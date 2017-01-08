/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:32:14 by hsabouri          #+#    #+#             */
/*   Updated: 2016/11/08 11:13:11 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	ft_positive_power(float a, int b)
{
	if (b == 0)
		return (1);
	else
		return (a * ft_positive_power(a, (b < 0) ? b + 1 : b - 1));
}

static float	ft_negative_power(float a, int b)
{
	return (1 / ft_positive_power(a, b));
}

float			ft_power(float a, int b)
{
	if (b == 0 && a == 0)
		return (0);
	if (b == 0)
		return (1);
	if (b < 0)
		return (ft_negative_power(a, b));
	return (ft_positive_power(a, b));
}
