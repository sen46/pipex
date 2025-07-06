/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:02:37 by ssawa             #+#    #+#             */
/*   Updated: 2025/04/25 15:08:15 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ud;
	unsigned char	*us;

	if (dest == NULL && src == NULL)
		return (NULL);
	ud = (unsigned char *)dest;
	us = (unsigned char *)src;
	while (n-- > 0)
	{
		*ud = *us;
		ud++;
		us++;
	}
	return (dest);
}
