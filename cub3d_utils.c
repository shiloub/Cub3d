/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evsuits <evsuits@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:21:33 by evsuits           #+#    #+#             */
/*   Updated: 2023/02/08 15:53:18 by evsuits          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	fix_angle(double a)
{
	if (a > 2 * PI)
		a -= 2 * PI;
	if (a < 0)
		a += 2 * PI;
	return (a);
}

int	img_pix_get(t_image *img, int x, int y)
{
	int	i;
	int	r;
	int	g;
	int	b;
	int	color;

	if (x >= 0 && x <= img->w && y >= 0 && y <= img->h)
	{
		i = (y * img->line_len + x * (img->bpp / 8));
		r = img->addr[i];
		g = img->addr[++i];
		b = img->addr[++i];
		color = b;
		color += g << 8;
		color += r << 16;
	}
	return (color);
}

void	img_pix_put(t_image *img, int x, int y, int color)
{
	int	i;

	if (x >= 0 && x < img->w && y >= 0 && y < img->h)
	{
		i = (y * img->line_len + x * (img->bpp / 8));
		img->addr[i] = color;
		img->addr[++i] = color >> 8;
		img->addr[++i] = color >> 16;
	}
}

double	dist(int xa, int ya, int xb, int yb)
{
	double	difx;
	double	dify;

	if (xa > xb)
		difx = (xa - xb);
	else
		difx = (xb - xa);
	if (ya > yb)
		dify = (ya - yb);
	else
		dify = (yb - ya);
	return (sqrt((difx * difx) + (dify * dify)));
}

int	put_color(t_data *data, int xpixel, int ypixel)
{
	if (data->which_tex == 1)
		return (img_pix_get(data->tex_north, xpixel, ypixel));
	else if (data->which_tex == 2)
		return (img_pix_get(data->tex_south, xpixel, ypixel));
	else if (data->which_tex == 4)
		return (img_pix_get(data->tex_east, xpixel, ypixel));
	else
		return (img_pix_get(data->tex_west, xpixel, ypixel));
}
