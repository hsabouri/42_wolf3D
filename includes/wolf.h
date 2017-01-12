/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 20:20:52 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/12 14:45:44 by hsabouri         ###   ########.fr       */
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
# define WIDTH 1920
# define HEIGHT 1080
# define IMGSIZE WIDTH * HEIGHT * 32

# define KEYPRESSEVENT 2
# define KEYPRESSMASK (1L << 0)
# define KEYRELEASEEVENT 3
# define KEYRELEASEMASK (1L << 1)
# define DESTROYNOTIFY 17
# define STRUCTURENOTIFYMASK (1L<<17)

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
	double	speed;
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
	t_color	fog;
	double	fog_dis;
	char	map[625];
}				t_map;

typedef struct	s_env
{
	t_map		map;
	t_player	player;
	int			width;
	int			height;
	int			px;
	int			py;
	t_image		screen;
	void		*mlx;
	void		*win;
	int			keystatus[127];
}				t_env;

typedef struct	s_raycast
{
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		next_x;
	int		next_y;
	int		side;
	double	ux;
	double	uy;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	angle;
	double	dis;
	t_color	color;
}				t_raycast;

int				abs_i(int n);
double			abs_d(double n);

t_image			g_pixel_put(t_image image, int x, int y, t_color color);
t_image			g_new_image(t_env env);
void			g_refresh_win(t_image image, t_env env);

t_raycast		ray_init(t_env *env, int i);
t_raycast		m_raytrace(t_env *env, t_raycast ray);

t_env			env_init(void);

int				keypress(int keycode, t_env *env);
int				keyrelease(int keycode, t_env *env);
void			keyboard(t_env *env);
int				g_mouse_click(int button, int x, int y, t_env *env);
int				g_mouse(int x, int y, t_env *env);
int				g_loop(t_env *env);

t_player		m_left(t_env env, t_player player);
t_player		m_right(t_env env, t_player player);
t_player		m_forward(t_env env, t_player player);
t_player		m_backward(t_env env, t_player player);
t_player		m_rotate(t_player player, double angle);

int				destroy(t_env *env);

#endif
