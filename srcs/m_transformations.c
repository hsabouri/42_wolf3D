/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_transformations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 12:06:24 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/10 12:23:10 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_player	m_left(t_player player)
{
	player.x += cos(player.angle - M_PI / 2) / 10;
	player.y += sin(player.angle - M_PI / 2) / 10;
	return (player);
}

t_player	m_right(t_player player)
{
	player.x -= cos(player.angle - M_PI / 2) / 10;
	player.y -= sin(player.angle - M_PI / 2) / 10;
	return (player);
}

t_player	m_forward(t_player player)
{
	player.x += cos(player.angle) / 10;
	player.y += sin(player.angle) / 10;
	return (player);
}

t_player	m_backward(t_player player)
{
	player.x -= cos(player.angle) / 10;
	player.y -= sin(player.angle) / 10;
	return (player);
}

t_player	m_rotate(t_player player, double angle)
{
	player.angle += angle;
	return (player);
}
