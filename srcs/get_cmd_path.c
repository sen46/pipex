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
#include "struct.h"
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

static void	print_cmd_not_found(t_pipex *pipex, int i, int *is_err)
{
	if (i == pipex->cmd_count - 1)
		*is_err = 127;
	else
		*is_err = 0;
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putstr_fd(pipex->cmd_args[i][0], 2);
	ft_putstr_fd("\n", 2);
	pipex->cmd_path[i] = ft_calloc(1, sizeof(char));
}

static void	exit_get_cmd_path(t_pipex *pipex, int status_code)
{
	pipex->status = status_code;
}

void	get_cmd_path(t_pipex *pipex)
{
	int	i;
	int	j;
	int	flag;
	int	status_code;

	pipex->cmd_path = ft_calloc(pipex->cmd_count + 1, sizeof(char *));
	if (!pipex->cmd_path)
		return ;
	i = -1;
	status_code = -1;
	while (pipex->cmd_args[++i])
	{
		flag = 1;
		if (pipex->paths)
			path_check(i, &j, pipex, &flag);
		if (flag == 1 && !access(pipex->cmd_args[i][0], X_OK))
		{
			pipex->cmd_path[i] = ft_strdup(pipex->cmd_args[i][0]);
			flag = 0;
		}
		if (flag == 1)
			print_cmd_not_found(pipex, i, &status_code);
	}
	if (status_code != -1)
		exit_get_cmd_path(pipex, status_code);
}
