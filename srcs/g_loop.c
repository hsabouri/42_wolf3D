/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_loop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:14:52 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/08 17:47:59 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_image	g_raytrace(t_env env, int col, double distance)
{
	int i;
	int	height;

	i = 0;
	height = (double)(200 / distance);
	while (i < env.height)
	{
		if (i < env.height / 2 - height / 2)
			env.screen = g_pixel_put(env.screen, col, i, env.map.sky);
		else if (i < env.height / 2 + height / 2 )
			env.screen = g_pixel_put(env.screen, col, i, env.map.west);
		else
			env.screen = g_pixel_put(env.screen, col, i, env.map.floor);
		i++;
	}
	return (env.screen);
}

int		g_loop(t_env *env)
{
	double	init_x;
	double	init_y;
	double	delta_x;
	double	delta_y;
	double	angle;
	double	rx;
	double	ry;
	double	dist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		i;

	keyboard(env);
	i = 0;
	angle = env->player.angle - (env->player.fov * M_PI) / 2;
	while (i < env->width)
	{
		rx = cos(angle);
		ry = sin(angle);
		map_x = (int)env->player.x;
		map_y = (int)env->player.y;
		delta_x = sqrt(1 + (ry * ry) / (rx * rx));
		delta_y = sqrt(1 + (rx * rx) / (ry * ry));
		init_x = (rx < 0) ? (env->player.x - map_x) * delta_x : 
			map_x + 1.0 - env->player.x;
		init_y = (ry < 0) ? (env->player.y - map_y) * delta_y : 
			map_y + 1.0 - env->player.y;
		step_x = (rx < 0) ? -1 : 1;
		step_y = (ry < 0) ? -1 : 1;
		angle += env->player.fov / env->width * M_PI;
		while (1)
		{
			if (init_x < init_y)
			{
				init_x += delta_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				init_y += delta_y;
				map_y += step_y;
				side = 1;
			}
			if (map_x >= 0 && map_x < env->map.width && map_y >= 0 && map_y < env->map.width)
			{
				if (env->map.map[(env->map.width * map_y) + map_x] == '\1')
					break;
			}
			else
				break;
		}
		if (!side)
			dist = ((map_x - env->player.x + (1 - step_x) / 2) / rx);
		else
			dist = ((map_y - env->player.y + (1 - step_y) / 2) / ry);
		env->screen = g_raytrace(*env, i, dist);
		i++;
	}
	g_refresh_win(env->screen, *env);
	return (0);
}
