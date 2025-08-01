/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:20:32 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/01 22:52:59 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include "struct.h"
#include <fcntl.h>

static char	***command_alloc(int argc, char **argv, int type);
static void	type_pipes(int argc, char **argv, t_pipex *pipex, char **envp);
static void	type_heredoc(int argc, char **argv, t_pipex *pipex, char **envp);

int	initialize(int argc, char **argv, char **envp, t_pipex *pipex)
{
	if (pipex->type == PIPES)
	{
		type_pipes(argc, argv, pipex, envp);
	}
	else if (pipex->type == HERE_DOC)
	{
		type_heredoc(argc, argv, pipex, envp);
	}
	return (0);
}

static void	type_pipes(int argc, char **argv, t_pipex *pipex, char **envp)
{
	pipex->paths = find_path_from_envp(envp);
	if (pipex->paths == NULL)
	{
		close(pipex->infile_fd);
		close(pipex->outfile_fd);
		write(2, "PATH Error\n", 11);
		exit(1);
	}
	pipex->cmd_count = argc - 2 - pipex->type;
	pipex->cmd_args = command_alloc(pipex->cmd_count, argv, pipex->type);
	get_cmd_path(pipex);
}

static char ***command_alloc(int cmd_count, char **argv, int type)
{
	char	***res;
	int		i;

	res = (char ***)ft_calloc(cmd_count + 1, sizeof(char **));
	i = 0;
	while (i < cmd_count)
	{
		res[i] = ft_split(argv[i + type + 1], ' ');
		if (res[i] == NULL)
		{
			free_char_deg3(res);
			write(2, "memory allocated Error\n", 23);
			exit(1);
		}
		i++;
	}
	return (res);
}

static void	type_heredoc(int argc, char **argv, t_pipex *pipex, char **envp)
{
	char	*str;
	char	*eof;

	eof = ft_strjoin(argv[2], "\n");
	while (1)
	{
		write(1, "pipe heredoc >", 14);
		str = get_next_line(0);
		if (!ft_strcmp(str, eof))
		{
			break ;
		}
		else
		{
			ft_putstr_fd(str, pipex->infile_fd);
		}
	}
	free(eof);
	close(pipex->infile_fd);
	pipex->infile_fd = open("tmp", O_RDONLY);
	type_pipes(argc, argv, pipex, envp);
}
