/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:03:35 by ssawa             #+#    #+#             */
/*   Updated: 2025/04/25 16:41:01 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	idx;
	size_t	mx_copy;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	else
	{
		mx_copy = dstsize - dst_len - 1;
		idx = 0;
		while (idx < mx_copy && src[idx])
		{
			dst[dst_len + idx] = src[idx];
			idx++;
		}
		dst[dst_len + idx] = '\0';
		return (dst_len + src_len);
	}
}
