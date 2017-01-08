/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:20:52 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/08 16:46:28 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "key_define.h"
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define TITLE "Wolf-3D"
# define WIDTH 400
# define HEIGHT 400
# define IMGSIZE WIDTH * HEIGHT * 32

# define KEYPRESSEVENT 2
# define KEYPRESSMASK (1L << 0)
# define KEYRELEASEEVENT 3
# define KEYRELEASEMASK (1L << 1)

typedef struct	s_image
{
	int		width;
	int		height;
	char	*data;
	void	*mlx_img;
}				t_image;

typedef struct	s_color
{
	unsigned char	blue;
	unsigned char	green;
	unsigned char	red;
	unsigned char	opacity;
}				t_color;

typedef struct	s_player
{
	double	x;
	double	y;
	double	angle;
	double	fov;
	double	ux;
	double	uy;
}				t_player;

typedef struct	s_map
{
	int		width;
	int		height;
	t_color	east;
	t_color	west;
	t_color	north;
	t_color	south;
	t_color	floor;
	t_color	sky;
	char	*map;
}				t_map;

typedef struct	s_env
{
	t_map		map;
	t_player	player;
	int			width;
	int			height;
	t_image		screen;
	void		*mlx;
	void		*win;
	int			keystatus[127];
}				t_env;

int		abs_i(int n);
double	abs_d(double n);

t_image		g_pixel_put(t_image image, int x, int y, t_color color);
t_image		g_new_image(t_env env);
void		g_refresh_win(t_image image, t_env env);

t_env		env_init(void);

int			keypress(int keycode, t_env *env);
int			keyrelease(int keycode, t_env *env);
void		keyboard(t_env *env);
int			g_loop(t_env *env);

#endif
