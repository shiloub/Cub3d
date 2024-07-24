/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:34:58 by evsuits           #+#    #+#             */
/*   Updated: 2023/02/08 15:10:54 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_sky_floor(t_data *data, t_info *infos)
{
	data->floor = infos->ground.b;
	data->floor += infos->ground.g << 8;
	data->floor += infos->ground.r << 16;
	data->sky = infos->sky.b;
	data->sky += infos->sky.g << 8;
	data->sky += infos->sky.r << 16;
	data->key_down = 0;
	data->key_left = 0;
	data->key_right = 0;
	data->key_rleft = 0;
	data->key_rright = 0;
	data->key_up = 0;
	data->key_esc = 0;
}

int	main(int ac, char **av)
{
	t_data	data;
	t_info	*infos;

	data.escyes = 0;
	infos = parsing(ac, av);
	if (!infos)
		return (0);
	set_sky_floor(&data, infos);
	data.map = infos->pure_map;
	data.mapx = ft_strlen(data.map[0]);
	while (data.map[data.escyes])
		data.escyes++;
	data.mapy = data.escyes;
	data.escyes = 0;
	data_init(&data, infos);
	player_init(data.map, &data);
	send_rays(&data);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img->img,
		data.win_width / 10, data.win_height / 10);
	ft_hooks(&data);
	free_infos(infos);
	free(data.cam);
	free(data.mlx_ptr);
	return (0);
}
