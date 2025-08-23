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
#include <stdlib.h>

static void	path_check(const int i, int *j, t_pipex *pipex, int *flag)
{
	*flag = 1;
	*j = 0;
	while (pipex->paths[*j])
	{
		pipex->cmd_path[i] = ft_strjoin3(pipex->paths[*j], "/", \
										pipex->cmd_args[i][0]);
		if (!pipex->cmd_path[i])
			return ;
		if (!access(pipex->cmd_path[i], X_OK))
		{
			*flag = 0;
			break ;
		}
		else if (pipex->cmd_path[i])
		{
			free(pipex->cmd_path[i]);
			pipex->cmd_path[i] = NULL;
		}
		(*j)++;
	}
}

/*
void	get_cmd_path(t_pipex *pipex)
{
	int	i;
	int	j;
	int	flag;

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
		path_check(i++, &j, pipex, &flag);
		if (flag)
		{
			free_all(pipex);
			write(2, "command not found\n", 18);
			exit(EXIT_FAILURE);
		}
	}
}
*/

void	get_cmd_path(t_pipex *pipex)
{
	int	i;
	int	j;
	int	flag;

	pipex->cmd_path = ft_calloc(pipex->cmd_count + 1, sizeof(char *));
	if (!pipex->cmd_path)
		return ;
	i = 0;
	while (pipex->cmd_args[i])
	{
		path_check(i, &j, pipex, &flag);
		if (flag && !access(pipex->cmd_args[i][0], X_OK))
			pipex->cmd_path[i] = ft_strdup(pipex->cmd_args[i][0]);
		if (flag)
		{
			free_all(pipex);
			write(2, "ft command not found\n", 18);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
