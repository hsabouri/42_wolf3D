/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newcomplex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:21:32 by hsabouri          #+#    #+#             */
/*   Updated: 2016/11/09 15:40:11 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_complex	*ft_newcomplex(float a, float b)
{
	t_complex *c;

	if (!(c = (t_complex *)malloc(sizeof(t_complex))))
		return (NULL);
	c->a = a;
	c->b = b;
	return (c);
}
