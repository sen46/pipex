/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:43:36 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/01 23:00:30 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "pipex.h"

void	free_char_deg2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i++] = NULL;
	}
	free(str);
	str = NULL;
}

void	free_char_deg3(char ***str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free_char_deg2(str[i++]);
	}
	free(str);
	str = NULL;
}

void	free_pipes(int **pipes)
{
	int	i;

	i = 0;
	while (pipes[i])
	{
		free(pipes[i]);
		pipes[i++] = NULL;
	}
	free(pipes);
	pipes = NULL;
}

void	free_all(t_pipex *pipex)
{
	free_char_deg3(pipex->cmd_args);
	free_char_deg2(pipex->cmd_path);
	free_char_deg2(pipex->paths);
	if (!access("tmp", F_OK))
	{
		unlink("tmp");
	}
}
