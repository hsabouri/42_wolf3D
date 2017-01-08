/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_keyboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:01:18 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/08 17:16:47 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	keyboard(t_env *env)
{
	if (env->keystatus[A])
		env->player.angle -= M_PI / 20;
	if (env->keystatus[D])
		env->player.angle += M_PI / 20;
	if (env->keystatus[W])
	{
		env->player.x += cos(env->player.angle) / 5;
		env->player.y += sin(env->player.angle) / 5;
	}
	if (env->keystatus[S])
	{
		env->player.x -= cos(env->player.angle) / 5;
		env->player.y -= sin(env->player.angle) / 5;
	}
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
