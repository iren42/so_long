/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_has_necessary_components.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:59:39 by iren              #+#    #+#             */
/*   Updated: 2023/02/25 17:59:40 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	add_comp(t_map *tmap, char c)
{
	if (ft_is_player_char(c))
		tmap->comp.nb_starting_points++;
	else if (c == 'E')
		tmap->comp.nb_exits++;
	else if (c == 'C')
		tmap->comp.nb_collec++;
}

static int	ft_inspect_map(t_map *tmap)
{
	int	i;
	int	j;

	if (tmap->map != 0)
	{
		i = -1;
		while (++i < tmap->rows)
		{
			j = -1;
			while (++j < tmap->cols)
			{
				add_comp(tmap, tmap->map[i][j]);
				if (ft_is_player_char(tmap->map[i][j]))
				{
					tmap->comp.player_x = j;
					tmap->comp.player_y = i;
				}
			}
		}
	}
	return (tmap->comp.nb_starting_points == 1 && tmap->comp.nb_exits == 1
		&& tmap->comp.nb_collec >= 1);
}

static void	init_comp(t_map_comp *c)
{
	c->nb_starting_points = 0;
	c->nb_collec = 0;
	c->nb_exits = 0;
	c->player_x = -1;
	c->player_y = -1;
}

int	ft_map_has_necessary_components(t_map *tmap)
{
	init_comp(&tmap->comp);
	if (ft_inspect_map(tmap) != 1)
		return (0);
	tmap->px = tmap->comp.player_x;
	tmap->py = tmap->comp.player_y;
	return (1);
}
