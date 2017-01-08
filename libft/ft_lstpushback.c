/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:58:24 by hsabouri          #+#    #+#             */
/*   Updated: 2016/11/16 12:18:41 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list *ptr;

	ptr = *alst;
	while (ptr && ptr->next)
	{
		ptr = ptr->next;
	}
	if (ptr && new)
		ptr->next = new;
	else if (new)
		(*alst) = new;
}
