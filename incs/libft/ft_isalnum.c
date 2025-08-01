/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:59:29 by ssawa             #+#    #+#             */
/*   Updated: 2025/07/05 17:19:54 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (ft_isdigit(c))
		return (1);
	else if (uc >= 'a' && uc <= 'z')
		return (1);
	else if (uc >= 'A' && uc <= 'Z')
		return (1);
	else
		return (0);
}
