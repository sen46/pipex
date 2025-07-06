/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:43:53 by ssawa             #+#    #+#             */
/*   Updated: 2025/04/25 14:46:13 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*us;
	size_t			idx;

	us = (unsigned char *)s;
	idx = 0;
	while (idx < len)
	{
		us[idx] = '\0';
		idx++;
	}
}
