/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evsuits <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:33:11 by evsuits           #+#    #+#             */
/*   Updated: 2023/02/08 14:33:13 by evsuits          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_data *data)
{
	int	arrivalx;
	int	arrivaly;

	arrivalx = (int)(data->cam->x + (data->cam->dx * 2)) / 64;
	arrivaly = (int)(data->cam->y + (data->cam->dy * 2)) / 64;
	if (arrivalx < 0 || arrivalx > data->mapx || arrivaly < 0
		|| arrivaly > data->mapy)
		return ;
	if (data->map[arrivaly][arrivalx] == '1')
		return ;
	(data->cam->y) += data->cam->dy;
	(data->cam->x) += data->cam->dx;
}

void	move_down(t_data *data)
{
	int	arrivalx;
	int	arrivaly;

	arrivalx = (int)(data->cam->x - (data->cam->dx * 2)) / 64;
	arrivaly = (int)(data->cam->y - (data->cam->dy * 2)) / 64;
	if (arrivalx < 0 || arrivalx > data->mapx || arrivaly < 0
		|| arrivaly > data->mapy)
		return ;
	if (data->map[arrivaly][arrivalx] == '1')
		return ;
	(data->cam->y) -= data->cam->dy;
	(data->cam->x) -= data->cam->dx;
}

void	move_left(t_data *data)
{
	int	arrivalx;
	int	arrivaly;

	arrivaly = (int)(data->cam->y + (data->cam->dx * 2)) / 64;
	arrivalx = (int)(data->cam->x - (data->cam->dy * 2)) / 64;
	if (arrivalx < 0 || arrivalx > data->mapx || arrivaly < 0
		|| arrivaly > data->mapy)
		return ;
	if (data->map[arrivaly][arrivalx] == '1')
		return ;
	(data->cam->y) += data->cam->dx;
	(data->cam->x) -= data->cam->dy;
}

void	move_right(t_data *data)
{
	int	arrivalx;
	int	arrivaly;

	arrivaly = (int)(data->cam->y - (data->cam->dx * 2)) / 64;
	arrivalx = (int)(data->cam->x + (data->cam->dy * 2)) / 64;
	if (arrivalx < 0 || arrivalx > data->mapx || arrivaly < 0
		|| arrivaly > data->mapy)
		return ;
	if (data->map[arrivaly][arrivalx] == '1')
		return ;
	(data->cam->y) -= data->cam->dx;
	(data->cam->x) += data->cam->dy;
}

void	get_move(t_data *data)
{
	if (data->key_rright)
		look_right(data);
	else if (data->key_rleft)
		look_left(data);
	else if (data->key_up)
		move_up(data);
	else if (data->key_down)
		move_down(data);
	else if (data->key_left)
		move_left(data);
	else if (data->key_right)
		move_right(data);
}
