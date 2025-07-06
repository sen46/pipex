/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:09:15 by ssawa             #+#    #+#             */
/*   Updated: 2025/04/25 16:23:19 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	size_t			idx;
	unsigned char	*ud;
	unsigned char	*us;

	ud = (unsigned char *)dest;
	us = (unsigned char *)src;
	if (src > dest)
	{
		idx = 0;
		while (idx < count)
		{
			ud[idx] = us[idx];
			idx++;
		}
	}
	else if (src < dest)
	{
		idx = count;
		while (idx-- > 0)
			ud[idx] = us[idx];
	}
	return (dest);
}
