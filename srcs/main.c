/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:20:20 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/12 15:15:14 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	main(void)
{
	t_env	env;

	env = env_init();
	mlx_hook(env.win, KEYPRESSEVENT, KEYPRESSMASK, &keypress, &env);
	mlx_hook(env.win, KEYRELEASEEVENT, KEYRELEASEMASK, &keyrelease, &env);
	mlx_hook(env.win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, &destroy, &env);
	mlx_hook(env.win, MOTIONNOTIFY, POINTERMOTIONMASK, &g_mouse, &env);
	mlx_mouse_hook(env.win, &g_mouse_click, &env);
	g_refresh_win(env.screen, env);
	mlx_loop_hook(env.mlx, &g_loop, &env);
	mlx_loop(env.mlx);
	return (0);
}
