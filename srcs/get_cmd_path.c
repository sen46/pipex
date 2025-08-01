/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:19:06 by ssawa             #+#    #+#             */
/*   Updated: 2025/08/01 22:51:54 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

void	get_cmd_path(t_pipex *pipex)
{
	int	i;
	int	j;

	pipex->cmd_path = ft_calloc(pipex->cmd_count + 1, sizeof(char *));
	if (!pipex->cmd_path)
		return ;
	i = 0;
	while (pipex->cmd_args[i])
	{
		j = 0;
		if (!access(pipex->cmd_args[i][0], X_OK))
		{
			pipex->cmd_path[i] = ft_strdup(pipex->cmd_args[i][0]);
			i++;
			continue ;
		}
		while (pipex->paths[j])
		{
			pipex->cmd_path[i] = ft_strjoin3(pipex->paths[j], "/", pipex->cmd_args[i][0]);
			if (!pipex->cmd_path[i])
				return ;
			if (!access(pipex->cmd_path[i], X_OK))
				break;
			else if (pipex->cmd_path[i])
			{
				free(pipex->cmd_path[i]);
				pipex->cmd_path[i] = NULL;
			}
			j++;
		}
		i++;
	}
}
