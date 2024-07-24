/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:54:23 by shiloub           #+#    #+#             */
/*   Updated: 2023/02/08 12:47:46 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	replace_spaces(char **map)
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
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

char	*add_spaces(char *str, int size)
{
	int	i;

	i = ft_strlen(str);
	while (i < size)
	{
		str = ft_strjoin_f(str, " ");
		i ++;
	}
	return (str);
}

void	set_spaces(char **map)
{
	int	size_max;
	int	i;

	size_max = 0;
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > size_max)
			size_max = ft_strlen(map[i]);
		i++;
	}
	i = 0;
	while (map[i])
	{
		map[i] = add_spaces(map[i], size_max);
		i++;
	}
}
