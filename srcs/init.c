/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:58:32 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/12 14:45:43 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static t_map	map_init(void)
{
	t_map	map;

	map.width = 25;
	map.height = 25;
	ft_bzero(map.map, map.width * map.height);
	map.east = (t_color){255, 0, 255, 0};
	map.west = (t_color){255, 255, 0, 0};
	map.north = (t_color){0, 255, 255, 0};
	map.south = (t_color){0, 255, 0, 0};
	map.floor = (t_color){50, 50, 50, 0};
	map.sky = (t_color){60, 60, 60, 0};
	map.fog = (t_color){0, 0, 0, 0};
	map.fog_dis = 20;
	return (map);
}

static t_player	player_init(t_env env)
{
	t_player	player;
	int			i;

	i = 0;
	while (env.map.map[i] != 2 && i < env.map.width * env.map.height)
		i++;
	player.x = 10;
	player.y = 10;
	player.angle = 0;
	player.fov = 0.40;
	player.speed = 1;
	return (player);
}

t_env			env_init(void)
{
	t_env	env;

	env.width = WIDTH;
	env.height = HEIGHT;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.width, env.height, TITLE);
	env.screen = g_new_image(env);
	env.map = map_init();
	env.player = player_init(env);
	env.px = -1;
	env.px = -1;
	ft_bzero(env.keystatus, sizeof(int) * 127);
	return (env);
}
