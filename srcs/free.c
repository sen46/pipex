/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:43:36 by ssawa             #+#    #+#             */
/*   Updated: 2025/07/07 19:10:56 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_char_deg2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
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
}

