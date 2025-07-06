/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 16:00:36 by ssawa             #+#    #+#             */
/*   Updated: 2025/04/26 16:48:02 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	len;
	unsigned int	idx;

	if (str == NULL || (*f) == NULL)
		return (NULL);
	len = ft_strlen((char *)str);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	idx = 0;
	while (idx < len)
	{
		res[idx] = f(idx, str[idx]);
		idx++;
	}
	return (res);
}
