/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:25:13 by shiloub           #+#    #+#             */
/*   Updated: 2023/02/08 17:31:37 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	norme(t_info *info, char **line)
{
	if (!ft_strncmp("F", line[0], 2147483647))
	{
		if (info->ground.r != -1 || !line[1])
			return (-1);
		if (get_color(&info->ground, line[1]) == -1)
			return (-1);
	}
	else if (!ft_strncmp("C", line[0], 2147483647))
	{
		if (info->sky.r != -1 || !line[1])
			return (-1);
		if (get_color(&info->sky, line[1]) == -1)
			return (-1);
	}
	else if (!ft_strncmp("WE", line[0], 21))
	{
		if (info->west_path || !line[1])
			return (-1);
		info->west_path = ft_strdup(line[1]);
	}
	else
		return (1);
	return (0);
}

int	get_info(t_info *info, char **line)
{
	if (!ft_strncmp("NO", line[0], 21))
	{
		if (info->north_path || !line[1])
			return (-1);
		info->north_path = ft_strdup(line[1]);
	}
	else if (!ft_strncmp("SO", line[0], 21))
	{
		if (info->south_path || !line[1])
			return (-1);
		info->south_path = ft_strdup(line[1]);
	}
	else if (!ft_strncmp("EA", line[0], 21))
	{
		if (info->east_path || !line[1])
			return (-1);
		info->east_path = ft_strdup(line[1]);
	}
	else
		return (norme(info, line));
	return (0);
}

int	lines_left(char **map, int i)
{
	int	count;

	count = 0;
	while (map[i])
	{
		count ++;
		i++;
	}
	return (count + 1);
}

int	what_to_do(int i, int map_start, char **map, t_info *info)
{
	int	j;

	if (map_start == -1)
		return (-1);
	info->pure_map = malloc(sizeof(char *) * lines_left(map, i));
	j = 0;
	while (map[i])
	{
		info->pure_map[j] = ft_strdup(map[i]);
		i++;
		j++;
	}
	info->pure_map[j] = NULL;
	free_tab(map);
	return (0);
}

int	parse_first_elems(char **map, t_info *info)
{
	char	**line_split;
	int		i;
	int		map_start;

	map_start = 0;
	i = 0;
	while (map[i])
	{
		line_split = ft_split(map[i], ' ');
		map_start = get_info(info, line_split);
		if (map_start == 0 && line_split[1] && line_split[2])
		{
			ft_putstr("Error en el mapa expediente\n");
			map_start = -1;
		}
		free_tab(line_split);
		if (map_start != 0)
			break ;
		i++;
	}
	return (what_to_do(i, map_start, map, info));
}
