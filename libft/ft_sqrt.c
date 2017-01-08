/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:27:34 by hsabouri          #+#    #+#             */
/*   Updated: 2016/11/09 15:17:54 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	ft_sqrti(float n)
{
	int sqrt;

	sqrt = ((int)n % 2 == 0) ? 2 : 1;
	while (sqrt * sqrt < n)
		sqrt += 2;
	return (sqrt - 2);
}

float			ft_sqrt(float n)
{
	float	r;
	float	s;
	int		i;

	if (n <= 0)
		return (0);
	r = ft_sqrti(n);
	i = 0;
	while (i < 2)
	{
		s = (n - r * r) / (2 * r);
		r += (s - ((s * s) / (2 * (r + s))));
		i++;
	}
	return (r);
}
