/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:35:17 by evsuits           #+#    #+#             */
/*   Updated: 2023/02/08 16:39:55 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_angle(t_data *data, char map)
{
	if (map == 'S')
		data->cam->a = (PI / 2);
	else if (map == 'N')
		data->cam->a = (3 * PI / 2);
	else if (map == 'E')
		data->cam->a = 0.00000;
	else if (map == 'W')
		data->cam->a = PI;
}

void	player_init(char **map, t_data *data)
{
	int	j;
	int	i;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				data->cam->x = j * 64 + (64 / 2);
				data->cam->y = i * 64 + (64 / 2);
				player_angle(data, map[i][j]);
			}
			j++;
		}
		i++;
	}
	data->cam->dx = cos(data->cam->a) * 5;
	data->cam->dy = sin(data->cam->a) * 5;
}

int	image_init(t_data *data)
{
	data->img->w = (data->win_width - (data->win_width / 5));
	data->img->h = (data->win_height - (data->win_height / 5));
	data->img->img = mlx_new_image(data->mlx_ptr,
			data->img->w + 1, data->img->h + 1);
	data->img->addr = mlx_get_data_addr(data->img->img, &(data->img)->bpp,
			&(data->img)->line_len, &(data->img)->endian);
	return (0);
}

void	set_first_variables(t_data *data)
{
	data->win_height = 530;
	data->win_width = 945;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width,
			data->win_height, "--  LOS CUBOS 3D  --");
}

void	data_init(t_data *data, t_info *infos)
{
	set_first_variables(data);
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		exit(EXIT_FAILURE);
	}
	data->img = malloc(sizeof(t_image));
	if (!(data->img))
		return ;
	image_init(data);
	if (!texture_init(data, infos))
	{	
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free_infos(infos);
		exit (0);
	}
	data->cam = malloc(sizeof(t_cam));
	if (!(data->cam))
		return (free(data->img), free(data->tex_east),
			free(data->tex_west), free(data->tex_north), free(data->tex_south));
}
