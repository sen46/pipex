/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:20:32 by ssawa             #+#    #+#             */
/*   Updated: 2025/07/08 14:31:08 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "struct.h"

static char ***command_alloc(int argc, char **argv);
static int **pipes_alloc(int argc);

// PATH変数の中身を初期化する
// 後で使うpipe()を動的にメモリを確保
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
		pipex->cmd_args = command_alloc(argc, argv);
		pipex->pipes = pipes_alloc(argc);
	}
	else if (pipex->type == HERE_DOC)
	{
		// 後で作成
	}
	return (0);
}

static int **pipes_alloc(int argc)
{
	int	cmd_count;
	int	**pipes;
	int	i;

	cmd_count = argc - 3;
	pipes = ft_calloc(cmd_count, sizeof(int *));
	if (pipes == NULL)
	{
		exit(1);
	}
	i = 0;
	while (i < cmd_count)
	{
		pipes[i] = ft_calloc(2, sizeof(int));
		if (pipes[i++] == NULL)
		{
			free_pipes(pipes);
			exit(1);
		}
		pipes[i][0] = -1;
		pipes[i][1] = -1;
	}
	return(pipes);
}

static char ***command_alloc(int argc, char **argv)
{
	char	***res;
	int		i;

	res = (char ***)ft_calloc(argc - 3, sizeof(char **));
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
