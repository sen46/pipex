/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 11:58:29 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/01 22:54:11 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "struct.h"
#include <unistd.h>

static void	free_for_child(t_pipex *pipex)
{
	free_char_deg3(pipex->cmd_args);
	free_char_deg2(pipex->cmd_path);
	free_char_deg2(pipex->paths);
}

static void	run_child_process(t_pipex *pipex, int i, char **envp, t_fd *fd)
{
	dup2(fd->prev, STDIN_FILENO);
	if (i == pipex->cmd_count - 1)
		dup2(pipex->outfile_fd, STDOUT_FILENO);
	else
		dup2(fd->pipe[1], STDOUT_FILENO);
	if (i < pipex->cmd_count - 1)
	{
		close(fd->pipe[0]);
		close(fd->pipe[1]);
	}
	close(fd->prev);
	close(pipex->outfile_fd);
	execve(pipex->cmd_path[i], pipex->cmd_args[i], envp);
	perror("execve");
	free_for_child(pipex);
	exit(127);
}

static void	execute_command_step(t_pipex *pipex, char **envp, t_fd *fd, int i)
{
	pid_t	pid;

	if (i < pipex->cmd_count - 1 && pipe(fd->pipe) == -1)
	{
		free_all(pipex);
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		free_all(pipex);
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
		run_child_process(pipex, i, envp, fd);
	if (i == pipex->cmd_count - 1)
		fd->last_pid = pid;

	close(fd->prev);
	if (i < pipex->cmd_count - 1)
	{
		close(fd->pipe[1]);
		fd->prev = fd->pipe[0];
	}
}

/*
void	execute_commands(t_pipex *pipex, char **envp)
{
	t_fd	fd;
	int		i;
	int		status;
	pid_t	terminated_pid;

	i = 0;
	fd.prev = pipex->infile_fd;
	while (i < pipex->cmd_count)
	{
		if (pipex->cmd_path[0][0])
			execute_command_step(pipex, envp, &fd, i);
		i++;
	}
	i = 0;
	while (i < pipex->cmd_count)
	{
		terminated_pid = wait(&status);
		if (terminated_pid == fd.last_pid)
		{
			// if (pipex->status == 1 || pipex->status == 127 || git.status == 0)
			if (pipex->status == 1 || pipex->status == 127)
			// if (pipex->status == 1)
				continue ;
			if (WIFEXITED(status))
				pipex->status = WEXITSTATUS(status);
		}
		i++;
	}
}
*/

void	execute_commands(t_pipex *pipex, char **envp)
{
	t_fd	fd;
	int		i;
	int		status;
	pid_t	terminated_pid;

	i = 0;
	fd.prev = pipex->infile_fd;
	fd.last_pid = 0;
	while (i < pipex->cmd_count)
	{
		execute_command_step(pipex, envp, &fd, i);
		i++;
	}
	i = 0;
	while (i < pipex->cmd_count)
	{
		terminated_pid = wait(&status);
		if (terminated_pid == fd.last_pid)
		{
			if (pipex->status == 1 || pipex->status == 127)
				continue ;
			if (WIFEXITED(status))
				pipex->status = WEXITSTATUS(status);
		}
		i++;
	}
}
