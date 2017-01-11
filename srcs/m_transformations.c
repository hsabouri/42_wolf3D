/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_transformations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 12:06:24 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/11 15:16:31 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_player	m_left(t_env env, t_player player)
{
	double x;
	double y;

	x = cos(player.angle - M_PI / 2) / 10;
	y = sin(player.angle - M_PI / 2) / 10;
	if (player.x + x >= 0 && player.x + x < env.map.width)
	{
		if (env.map.map[(int)(player.y) * env.map.width +
		(int)(player.x + x)] != '\1')
			player.x += x;
	}
	if (player.y + y >= 0 && player.y + y < env.map.height)
	{
		if (env.map.map[(int)(player.y + y) * env.map.width +
		(int)(player.x)] != '\1')
			player.y += y;
	}
	return (player);
}

t_player	m_right(t_env env, t_player player)
{
	double x;
	double y;

	x = cos(player.angle - M_PI / 2) / 10;
	y = sin(player.angle - M_PI / 2) / 10;
	if (player.x - x >= 0 && player.x - x < env.map.width)
	{
		if (env.map.map[(int)(player.y) * env.map.width +
		(int)(player.x - x)] != '\1')
			player.x -= x;
	}
	if (player.y - y >= 0 && player.y - y < env.map.height)
	{
		if (env.map.map[(int)(player.y - y) * env.map.width +
		(int)(player.x)] != '\1')
			player.y -= y;
	}
	return (player);
}

t_player	m_forward(t_env env, t_player player)
{
	double x;
	double y;

	x = cos(player.angle) / 10;
	y = sin(player.angle) / 10;
	if (player.x + x >= 0 && player.x + x < env.map.width)
	{
		if (env.map.map[(int)(player.y) * env.map.width +
		(int)(player.x + x)] != '\1')
			player.x += x;
	}
	if (player.y + y >= 0 && player.y + y < env.map.height)
	{
		if (env.map.map[(int)(player.y + y) * env.map.width +
		(int)(player.x)] != '\1')
			player.y += y;
	}
	return (player);
}

t_player	m_backward(t_env env, t_player player)
{
	double x;
	double y;

	x = cos(player.angle) / 10;
	y = sin(player.angle) / 10;
	if (player.x - x >= 0 && player.x - x < env.map.width)
	{
		if (env.map.map[(int)(player.y) * env.map.width +
		(int)(player.x - x)] != '\1')
			player.x -= x;
	}
	if (player.y - y >= 0 && player.y - y < env.map.height)
	{
		if (env.map.map[(int)(player.y - y) * env.map.width +
		(int)(player.x)] != '\1')
			player.y -= y;
	}
	return (player);
}

t_player	m_rotate(t_player player, double angle)
{
	player.angle += angle;
	return (player);
}
