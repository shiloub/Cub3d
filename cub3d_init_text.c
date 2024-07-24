/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_init_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:18:10 by amontant          #+#    #+#             */
/*   Updated: 2023/02/08 17:30:14 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_tex_start(t_data *data)
{
	data->tex_east = NULL;
	data->tex_west = NULL;
	data->tex_north = NULL;
	data->tex_south = NULL;
}

static t_image	*tex_init(t_data *data, char *path)
{
	t_image	*text;

	text = malloc(sizeof(t_image));
	if (!text)
		return (NULL);
	text->img = mlx_xpm_file_to_image(data->mlx_ptr, path,
			&(text)->w, &(text)->h);
	if (!text->img)
	{
		ft_putstr("ERROR : wrong xpm file\n");
		free(text);
		return (NULL);
	}
	text->addr = mlx_get_data_addr(text->img,
			&(text)->bpp,
			&(text)->line_len, &(text)->endian);
	return (text);
}

int	texture_init(t_data *d, t_info *infos)
{
	d->tex_east = tex_init(d, infos->east_path);
	if (!(d->tex_east))
		return (mlx_destroy_image(d->mlx_ptr, d->img->img),
			free(d->img), 0);
	d->tex_west = tex_init(d, infos->west_path);
	if (!(d->tex_west))
		return (mlx_destroy_image(d->mlx_ptr, d->img->img),
			free(d->img),
			mlx_destroy_image(d->mlx_ptr, d->tex_east->img),
			free(d->tex_east), 0);
	d->tex_south = tex_init(d, infos->south_path);
	if (!(d->tex_south))
		return (mlx_destroy_image(d->mlx_ptr, d->img->img),
			free(d->img), mlx_destroy_image(d->mlx_ptr,
				d->tex_east->img), free(d->tex_east),
			mlx_destroy_image(d->mlx_ptr, d->tex_west->img),
			free(d->tex_west), 0);
	d->tex_north = tex_init(d, infos->north_path);
	if (!(d->tex_north))
		return (mlx_destroy_image(d->mlx_ptr, d->img->img), free(d->img),
			mlx_destroy_image(d->mlx_ptr, d->tex_east->img), free(d->tex_east),
			mlx_destroy_image(d->mlx_ptr, d->tex_west->img), free(d->tex_west),
			mlx_destroy_image(d->mlx_ptr, d->tex_south->img),
			free(d->tex_south), 0);
	return (1);
}
