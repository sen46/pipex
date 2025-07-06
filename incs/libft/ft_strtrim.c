/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:08:13 by ssawa             #+#    #+#             */
/*   Updated: 2025/04/26 12:44:17 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	pre_set_cnt(const char *str, const char *set)
{
	int	cnt;
	int	len;
	int	idx;

	len = ft_strlen((char *)str);
	cnt = 0;
	idx = 0;
	while (idx < len && isset(str[idx], set))
	{
		cnt++;
		idx++;
	}
	return (cnt);
}

static int	suf_set_cnt(const char *str, const char *set)
{
	int	cnt;
	int	len;
	int	idx;

	len = ft_strlen((char *)str);
	cnt = 0;
	idx = len - 1;
	while (idx >= 0 && isset(str[idx], set))
	{
		cnt++;
		idx--;
	}
	if (cnt == len)
		return (0);
	else
		return (cnt);
}

char	*ft_strtrim(const char *str, const char *set)
{
	char	*res;
	int		pre_cnt;
	int		suf_cnt;
	int		len;
	int		idx;

	if (str == NULL || set == NULL)
		return (NULL);
	len = ft_strlen((char *)str);
	pre_cnt = pre_set_cnt(str, set);
	suf_cnt = suf_set_cnt(str, set);
	res = (char *)malloc(sizeof(char) * (len - (pre_cnt + suf_cnt) + 1));
	if (res == NULL)
		return (NULL);
	idx = 0;
	while (idx + pre_cnt < len - suf_cnt)
	{
		res[idx] = str[idx + pre_cnt];
		idx++;
	}
	res[idx] = '\0';
	return (res);
}
