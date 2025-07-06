/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssawa <ssawa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:45:15 by ssawa             #+#    #+#             */
/*   Updated: 2025/04/27 15:51:32 by ssawa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nxt;

	if (*lst && del)
	{
		while (*lst)
		{
			nxt = (*lst)->next;
			del((*lst)->content);
			free(*lst);
			*lst = nxt;
		}
	}
}
