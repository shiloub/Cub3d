/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_hcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evsuits <evsuits@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:21:17 by evsuits           #+#    #+#             */
/*   Updated: 2023/02/07 21:04:32 by evsuits          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	h_looking_down(t_data *data, double atan)
{
	data->yray = (((int)(data->cam->y / 64)) * 64) - 0.0001;
	data->xray = ((data->cam->y - data->yray) * atan) + data->cam->x;
	data->ystep = -64;
	data->xstep = -data->ystep * atan;
}

static void	h_looking_up(t_data *data, double atan)
{
	data->yray = (((int)(data->cam->y / 64)) * 64) + 64;
	data->xray = ((data->cam->y - data->yray) * atan) + data->cam->x;
	data->ystep = 64;
	data->xstep = -data->ystep * atan;
}

static int	first_h_check(t_data *data)
{
	double	atan;

	atan = -1 / tan(data->alpharay);
	if (data->alpharay > PI)
	{
		data->which_tex = 1;
		h_looking_down(data, atan);
	}
	else if (data->alpharay < PI)
	{
		data->which_tex = 2;
		h_looking_up(data, atan);
	}
	else
	{
		data->xray = data->cam->x;
		data->yray = data->cam->y;
		return (8);
	}
	return (0);
}

double	hit_h_wall(t_data *data)
{
	data->hx = data->xray;
	data->hy = data->yray;
	return (dist(data->cam->x, data->cam->y, data->hx, data->hy));
}

double	check_hwall(t_data *data)
{
	int		mx;
	int		my;
	int		check;
	double	dist_h;

	dist_h = 10000000;
	check = first_h_check(data);
	while (check < data->mapy)
	{
		mx = (int) data->xray / 64 ;
		my = (int) data->yray / 64 ;
		if (my >= 0 && mx >= 0 && (my < data->mapy && mx < data->mapx)
			&& data->map[my][mx] == '1')
			return (hit_h_wall(data));
		else
		{
			data->xray += data->xstep;
			data->yray += data->ystep;
			check++;
		}
	}
	return (dist_h);
}
