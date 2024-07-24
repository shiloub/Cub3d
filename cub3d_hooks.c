/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evsuits <evsuits@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:35:34 by evsuits           #+#    #+#             */
/*   Updated: 2023/02/08 15:40:03 by evsuits          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int key, t_data *data)
{
	if (key == ESC)
		data->key_esc = 1;
	else if (key == UP)
		data->key_up = 1;
	else if (key == DOWN)
		data->key_down = 1;
	else if (key == LEFT)
		data->key_left = 1;
	else if (key == RIGHT)
		data->key_right = 1;
	else if (key == R_LEFT)
		data->key_rleft = 1;
	else if (key == R_RIGHT)
		data->key_rright = 1;
	return (0);
}

int	key_release(int key, t_data *data)
{
	if (key == ESC)
		data->key_esc = 0;
	else if (key == UP)
		data->key_up = 0;
	else if (key == DOWN)
		data->key_down = 0;
	else if (key == LEFT)
		data->key_left = 0;
	else if (key == RIGHT)
		data->key_right = 0;
	else if (key == R_LEFT)
		data->key_rleft = 0;
	else if (key == R_RIGHT)
		data->key_rright = 0;
	return (0);
}

int	handle_key(t_data *data)
{
	if (data->key_esc)
	{
		data->escyes = 42;
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	if (data->key_right || data->key_left || data->key_up
		|| data->key_down || data->key_rleft || data->key_rright)
	{
		mlx_destroy_image(data->mlx_ptr, (data->img)->img);
		image_init(data);
		get_move(data);
		send_rays(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->img,
			data->win_width / 10, data->win_height / 10);
	}
	return (0);
}

void	ft_hooks(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, handle_key, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, &key_press, data);
	mlx_hook(data->win_ptr, 3, 1L << 1, &key_release, data);
	mlx_hook(data->win_ptr, 17, 0, &mlx_loop_end, data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
	if (data->escyes != 42)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img->img);
	mlx_destroy_image(data->mlx_ptr, data->tex_east->img);
	mlx_destroy_image(data->mlx_ptr, data->tex_north->img);
	mlx_destroy_image(data->mlx_ptr, data->tex_south->img);
	mlx_destroy_image(data->mlx_ptr, data->tex_west->img);
	free(data->img);
	free(data->tex_east);
	free(data->tex_north);
	free(data->tex_south);
	free(data->tex_west);
	mlx_destroy_display(data->mlx_ptr);
}
