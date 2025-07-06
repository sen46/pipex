/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:37:50 by ssawa             #+#    #+#             */
/*   Updated: 2025/04/25 17:49:32 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*pos;

	pos = NULL;
	while (*str)
	{
		if (*str == (unsigned char)c)
			pos = (char *)str;
		str++;
	}
	if (c == '\0')
		pos = (char *)str;
	return (pos);
}
