/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 22:34:25 by iren              #+#    #+#             */
/*   Updated: 2021/08/14 14:31:15 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_tmap(t_map *tmap)
{
	int	i;

	i = -1;
	if (tmap != NULL)
	{
		if (tmap->texture[wall] != 0)
			free(tmap->texture[wall]);
		if (tmap->texture[ground] != 0)
			free(tmap->texture[ground]);
		if (tmap->texture[collec] != 0)
			free(tmap->texture[collec]);
		if (tmap->texture[map_exit] != 0)
			free(tmap->texture[map_exit]);
		if (tmap->texture[player] != 0)
			free(tmap->texture[player]);
		free(tmap->texture);
		if (tmap->map != 0)
		{
			while (tmap->map[++i] != 0)
				free(tmap->map[i]);
			free(tmap->map);
			tmap->map = 0;
		}
	}
}
