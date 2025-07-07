/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path_from_envp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:11:38 by ssawa             #+#    #+#             */
/*   Updated: 2025/07/07 18:43:30 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static char **split_path(char *envp)
{
	return (ft_split(envp, ':'));
}

char	**find_path_from_envp(char **envp)
{
	int	i;
	int	len;
	char	**res;

	i = 0;
	len = ft_strlen("PATH=");
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", len))
		{
			res = split_path(envp[i] + 5);
			if (res)
				return (res);
		}
		i++;
	}
	return (NULL);
}

