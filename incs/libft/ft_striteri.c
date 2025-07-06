/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:43:02 by ssawa             #+#    #+#             */
/*   Updated: 2025/04/26 16:48:59 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	idx;
	unsigned int	len;

	if (s != NULL && f != NULL)
	{
		idx = 0;
		len = ft_strlen(s);
		while (idx < len)
		{
			(*f)(idx, &s[idx]);
			idx++;
		}
	}
}
