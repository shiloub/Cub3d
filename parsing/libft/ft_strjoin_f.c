/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontant <amontant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:38:19 by amontant          #+#    #+#             */
/*   Updated: 2023/02/03 16:21:07 by amontant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin_f(char *s1, char const *s2)
{
	int		lens1;
	char	*strcat;
	int		i;

	lens1 = ft_strlen((char *)s1);
	i = 0;
	strcat = malloc(sizeof(char) * (lens1 + ft_strlen((char *)s2) + 1));
	if (!strcat)
		return (0);
	while (s1[i])
	{
		strcat[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		strcat[i + lens1] = s2[i];
		i++;
	}
	strcat[i + lens1] = '\0';
	free(s1);
	return (strcat);
}
