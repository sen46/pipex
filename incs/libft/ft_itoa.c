/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:24:10 by ssawa             #+#    #+#             */
/*   Updated: 2025/04/26 15:36:44 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_digit(long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		cnt++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	*res;
	int		idx;

	num = n;
	len = cnt_digit(num);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	if (num == 0)
		res[0] = '0';
	idx = len - 1;
	while (num > 0)
	{
		res[idx--] = '0' + (num % 10);
		num /= 10;
	}
	return (res);
}
