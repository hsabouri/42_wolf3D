/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_mouse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 14:20:06 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/12 15:25:53 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	g_mouse(int x, int y, t_env *env)
{
	t_raycast	ray;
	int			i;

	i = 0;
	while (i < env->map.width * env->map.height)
	{
		if (env->map.map[i % env->map.width +\
		(i / env->map.height) * env->map.width] == '\3')
		{
			env->map.map[i % env->map.width +
			(i / env->map.height) * env->map.width] = '\1';
		}
		i++;
	}
	if (x < env->width && x >= 0 && y < env->height && y >= 0)
	{
		ray = ray_init(env, x);
		ray = m_raytrace(env, ray);
		if (ray.map_x >= 0 && ray.map_x < env->map.width && ray.map_y >= 0 &&\
		ray.map_y < env->map.height)
			env->map.map[ray.map_x + (ray.map_y * env->map.width)] = '\3';
	}
	return (0);
}

int	g_mouse_click(int button, int x, int y, t_env *env)
{
	t_raycast ray;

	if (button == 5)
		env->player.speed += (env->player.speed < 5) ? 0.1 : 0;
	if (button == 4)
		env->player.speed -= (env->player.speed > 0.2) ? 0.1 : 0;
	if ((button == 1 || button == 2) &&\
	x < env->width && x >= 0 && y < env->height && y >= 0)
	{
		ray = ray_init(env, x);
		ray = m_raytrace(env, ray);
		if (button == 1)
			if (ray.next_x >= 0 && ray.next_x < env->map.width &&\
			ray.next_y >= 0 && ray.next_y < env->map.height &&\
			(ray.next_x != (int)env->player.x ||\
			ray.next_y != (int)env->player.y))
				env->map.map[(ray.next_y * env->map.width) + ray.next_x] = '\1';
		if (button == 2)
			if (ray.map_x >= 0 && ray.map_x < env->map.width &&\
			ray.map_y >= 0 && ray.map_y < env->map.height)
				env->map.map[(ray.map_y * env->map.width) + ray.map_x] = '\0';
	}
	return (g_mouse(x, y, env));
}
