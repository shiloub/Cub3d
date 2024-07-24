/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_display_lines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evsuits <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:20:52 by evsuits           #+#    #+#             */
/*   Updated: 2023/02/07 20:20:54 by evsuits          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	display_seg_cmpl(int pt[2], t_data *data, t_param param, int color)
{
	int	x;
	int	y;

	x = data->cam->x;
	y = data->cam->y;
	while (x != pt[0] || y != pt[1])
	{
		if (x <= (data->img)->w || y <= (data->img)->h)
			img_pix_put(data->img, x, y, color);
		param.error[1] = param.error[0] * 2;
		if ((param.error[1]) > -param.delta[1])
		{
			param.error[0] -= param.delta[1];
			x += param.sign[0];
		}
		if (param.error[1] < param.delta[0])
		{
			param.error[0] += param.delta[0];
			y += param.sign[1];
		}
	}
}

void	display_seg(int pt[2], t_data *data, int color)
{
	t_param	param;

	param.delta[0] = abs(pt[0] - data->cam->x);
	param.delta[1] = abs(pt[1] - data->cam->y);
	if (data->cam->x < pt[0])
		param.sign[0] = 1;
	else
		param.sign[0] = -1;
	if (data->cam->y < pt[1])
		param.sign[1] = 1;
	else
		param.sign[1] = -1;
	param.error[0] = param.delta[0] - param.delta[1];
	param.error[1] = param.error[0] * 2;
	display_seg_cmpl(pt, data, param, color);
}
