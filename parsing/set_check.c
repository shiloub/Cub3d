/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:54:27 by amontant          #+#    #+#             */
/*   Updated: 2023/02/08 12:57:16 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_infos(t_info *infos)
{
	infos->pure_map = NULL;
	infos->east_path = NULL;
	infos->north_path = NULL;
	infos->south_path = NULL;
	infos->west_path = NULL;
	infos->ground.r = -1;
	infos->sky.r = -1;
}

int	check_all_elems(t_info *infos)
{
	if (!infos->east_path || !infos->west_path || !infos->north_path
		|| !infos->south_path || infos->ground.r == -1 || infos->sky.r == -1)
		return (0);
	return (1);
}

void	set_os(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '0';
			j++;
		}
		i++;
	}
}

int	check_open(t_info *infos)
{
	int	fd;

	fd = open(infos->north_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open(infos->south_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open(infos->east_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	fd = open(infos->west_path, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}
