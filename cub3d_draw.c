/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:21:01 by evsuits           #+#    #+#             */
/*   Updated: 2023/02/08 17:47:14 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_data data)
{
	int	x;
	int	y;

	data.cam->x -= 3;
	data.cam->y -= 3;
	x = data.cam->x;
	y = data.cam->y;
	while (data.cam->y < y + 6)
	{
		data.cam->x = x;
		while (data.cam->x < x + 6)
		{
			img_pix_put(data.img, data.cam->x,
				data.cam->y, ORANGE);
			data.cam->x++;
		}
		data.cam->y++;
	}
	data.cam->x -= 3;
	data.cam->y -= 3;
}

static void	draw_block(int color, int i, int j, t_data *data)
{
	int	x;
	int	y;

	x = j * 64 + 1;
	y = i * 64 + 1;
	while (y < i * 64 + 64 - 1)
	{
		x = j * 64 + 1;
		while (x < j * 64 + 64 - 1)
		{
			img_pix_put(data->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	choose_color_type(t_data *data, int y, int yo, int x)
{
	if (y < yo - 1)
		img_pix_put(data->img, x, y, data->sky);
	else if (y <= yo + 1)
		img_pix_put(data->img, x, y, 0);
	else if (y >= yo && y < (int) data->line + yo - 1)
		img_pix_put(data->img, x, y,
			put_color(data, ((data->hx) / 64 - (int)
					(data->hx / 64)) * 64,
				(((y - yo) / data->line) * 64)));
	else if (y <= (int) data->line + yo + 1)
		img_pix_put(data->img, x, y, 0);
	else
		img_pix_put(data->img, x, y, data->floor);
}

void	draw_line(int numray, t_data *data)
{
	int	x;
	int	y;
	int	yo;
	int	xo;

	xo = numray * (data->img->w / 160);
	x = xo;
	yo = data->img->h / 2 - (data->line / 2);
	while (x <= ((data->img->w / 160) * (numray + 1)))
	{
		y = 0;
		while (y <= data->img->h)
		{
			choose_color_type(data, y, yo, x);
			y++;
		}
		x++;
		data->hx += data->dxray / data->img->w;
	}
}

void	draw_map(char **map, t_data *data)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N'
			|| map[i][j] == 'S' || map[i][j] == 'E'
			|| map[i][j] == 'W')
				color = VIOLET;
			else
				color = RED;
			draw_block(color, i, j, data);
			j++;
		}
		i++;
	}
}
