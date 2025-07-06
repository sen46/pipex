/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:29:04 by ssawa             #+#    #+#             */
/*   Updated: 2025/04/25 22:34:42 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int c, size_t count)
{
	void	*pos;
	char	*str;

	pos = NULL;
	str = (char *)buf;
	while (count-- > 0)
	{
		if (*str == (unsigned char)c)
		{
			pos = str;
			break ;
		}
		str++;
	}
	return (pos);
}
