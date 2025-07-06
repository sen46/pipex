/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:52:18 by ssawa             #+#    #+#             */
/*   Updated: 2025/04/26 13:35:22 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_cnt(const char *str, char c)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str != c)
		{
			cnt++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	return (cnt);
}

static char	*word_splitter(const char *str, char c)
{
	char	*res;
	int		cnt;
	int		idx;

	cnt = 0;
	while (*(str + cnt) && *(str + cnt) != c)
		cnt++;
	res = (char *)malloc(sizeof(char) * (cnt + 1));
	if (res == NULL)
		return (NULL);
	idx = 0;
	while (idx < cnt)
	{
		res[idx] = *(str + idx);
		idx++;
	}
	res[idx] = '\0';
	return (res);
}

static void	free_all(char **res, int n)
{
	while (n-- > 0)
		free(res[n]);
	free(res);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	int		idx;

	res = (char **)ft_calloc(word_cnt(str, c) + 1, sizeof(char *));
	if (res == NULL)
		return (NULL);
	idx = 0;
	while (*str)
	{
		if (*str != c)
		{
			res[idx] = word_splitter(str, c);
			if (!res[idx])
			{
				free_all(res, idx);
				return (NULL);
			}
			idx++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	return (res);
}
