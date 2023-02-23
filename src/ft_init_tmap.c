/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:14:11 by iren              #+#    #+#             */
/*   Updated: 2021/08/14 14:30:41 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_tmap(t_map *tmap)
{
	tmap->error = 0;
	tmap->texture = malloc(sizeof(char*) * 5);
	if (tmap->texture != NULL)
	{
		tmap->texture[wall] = ft_strdup("./texture/pillar.xpm");
		tmap->texture[ground] = ft_strdup("./texture/mossy.xpm");
		tmap->texture[collec] = ft_strdup("./texture/elixir.xpm");
		tmap->texture[map_exit] = ft_strdup("./texture/door.xpm");
		tmap->texture[player] = ft_strdup("./texture/sans_player.xpm");
	}
//	tmap->floor = -1;
//	tmap->ceiling = -1;
	tmap->map = 0;
	tmap->rows = 0;
	tmap->cols = 0;
}
