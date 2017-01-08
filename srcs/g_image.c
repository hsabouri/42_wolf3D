/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_image.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:13:45 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/06 13:38:03 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_image		g_pixel_put(t_image image, int x, int y, t_color color)
{
	if (x < image.width && y < image.height && x >= 0 && y >= 0)
		((t_color *)(image.data))[(x + (y * image.width))] = color;
	return (image);
}

t_image		g_new_image(t_env env)
{
	const t_env	c_env = env;
	t_image		new;
	int			bin;

	new.mlx_img = mlx_new_image(c_env.mlx, c_env.width, c_env.height);
	new.width = c_env.width;
	new.height = c_env.height;
	new.data = mlx_get_data_addr(new.mlx_img, &bin, &bin, &bin);
	return (new);
}

void		g_refresh_win(t_image image, t_env env)
{
	mlx_put_image_to_window(env.mlx, env.win, image.mlx_img, 0, 0);
}
