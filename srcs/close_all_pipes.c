/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_all_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:31:31 by ssawa             #+#    #+#             */
/*   Updated: 2025/07/08 14:33:02 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_all_pipes(int cmd_count, int **pipes)
{
	int	i;

	i = 0;
	while (i < cmd_count)
	{
		if (pipes[i][0] != -1)
		{
			close(pipes[i][0]);
			pipes[i][0] = -1;
		}
		if (pipes[i][1] != -1)
		{
			close(pipes[i][1]);
			pipes[i][1] = -1;
		}
		i++;
	}
}
