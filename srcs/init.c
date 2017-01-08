/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:58:32 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/08 17:41:01 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static t_map	map_init(void)
{
	t_map	map;

	map.width = 10;
	map.height = 10;
	if (!(map.map = ft_strnew(100)))
		exit(EXIT_FAILURE);
	map.map = ft_memcpy(map.map ,"\
\1\1\1\1\1\1\1\1\1\1\
\1\0\0\0\0\0\0\0\0\1\
\1\0\0\0\0\0\0\0\0\1\
\1\0\0\0\0\0\0\0\0\1\
\1\0\0\0\1\1\1\1\1\1\
\1\0\0\0\0\0\0\0\0\1\
\1\0\0\0\0\0\0\0\0\1\
\1\0\0\0\0\2\0\0\0\1\
\1\0\0\0\0\0\0\0\0\1\
\1\1\1\1\1\1\1\1\1\1", 100);
	map.east = (t_color){255, 0, 255, 0};
	map.west = (t_color){255, 255, 0, 0};
	map.north = (t_color){0, 255, 255, 0};
	map.south = (t_color){0, 255, 0, 0};
	map.floor = (t_color){50, 50, 50, 0};
	map.sky = (t_color){255, 255, 255, 0};
	return (map);
}

static t_player	player_init(t_env env)
{
	t_player player;
	int i;

	i = 0;
	while (env.map.map[i] != 2 && i < 100)
		i++;
	player.x = (double)(i % env.map.width);
	player.y = (double)(i / env.map.width);
	player.angle = 0;
	player.fov = 0.4;
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
	return (env);
}
