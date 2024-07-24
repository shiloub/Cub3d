/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:41:43 by amontant          #+#    #+#             */
/*   Updated: 2023/02/08 17:25:43 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/X.h>
# include "parsing/parsing.h"

# define MAPTILES 64
# define DEG 0.01745329

# define ESC 65307
# define RIGHT 97
# define LEFT 100
# define R_LEFT 65361
# define R_RIGHT 65363
# define UP 119
# define DOWN 115

# define PI 3.14159265
# define RED 0xFF1E26
# define ORANGE 0xFE941E
# define YELLOW 0xFFFF00
# define GREEN 0x06BD00
# define BLUE 0x001A98
# define VIOLET 0x760088

typedef struct s_image {
	int		w;
	int		h;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		tr;
}	t_image;

typedef struct s_cam {
	int		x;
	int		y;
	int		dx;
	int		dy;
	double	a;
}	t_cam;

typedef struct s_data {
	int		mapx;
	int		mapy;
	int		win_width;
	int		win_height;
	int		escyes;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	t_cam	*cam;
	double	dxray;
	double	xray;
	double	yray;
	double	xstep;
	double	ystep;
	double	alpharay;
	double	hx;
	double	hy;
	double	vx;
	double	vy;
	double	line;
	t_image	*img;
	t_image	*tex_north;
	t_image	*tex_south;
	t_image	*tex_east;
	t_image	*tex_west;

	int		key_up;
	int		key_down;
	int		key_right;
	int		key_left;
	int		key_rright;
	int		key_rleft;
	int		key_esc;
	int		which_tex;
	int		floor;
	int		sky;
}	t_data;

typedef struct s_param {
	int	delta[2];
	int	sign[2];
	int	error[2];
}	t_param;

//hooks.c
void	ft_hooks(t_data *data);
int		handle_key(t_data *data);
void	look_left(t_data *data);
void	look_right(t_data *data);

//init.c
void	player_init(char **map, t_data *data);
int		image_init(t_data *data);
void	data_init(t_data *data, t_info *infos);

//init_texture.c
int		texture_init(t_data *data, t_info *infos);

//draw.c
int		img_pix_get(t_image *img, int x, int y);
void	draw_map(char **map, t_data *data);
void	draw_player(t_data data);
void	draw_line(int numray, t_data *data);

//vcheck.c
double	check_hwall(t_data *data);

//hcheck.c
double	check_vwall(t_data *data);

//raycasting.c
void	send_rays(t_data *data);

//move.c
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	get_move(t_data *data);

//display_lines.c
void	display_seg(int pt[2], t_data *data, int color);

//utils.c
void	img_pix_put(t_image *img, int x, int y, int color);
int		img_pix_get(t_image *img, int x, int y);
double	dist(int xa, int ya, int xb, int yb);
double	fix_angle(double a);
int		put_color(t_data *data, int xpixel, int ypixel);

#endif
