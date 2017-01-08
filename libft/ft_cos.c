/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:13:24 by hsabouri          #+#    #+#             */
/*   Updated: 2016/11/09 15:28:09 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_cos(float x)
{
	float	n;
	float	m;
	float	result;

	n = 1;
	m = -1;
	result = 1;
	while (n < 10)
	{
		result += m * (ft_power(x, 2 * n) / ft_factoriel(2 * n));
		m = (m == -1) ? 1 : -1;
		n++;
	}
	return (result);
}
