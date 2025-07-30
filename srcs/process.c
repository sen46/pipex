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
