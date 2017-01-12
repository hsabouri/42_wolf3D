/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_loop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:14:52 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/12 15:22:44 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_color		g_col_dis(t_env env, t_color color, double dis, t_raycast ray)
{
	float ir;
	float ig;
	float ib;

	if (env.map.map[ray.map_x + (ray.map_y * env.map.width)] == '\3')
	{
		color.red = 255;
		color.green = 100;
		color.blue = 100;
	}
	ir = (env.map.fog.red - color.red) / env.map.fog_dis;
	ig = (env.map.fog.green - color.green) / env.map.fog_dis;
	ib = (env.map.fog.blue - color.blue) / env.map.fog_dis;
	color.red += (dis < env.map.fog_dis) ? ir * dis : ir * env.map.fog_dis;
	color.green += (dis < env.map.fog_dis) ? ig * dis : ig * env.map.fog_dis;
	color.blue += (dis < env.map.fog_dis) ? ib * dis : ib * env.map.fog_dis;
	return (color);
}

t_color		g_grad_i(t_env env, t_color color, int i)
{
	float ir;
	float ig;
	float ib;
	float factor;

	ir = (float)(env.map.fog.red - color.red) * 2 / env.height;
	ig = (float)(env.map.fog.green - color.green) * 2 / env.height;
	ib = (float)(env.map.fog.blue - color.blue) * 2 / env.height;
	factor = ((i > env.map.fog_dis / 2) ? i - env.map.fog_dis / 2 : 0);
	color.red += ir * factor;
	color.green += ig * factor;
	color.blue += ib * factor;
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
			env.screen = g_pixel_put(env.screen, col, i,\
			g_grad_i(env, env.map.sky, i));
		else if (i < env.height / 2 + h / 2)
			env.screen = g_pixel_put(env.screen, col, i,\
			g_col_dis(env, ray.color, ray.dis, ray));
		else
			env.screen = g_pixel_put(env.screen, col, i,\
			g_grad_i(env, env.map.floor, abs_i(i - env.height)));
		i++;
	}
	return (env.screen);
}

int			g_loop(t_env *env)
{
	int			i;
	t_raycast	ray;

	i = 0;
	keyboard(env);
	while (i < env->width)
	{
		ray = ray_init(env, i);
		ray = m_raytrace(env, ray);
		ray.dis = (ray.side == 0) ?
			abs_d((ray.map_x - env->player.x + (1 - ray.step_x) / 2) / ray.ux) :
			abs_d((ray.map_y - env->player.y + (1 - ray.step_y) / 2) / ray.uy);
		env->screen = g_draw(*env, i, ray);
		i++;
	}
	g_refresh_win(env->screen, *env);
	return (0);
}
