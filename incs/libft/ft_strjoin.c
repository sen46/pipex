/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:39:46 by ssawa             #+#    #+#             */
/*   Updated: 2025/04/26 11:46:12 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	int		len_str1;
	int		len_str2;
	char	*res;

	len_str1 = ft_strlen((char *)str1);
	len_str2 = ft_strlen((char *)str2);
	res = (char *)malloc(sizeof(char) * (len_str1 + len_str2 + 1));
	if (res == NULL)
		return (NULL);
	res[len_str1 + len_str2] = '\0';
	while (len_str2-- > 0)
		res[len_str1 + len_str2] = str2[len_str2];
	while (len_str1-- > 0)
		res[len_str1] = str1[len_str1];
	return (res);
}
