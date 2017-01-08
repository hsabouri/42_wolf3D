/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgoto.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:27:41 by hsabouri          #+#    #+#             */
/*   Updated: 2016/11/16 12:33:23 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstgoto(t_list **alst, int i)
{
	int		j;
	t_list	*ptr;

	j = 0;
	if (!*alst)
		return (NULL);
	ptr = (*alst);
	while (ptr->next && j < i)
	{
		ptr = ptr->next;
		j++;
	}
	return (ptr);
}
