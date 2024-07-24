/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:29:51 by shiloub           #+#    #+#             */
/*   Updated: 2023/02/08 17:31:05 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_all_elem(char **map)
{
	int	i;
	int	j;
	int	jugador;

	jugador = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strfind("WENS01 ", map[i][j]))
				return (0);
			if (ft_strfind("WENS", map[i][j]))
				jugador ++;
			j++;
		}
		i++;
	}
	if (jugador != 1)
		return (0);
	return (1);
}

int	ratata(char **map, char c, int i, int j)
{
	if (i == 0 && c != '1' && c != ' ')
		return (0);
	if (j == 0 && c != '1' && c != ' ')
		return (0);
	if ((!map[i][j + 1] || map[i][j + 1] == ' ') && c != '1' && c != ' ')
		return (0);
	if (!map[i + 1] && c != '1' && c != ' ')
		return (0);
	if (i != 0 && map[i - 1][j] == ' ' && c != '1' && c != ' ')
		return (0);
	if (map[i + 1] && map[i + 1][j] == ' ' && c != '1' && c != ' ')
		return (0);
	return (1);
}

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ratata(map, map[i][j], i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(char **map)
{
	if (!check_all_elem(map))
	{
		ft_putstr("elem no valid in map\n");
		return (0);
	}
	if (!check_walls(map))
	{
		ft_putstr("map isnt surrounded by walls\n");
		return (0);
	}
	return (1);
}
