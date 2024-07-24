/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_vcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evsuits <evsuits@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:21:25 by evsuits           #+#    #+#             */
/*   Updated: 2023/02/08 15:58:07 by evsuits          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	looking_right(t_data *data, double ntan)
{
	data->xray = (((int)data->cam->x / 64) * 64) - 0.00001;
	data->yray = (data->cam->x - data->xray) * -ntan + data->cam->y;
	data->xstep = -64;
	data->ystep = data->xstep * ntan;
}

static void	looking_left(t_data *data, double ntan)
{
	data->xray = ((int)(data->cam->x / 64) * 64) + 64;
	data->yray = (data->cam->x - data->xray) * -ntan + data->cam->y;
	data->xstep = 64;
	data->ystep = data->xstep * ntan;
}

static int	first_v_check(t_data *data)
{
	double	ntan;

	ntan = (1 * tan(data->alpharay));
	data->vx = data->cam->x;
	data->vy = data->cam->y;
	if (cos(data->alpharay) <= -0.00000)
	{
		data->which_tex += 10;
		looking_right(data, ntan);
	}
	else if (cos(data->alpharay) >= 0.00000)
	{
		data->which_tex += 20;
		looking_left(data, ntan);
	}
	else
	{
		data->xray = data->cam->x;
		data->yray = data->cam->y;
		return (8);
	}
	return (0);
}

static double	hit_v_wall(t_data *data)
{
	data->vx = data->xray;
	data->vy = data->yray;
	return (dist(data->cam->x, data->cam->y, data->vx, data->vy));
}

double	check_vwall(t_data *data)
{
	int		mx;
	int		my;
	int		check;
	double	dist_v;

	check = first_v_check(data);
	dist_v = 100000000;
	while (check < data->mapx)
	{
		mx = (int)(data->xray) / 64;
		my = (int)(data->yray) / 64;
		if (my >= 0 && mx >= 0 && (my < data->mapy && mx < data->mapx)
			&& data->map[my][mx] == '1')
			return (hit_v_wall(data));
		else
		{
			data->xray += data->xstep;
			data->yray += data->ystep;
			check++;
		}
	}
	return (dist_v);
}
