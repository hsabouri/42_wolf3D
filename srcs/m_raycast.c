/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_raycast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:39:50 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/12 12:12:32 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_raycast	ray_init(t_env *env, int i)
{
	t_raycast ray;

	ray.angle = env->player.angle - (M_PI * env->player.fov / 2) +
		(M_PI * env->player.fov / env->width) * i;
	ray.ux = cos(ray.angle);
	ray.uy = sin(ray.angle);
	ray.map_x = (int)env->player.x;
	ray.map_y = (int)env->player.y;
	ray.delta_x = sqrt(1 + (ray.uy * ray.uy) / (ray.ux * ray.ux));
	ray.delta_y = sqrt(1 + (ray.ux * ray.ux) / (ray.uy * ray.uy));
	ray.side_x = ((ray.ux < 0) ? (env->player.x - ray.map_x) * ray.delta_x :
		(ray.map_x + 1 - env->player.x) * ray.delta_x);
	ray.side_y = ((ray.uy < 0) ? (env->player.y - ray.map_y) * ray.delta_y :
		(ray.map_y + 1 - env->player.y) * ray.delta_y);
	ray.step_x = ((ray.ux < 0) ? -1 : 1);
	ray.step_y = ((ray.uy < 0) ? -1 : 1);
	return (ray);
}

t_raycast	m_orientation(t_env *env, t_raycast ray)
{
	if (env->player.x > ray.map_x && ray.side == 0)
	{
		ray.color = env->map.east;
		ray.next_x = ray.map_x + 1;
		ray.next_y = ray.map_y;
	}
	else if (env->player.x < ray.map_x && ray.side == 0)
	{
		ray.color = env->map.west;
		ray.next_x = ray.map_x - 1;
		ray.next_y = ray.map_y;
	}
	else if (env->player.y < ray.map_y && ray.side == 1)
	{
		ray.color = env->map.north;
		ray.next_x = ray.map_x;
		ray.next_y = ray.map_y - 1;
	}
	else
	{
		ray.color = env->map.south;
		ray.next_x = ray.map_x;
		ray.next_y = ray.map_y + 1;
	}
	return (ray);
}

t_raycast	m_raytrace(t_env *env, t_raycast ray)
{
	int i;

	i = 0;
	while (i < env->map.fog_dis * 1.5)
	{
		if (ray.side_x < ray.side_y)
		{
			ray.side_x += ray.delta_x;
			ray.map_x += ray.step_x;
			ray.side = 0;
		}
		else
		{
			ray.side_y += ray.delta_y;
			ray.map_y += ray.step_y;
			ray.side = 1;
		}
		if (ray.map_x < 0 || ray.map_x >= env->map.width || ray.map_y < 0 ||
		ray.map_y >= env->map.width ||
		env->map.map[(ray.map_y * env->map.width) + ray.map_x] == '\1')
			break ;
		i++;
	}
	ray = m_orientation(env, ray);
	return (ray);
}
