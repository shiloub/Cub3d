/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:32:08 by amontant          #+#    #+#             */
/*   Updated: 2023/02/08 17:31:25 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	count_lines(char **map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i][0])
			count ++;
		i++;
	}
	return (count + 1);
}

int	check_empty_line_map(char **map)
{
	int	i;
	int	j;
	int	map_start;

	i = 0;
	map_start = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (ft_strfind("10", map[i][j]))
			map_start = 1;
		if (map[i][0] == 0 && map_start)
		{
			ft_putstr("empty line in map\n");
			free_tab(map);
			return (1);
		}
		i++;
	}
	return (0);
}

char	**trim_empty_lines(char **map)
{
	char	**new_map;
	int		i;
	int		j;

	new_map = malloc(sizeof(char *) * count_lines(map));
	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i][0])
		{
			new_map[j] = ft_strdup(map[i]);
			j ++;
		}
		i++;
	}
	new_map[j] = 0;
	free_tab(map);
	return (new_map);
}

int	check_code_color(char *code)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (code[i])
	{
		if (!ft_isdigit(code[i]) && code[i] != ',')
			return (0);
		if (code[i] == ',')
		{
			count ++;
			if (code[i + 1] == ',' || code[i + 1] == 0 || i == 0)
				return (0);
		}
		i++;
	}
	if (count == 2)
		return (1);
	ft_putstr("color problem\n");
	return (0);
}

int	get_color(t_color *color, char *code)
{
	char	**rgb;

	if (check_code_color(code) == 0)
	{
		ft_putstr("error code color\n");
		return (-1);
	}
	rgb = ft_split(code, ',');
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	free_tab(rgb);
	if (color->r > 255 || color->g > 255 || color->b > 255)
		return (-1);
	return (0);
}
