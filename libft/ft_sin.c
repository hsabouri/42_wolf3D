/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:13:24 by hsabouri          #+#    #+#             */
/*   Updated: 2016/11/08 14:35:43 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_sin(float x)
{
	float	n;
	float	m;
	float	result;

	n = 1;
	m = -1;
	result = x;
	while (n < 10)
	{
		result += m * (ft_power(x, (2 * n) + 1) / ft_factoriel((2 * n) + 1));
		m = (m == -1) ? 1 : -1;
		n++;
	}
	return (result);
}
