/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:49:19 by shiloub           #+#    #+#             */
/*   Updated: 2023/02/08 12:46:54 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	count_line(char *map_path)
{
	int		fd_map;
	char	*line;
	int		count;

	line = NULL;
	count = 0;
	fd_map = open(map_path, O_RDONLY);
	if (!fd_map)
		return (0);
	while (1)
	{
		line = get_next_line(fd_map);
		if (!line)
			break ;
		free(line);
		count ++;
	}
	close(fd_map);
	return (count);
}

void	throw_away_the_cr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		i ++;
	}
	if (str[i - 1] == '\n')
		str[i - 1] = 0;
}

char	**parse_file(char *map_path)
{
	int		fd_map;
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (count_line(map_path) + 1));
	if (!map)
		return (NULL);
	fd_map = open(map_path, O_RDONLY);
	while (1)
	{
		map[i] = get_next_line(fd_map);
		throw_away_the_cr(map[i]);
		if (!map[i])
			break ;
		i++;
	}
	close(fd_map);
	if (!map[0])
	{
		free_tab(map);
		return (NULL);
	}
	return (map);
}
