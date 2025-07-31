/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:58:29 by ssawa             #+#    #+#             */
/*   Updated: 2025/07/08 16:39:47 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "struct.h"

/*
void	process(int argc, t_pipex *pipex)
{
	int		i;
	pid_t	pid;
	int		cmd_count;

	i = 0;
	cmd_count = argc - 3;
	while (i < cmd_count)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free_all(pipex);
			exit(1);
		}
		// 子プロセスの処理
		if (pid == 0)
		{
			// ★ 最初のコマンド
			if (i == 0)
			{
				dup2(pipex->infile_fd, 0);
				dup2(pipex->pipes[i][1], 1);
			}
			// ★ 最後のコマンド
			else if (i == cmd_count - 1)
			{
				dup2(pipex->pipes[i - 1][0], 0);
				dup2(pipex->outfile_fd, 1);
			}
			// ★ 中間のコマンド
			else
			{
				dup2(pipex->pipes[i - 1][0], 0);
				dup2(pipex->pipes[i][1], 1);
			}
			// 不要なfd全部閉じる
			close_all_pipes(cmd_count, pipex->pipes);
			// execve呼び出し
			exec_cmd(pipex, i);
		}
		i++;
	}

	// 親プロセスでパイプ全部閉じる
	close_all_pipes(cmd_count, pipex->pipes);
	// 子プロセス全部待つ
	wait_all(pid, cmd_count);
}
*/






#include "pipex.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

// 子プロセスで実行される処理
static void child_process(t_pipex *pipex, char **envp, int i, int prev_fd)
{
	int pipefd[2];

	// ★ 1. パイプを作成 (最後のコマンドでなければ)
	if (i < pipex->cmd_count - 1)
	{
		if (pipe(pipefd) == -1)
		{
			perror("pipe");
			// free_and_exit(pipex);
			exit(1);
		}
	}

	// ★ 2. 入出力を設定 (dup2)
	// 入力元を前のFDに設定
	dup2(prev_fd, STDIN_FILENO);
	close(prev_fd);

	// 出力先を設定 (最後のコマンドか否かで分岐)
	if (i == pipex->cmd_count - 1)
		dup2(pipex->outfile_fd, STDOUT_FILENO);
	else
		dup2(pipefd[1], STDOUT_FILENO);
	close(pipex->outfile_fd);

	// ★ 3. 不要なFDを閉じる
	if (i < pipex->cmd_count - 1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
	}
	
	// ★ 4. コマンドを実行
	execve(pipex->cmd_path[i], pipex->cmd_args[i], envp);
	perror("execve");
	// free_and_exit(pipex);
	exit(127);
}


// 親プロセスで実行されるメインの処理
void	execute_commands(t_pipex *pipex, char **envp)
{
	int		i;
	pid_t	pid;
	int		status;
	int		prev_fd;

	// 最初の入力元は infile
	prev_fd = pipex->infile_fd;
	i = 0;
	while (i < pipex->cmd_count)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			// free_and_exit(pipex);
			exit(1);
		}
		if (pid == 0) // 子プロセス
			child_process(pipex, envp, i, prev_fd);

		// 親プロセスは子の終了を待つ
		waitpid(pid, &status, 0);

		i++;
	}
	// すべての処理が終わったので、最後のFDを閉じる
	close(prev_fd);
}
