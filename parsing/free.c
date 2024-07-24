/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:35:52 by shiloub           #+#    #+#             */
/*   Updated: 2023/02/08 17:33:22 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
	{
		free(tab);
		return ;
	}
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_infos(t_info *info)
{
	free(info->east_path);
	free(info->west_path);
	free(info->north_path);
	free(info->south_path);
	free_tab(info->pure_map);
	free(info);
}
