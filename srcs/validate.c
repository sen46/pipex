/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:55:35 by ssawa             #+#    #+#             */
/*   Updated: 2025/07/07 18:39:54 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "struct.h"
#include <fcntl.h>
#include <stdio.h>

int	valid(int ac, char **av, t_pipex *pipex)
{
	if (!ft_strcmp(av[1], "here_doc"))
	{
		pipex->type = HERE_DOC;
		// Bonus 課題のため後で作成
		if (ac != 6)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	else
	{
		pipex->type = PIPES;
		if (ac <= 4)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		pipex->infile_fd = open(av[1], O_RDONLY);
		if (pipex->infile_fd == -1)
		{
			perror(av[1]);
			exit(1);
		}
		pipex->outfile_fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (pipex->outfile_fd == -1)
		{
			perror(av[ac - 1]);
			close(pipex->infile_fd);
			exit(1);
		}
	}
	return (0);
}
