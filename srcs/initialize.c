/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:20:32 by ssawa             #+#    #+#             */
/*   Updated: 2025/07/07 19:14:29 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "struct.h"

static char ***command_init(int argc, char **argv);

// PATH変数の中身を初期化する
int	initialize(int argc, char **argv, char **envp, t_pipex *pipex)
{
	if (pipex->type == PIPES)
	{
		pipex->paths = find_path_from_envp(envp);
		if (pipex->paths == NULL)
		{
			close(pipex->infile_fd);
			close(pipex->outfile_fd);
			write(2, "PATH Error\n", 11);
			exit(1);
		}
		pipex->cmd_args = command_init(argc, argv);
	}
	else if (pipex->type == HERE_DOC)
	{

	}
	return (0);
}

static char ***command_init(int argc, char **argv)
{
	char	***res;
	int		i;

	res = (char ***)ft_calloc(argc - 1, sizeof(char **));
	i = 0;
	while (i < argc - 3)
	{
		res[i] = ft_split(argv[i + 2], ' ');
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
