/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 22:35:57 by ssawa             #+#    #+#             */
/*   Updated: 2025/04/25 22:56:50 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	const unsigned char	*ub1;
	const unsigned char	*ub2;

	ub1 = (const unsigned char *)buf1;
	ub2 = (const unsigned char *)buf2;
	while (count-- > 0)
	{
		if (*ub1 != *ub2)
			return (*ub1 - *ub2);
		ub1++;
		ub2++;
	}
	return (0);
}
