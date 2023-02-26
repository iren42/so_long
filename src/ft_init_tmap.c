/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:14:11 by iren              #+#    #+#             */
/*   Updated: 2023/02/25 18:19:54 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	test_allocs(t_map *tmap)
{
	int	i;

	i = NB_TEX - 1;
	while (i >= 0)
	{
		if (tmap->texture[i] == NULL)
		{
			ft_free_previously_malloced(tmap->texture, i - 1);
			return (FAILURE);
		}
		else
			i--;
	}
	return (SUCCESS);
}

int	ft_init_tmap(t_map *tmap)
{
	int	i;

	i = -1;
	tmap->error = 1;
	tmap->texture = malloc(sizeof(char *) * 5);
	if (tmap->texture != NULL)
	{
		while (++i < NB_TEX)
			tmap->texture[i] = 0;
		tmap->texture[wall] = ft_strdup("./texture/eagle.xpm");
		tmap->texture[ground] = ft_strdup("./texture/wood.xpm");
		tmap->texture[collec] = ft_strdup("./texture/elixir.xpm");
		tmap->texture[map_exit] = ft_strdup("./texture/door.xpm");
		tmap->texture[player] = ft_strdup("./texture/sans_player.xpm");
	}
	tmap->map = 0;
	tmap->rows = 0;
	tmap->cols = 0;
	return (test_allocs(tmap));
}
