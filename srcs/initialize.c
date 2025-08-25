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

#include "libft/get_next_line.h"
#include "libft/libft.h"
#include "pipex.h"
#include "struct.h"
#include <stdlib.h>

static char	***command_alloc(int argc, char **argv, int type);
static void	type_pipes(int argc, char **argv, t_pipex *pipex, char **envp);
static void	type_heredoc(int argc, char **argv, t_pipex *pipex, char **envp);

int	initialize(int argc, char **argv, char **envp, t_pipex *pipex)
{
	pipex->paths = NULL;
	pipex->cmd_args = NULL;
	pipex->cmd_path = NULL;
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
	if (!pipex->paths)
	{
		ft_putstr_fd("ft memory allocated Error\n", 2);
		free_all(pipex);
		exit(EXIT_FAILURE);
	}
	pipex->cmd_count = argc - 2 - pipex->type;
	pipex->cmd_args = command_alloc(pipex->cmd_count, argv, pipex->type);
	if (!pipex->cmd_args)
	{
		ft_putstr_fd("ft memory allocated Error\n", 2);
		free_all(pipex);
		exit(EXIT_FAILURE);
	}
	get_cmd_path(pipex);
}

static void	type_heredoc(int argc, char **argv, t_pipex *pipex, char **envp)
{
	char	*str;
	char	*eof;

	eof = ft_strjoin(argv[2], "\n");
	while (1)
	{
		write(1, "pipe heredoc>", 13);
		str = get_next_line(0);
		if (!str)
		{
			free_all(pipex);
			exit(EXIT_FAILURE);
		}
		if (!ft_strcmp(str, eof))
			break ;
		else
			ft_putstr_fd(str, pipex->infile_fd);
		free_str(str);
	}
	// get_next_line(-1);
	free_str(str);
	free_str(eof);
	close(pipex->infile_fd);
	pipex->infile_fd = open("ft_tmp", O_RDONLY);
	type_pipes(argc, argv, pipex, envp);
}

static char	***command_alloc(int cmd_count, char **argv, int type)
{
	char	***res;
	int		i;

	res = (char ***)ft_calloc(cmd_count + 1, sizeof(char **));
	if (!res)
		return (NULL);
	i = 0;
	while (i < cmd_count)
	{
		res[i] = ft_split(argv[i + type + 1], ' ');
		if (!res[i])
		{
			free_char_deg3(res);
			write(2, "ft memory allocated Error\n", 23);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (res);
}
