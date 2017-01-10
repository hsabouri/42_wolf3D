/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_keyboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:01:18 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/10 17:48:00 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	keyboard(t_env *env)
{
	if (env->keystatus[A])
		env->player = m_left(env->player);
	if (env->keystatus[D])
		env->player = m_right(env->player);
	if (env->keystatus[W])
		env->player = m_forward(env->player);
	if (env->keystatus[S])
		env->player = m_backward(env->player);
	if (env->keystatus[LT])
		env->player = m_rotate(env->player, - M_PI / 40);
	if (env->keystatus[RT])
		env->player = m_rotate(env->player, M_PI / 40);
	if (env->keystatus[SUB])
		env->player.fov -= (env->player.fov > 0.05) ? 0.005 : 0;
	if (env->keystatus[ADD])
		env->player.fov += 0.005;
	if (env->keystatus[STAR])
		env->player.fov = 0.4;
	if (env->keystatus[N9])
		env->map.fog_dis += 0.05;
	if (env->keystatus[N6])
		env->map.fog_dis -= 0.05;
	if (env->keystatus[SLASH])
		env->map.fog_dis = 20;
}

int		keypress(int keycode, t_env *env)
{
	if (keycode < 127  && keycode >= 0)
		(env->keystatus)[keycode] = 1;
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	return (0);
}

int		keyrelease(int keycode, t_env *env)
{
	if (keycode < 127 && keycode >= 0)
		(env->keystatus)[keycode] = 0;
	return (0);
}
