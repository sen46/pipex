/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:34:32 by ssawa             #+#    #+#             */
/*   Updated: 2025/07/08 16:36:30 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*ft_strjoin3(char *str1, char *str2, char *str3)
{
	char	*dst;
	char	*res;

	dst = ft_strjoin(str1, str2);
	res = ft_strjoin(dst, str3);
	free(dst);
	return (res);
}
