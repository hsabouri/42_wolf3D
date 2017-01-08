/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:17:34 by hsabouri          #+#    #+#             */
/*   Updated: 2016/11/08 17:01:24 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (new && *alst && alst)
	{
		new->next = *alst;
		*alst = new;
	}
	else if (alst && *alst)
		new = *alst;
	else if (new)
		*alst = new;
}
