/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:55:35 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/01 23:00:14 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include "struct.h"
#include <fcntl.h>
#include <stdlib.h>

void	valid_heredoc(int argc, char **argv, t_pipex *pipex)
{
	pipex->type = HERE_DOC;
	if (argc < 6)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	pipex->infile_fd = open("tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->infile_fd == -1)
	{
		perror("tmp");
		exit(EXIT_FAILURE);
	}
	pipex->outfile_fd = open(argv[argc - 1], \
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile_fd == -1)
	{
		perror(argv[argc - 1]);
		close(pipex->infile_fd);
		exit(EXIT_FAILURE);
	}
}

void	valid_pipes(int argc, char **argv, t_pipex *pipex)
{
	pipex->type = PIPES;
	if (argc < 5)
	{
		ft_putstr_fd("argument Error\n", 2);
		exit(EXIT_FAILURE);
	}
	pipex->infile_fd = open(argv[1], O_RDONLY);
	if (pipex->infile_fd == -1)
	{
		perror(argv[1]);
		exit(EXIT_FAILURE);
	}
	pipex->outfile_fd = open(argv[argc - 1], \
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile_fd == -1)
	{
		perror(argv[argc - 1]);
		close(pipex->infile_fd);
		exit(EXIT_FAILURE);
	}
}

int	valid(int argc, char **argv, t_pipex *pipex)
{
	if (!ft_strcmp(argv[1], "here_doc"))
		valid_heredoc(argc, argv, pipex);
	else
		valid_pipes(argc, argv, pipex);
	return (0);
}
