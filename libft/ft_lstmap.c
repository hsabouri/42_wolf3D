/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 21:20:39 by hsabouri          #+#    #+#             */
/*   Updated: 2016/11/07 22:03:30 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstmapmaker(t_list *lst, t_list *dst,
		t_list *(*f)(t_list *elem))
{
	if (lst)
	{
		dst = (*f)(lst);
		dst->next = ft_lstmapmaker(lst->next, dst->next, f);
	}
	else
		dst = NULL;
	return (dst);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*dst;

	dst = NULL;
	return (ft_lstmapmaker(lst, dst, f));
}
