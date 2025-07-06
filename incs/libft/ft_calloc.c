/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 08:20:58 by ssawa             #+#    #+#             */
/*   Updated: 2025/04/26 16:23:47 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*mlc;

	if (number && size && number > SIZE_MAX / size)
		return (NULL);
	mlc = (void *)malloc(number * size);
	if (mlc == NULL)
		return (NULL);
	ft_memset(mlc, 0, size * number);
	return (mlc);
}
