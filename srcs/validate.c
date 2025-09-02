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
	pipex->infile_fd = open("ft_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->infile_fd == -1)
	{
		perror("ft_tmp");
		exit(EXIT_FAILURE);
	}
	pipex->outfile_fd = open(argv[argc - 1], \
			O_WRONLY | O_CREAT | O_APPEND, 0644);
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
		ft_putstr_fd("ft argument Error\n", 2);
		exit(EXIT_FAILURE);
	}
	pipex->infile_fd = open(argv[1], O_RDONLY);
	pipex->outfile_fd = open(argv[argc - 1], \
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->infile_fd == -1)
	{
		pipex->infile_fd = open("ft_tmp_infile", \
				O_RDONLY | O_CREAT | O_TRUNC, 0644);
		unlink("ft_tmp_infile");
		perror(argv[1]);
	}
	if (pipex->outfile_fd == -1)
	{
		close(pipex->infile_fd);
		perror(argv[argc - 1]);
		pipex->status = 1;
		pipex->outfile_fd = open("ft_tmp", \
				O_RDWR | O_CREAT | O_TRUNC, 0644);
		// exit(EXIT_FAILURE);
	}
}

int	str_is_empty(int argc, char **argv)
{
	int	flag;
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		flag = 1;
		while (argv[i][j])
		{
			if (!ft_isspace(argv[i][j]))
				flag = 0;
			j++;
		}
		if (flag)
			return (1);
		i++;
	}
	return (0);
}

int	valid(int argc, char **argv, t_pipex *pipex)
{
	if (argc < 2)
		return (1);
	if (str_is_empty(argc, argv))
	{
		ft_putstr_fd("ft arguments Error\n", 2);
		exit(EXIT_FAILURE);
	}
	if (!ft_strcmp(argv[1], "here_doc"))
		valid_heredoc(argc, argv, pipex);
	else
		valid_pipes(argc, argv, pipex);
	return (0);
}
