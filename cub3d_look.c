/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_look.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evsuits <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:39:09 by evsuits           #+#    #+#             */
/*   Updated: 2023/02/08 15:39:11 by evsuits          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	look_right(t_data *data)
{
	(data->cam->a) += 0.1;
	data->cam->a = fix_angle(data->cam->a);
	data->cam->dx = cos(data->cam->a) * 5;
	data->cam->dy = sin(data->cam->a) * 5;
}

void	look_left(t_data *data)
{
	(data->cam->a) -= 0.1;
	data->cam->a = fix_angle(data->cam->a);
	data->cam->dx = cos(data->cam->a) * 5;
	data->cam->dy = sin(data->cam->a) * 5;
}
