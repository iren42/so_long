/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 22:34:25 by iren              #+#    #+#             */
/*   Updated: 2023/03/21 17:26:17 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_tex(t_map *tmap)
{
	free(tmap->texture[wall]);
	tmap->texture[wall] = 0;
	free(tmap->texture[ground]);
	tmap->texture[ground] = 0;
	free(tmap->texture[collec]);
	tmap->texture[collec] = 0;
	free(tmap->texture[map_exit]);
	tmap->texture[map_exit] = 0;
	free(tmap->texture[player]);
	tmap->texture[player] = 0;
	free(tmap->texture);
	tmap->texture = 0;
}

void	ft_free_tmap(t_map *tmap)
{
	int	i;

	i = -1;
	if (tmap != NULL)
	{
		free_tex(tmap);
		if (tmap->map != 0)
		{
			while (tmap->map[++i] != 0)
			{
				free(tmap->map[i]);
				tmap->map[i] = 0;
			}
			free(tmap->map);
			tmap->map = 0;
		}
	}
}
