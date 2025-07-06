/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:24:27 by ssawa             #+#    #+#             */
/*   Updated: 2025/04/26 11:46:02 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*res;
	size_t	mx_len;

	mx_len = ft_strlen((char *)str);
	if (start >= mx_len)
		return (ft_strdup(""));
	if (start + len >= mx_len)
		len = mx_len - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	while (len-- > 0)
		res[len] = str[start + len];
	return (res);
}
