/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:59:06 by ssawa             #+#    #+#             */
/*   Updated: 2025/04/25 23:15:37 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	small_len;
	size_t	start;
	size_t	big_len;
	size_t	i;

	small_len = ft_strlen((char *)small);
	big_len = ft_strlen((char *)big);
	if (small_len == 0)
		return ((char *)big);
	start = 0;
	while (start < big_len && start + small_len <= len)
	{
		i = 0;
		while (small[i] && big[start + i] && big[start + i] == small[i])
		{
			i++;
			if (i == small_len)
				return ((char *)&big[start]);
		}
		start++;
	}
	return (NULL);
}
