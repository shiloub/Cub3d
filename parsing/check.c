/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:02:13 by shiloub           #+#    #+#             */
/*   Updated: 2023/02/08 12:30:51 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_extention(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
		if (str[i] == '.')
		{
			if (str[i + 1] && str[i + 2] && str[i + 3] && !str[i + 4])
			{
				if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
					return (1);
			}
		}
	}
	return (0);
}

int	check_error(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (1);
	if (!check_extention(av[1]))
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}
