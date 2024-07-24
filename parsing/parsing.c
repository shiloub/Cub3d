/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:04:46 by shiloub           #+#    #+#             */
/*   Updated: 2023/02/08 17:31:48 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	first_parsing_checks(int ac, char **av, t_info *infos)
{
	char	**map;

	if (check_error(ac, av))
	{
		ft_putstr("Error\nWrong argument\n");
		return (0);
	}
	map = parse_file(av[1]);
	if (!map)
	{
		ft_putstr("Error\n Cant read map file\n");
		return (0);
	}
	if (check_empty_line_map(map))
		return (0);
	map = trim_empty_lines(map);
	if (parse_first_elems(map, infos) == -1)
	{
		free_tab(map);
		ft_putstr("Error in map file\n");
		return (0);
	}
	return (1);
}

int	clean_map(t_info *infos)
{
	replace_spaces(infos->pure_map);
	set_spaces(infos->pure_map);
	if (!check_map(infos->pure_map))
	{
		free_infos(infos);
		return (0);
	}
	set_os(infos->pure_map);
	return (1);
}

t_info	*parsing(int ac, char **av)
{
	t_info	*infos;

	infos = malloc(sizeof(t_info));
	set_infos(infos);
	if (first_parsing_checks(ac, av, infos) == 0)
	{
		free_infos(infos);
		return (0);
	}
	if (!check_all_elems(infos))
	{
		free_infos(infos);
		ft_putstr("textures or colors r missing\n");
		return (0);
	}
	if (!clean_map(infos))
		return (0);
	if (!check_open(infos))
	{
		free_infos(infos);
		ft_putstr("Error : cant open an xpm file\n");
		return (0);
	}
	return (infos);
}
