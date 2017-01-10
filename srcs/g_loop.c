/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_loop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:14:52 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/10 18:08:57 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_color		g_col_dis(t_env env, t_color color, double dis)
{
	double ir;
	double ig;
	double ib;

	ir = (env.map.fog.red - color.red) / env.map.fog_dis;
	ig = (env.map.fog.green - color.green) / env.map.fog_dis;
	ib = (env.map.fog.blue - color.blue) / env.map.fog_dis;
	color.red += (dis < env.map.fog_dis) ? ir * dis : ir * env.map.fog_dis;
	color.green += (dis < env.map.fog_dis) ? ig * dis : ig * env.map.fog_dis;
	color.blue += (dis < env.map.fog_dis) ? ib * dis : ib * env.map.fog_dis;
	return (color);
}

t_image		g_draw(t_env env, int col, t_raycast ray)
{
	int		i;
	int		h;
	double	realdis;

	i = 0;
	realdis = (ray.dis * cos(env.player.angle - ray.angle));
	h = (env.height * 1.40 / realdis);
	while (i < env.height)
	{
		if (i < env.height / 2 - h / 2)
			env.screen = g_pixel_put(env.screen, col, i, env.map.sky);
		else if (i < env.height / 2 + h / 2 )
			env.screen = g_pixel_put(env.screen, col, i,\
			g_col_dis(env, ray.color, realdis));
		else
			env.screen = g_pixel_put(env.screen, col, i, env.map.sky);
		i++;
	}
	return (env.screen);
}

t_raycast	g_raytrace(t_env env, t_raycast ray)
{
	while (1)
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
		if (ray.map_x < 0 || ray.map_x >= env.map.width || ray.map_y < 0 ||
		ray.map_y >= env.map.width ||
		env.map.map[(ray.map_y * env.map.width) + ray.map_x] == '\1')
			break;
	}
	if (env.player.x > ray.map_x && ray.side == 0)
		ray.color = env.map.east;
	else if (env.player.x < ray.map_x && ray.side == 0)
		ray.color = env.map.west;
	else if (env.player.y < ray.map_y && ray.side == 1)
		ray.color = env.map.north;
	else
		ray.color = env.map.south;
	return (ray);
}

int			g_loop(t_env *env)
{
	int			i;
	t_raycast	ray;

	i = 0;
	keyboard(env);
	while (i < env->width)
	{
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
		ray = g_raytrace(*env, ray);
		ray.dis = (ray.side == 0) ?
			abs_d((ray.map_x - env->player.x + (1 - ray.step_x) / 2) / ray.ux) :
			abs_d((ray.map_y - env->player.y + (1 - ray.step_y) / 2) / ray.uy);
		env->screen = g_draw(*env, i, ray);
		i++;
	}
	g_refresh_win(env->screen, *env);
	return (0);
}
