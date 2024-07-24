/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:24:46 by evsuits           #+#    #+#             */
/*   Updated: 2023/02/08 17:48:50 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	send_rays_compl(t_data *data, int vert, double dist_h, int numray)
{
	dist_h = dist_h * cos(fix_angle(data->cam->a - data->alpharay));
	data->dxray = (tan(fix_angle(40 * DEG)) * dist_h) * 2;
	data->line = (MAPTILES * data->img->h) / dist_h;
	if (data->line > MAPTILES * data->img->h)
		data->line = MAPTILES * data->img->h;
	if (vert == 1)
		if (cos(data->alpharay) < 0.00001)
			data->dxray *= (-1);
	if (vert == 0)
		if (data->alpharay < PI)
			data->dxray *= (-1);
	draw_line(numray, data);
}

void	send_rays(t_data *data)
{
	int		numray;
	double	dist_hv[2];
	int		vert;

	numray = 0;
	data->alpharay = fix_angle(data->cam->a - 40 * DEG);
	while (numray < 160)
	{
		vert = 0;
		dist_hv[0] = check_hwall(data);
		dist_hv[1] = check_vwall(data);
		if (dist_hv[0] >= dist_hv[1] && ++vert)
		{
			data->hx = data->vy;
			data->which_tex = (data->which_tex / 10) + 2;
			dist_hv[0] = dist_hv[1];
		}
		else
			data->which_tex = data->which_tex % 10;
		send_rays_compl(data, vert, dist_hv[0], numray);
		data->alpharay = fix_angle(data->alpharay + (0.5 * DEG));
		numray++;
	}
}
