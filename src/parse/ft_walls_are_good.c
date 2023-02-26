/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls_are_good.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:49:46 by iren              #+#    #+#             */
/*   Updated: 2023/02/26 05:58:35 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_walls_are_closed(t_map *tmap, char **map)
{
	int	i;

	i = 0;
	printf("cols %d rows %d\n", tmap->cols, tmap->rows);
	while (i < tmap->cols)
	{
		if (map[0][i] == '0' || map[tmap->rows - 1][i] == '0')
			return (0);
		i++;
	}
	i = 0;
	while (i < tmap->rows)
	{
		if (map[i][0] == '0' || map[i][tmap->cols - 1] == '0')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_map_nrect_big(t_map *tmap, char **map)
{
	int		i;
	size_t	len;

	i = 1;
	if (map != 0)
	{
		len = ft_strlen(map[0]);
		if (tmap->cols > SCR_WID / TILE_SIZE
			|| tmap->rows > SCR_HEI / TILE_SIZE)
			return (1);
		while (i < tmap->rows)
		{
			if (len != ft_strlen(map[i]))
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}

int	ft_walls_are_good(t_map *tmap)
{
	if (ft_is_map_nrect_big(tmap, tmap->map))
	{
		return (0);
	}
	if (!ft_walls_are_closed(tmap, tmap->map))
	{
		return (0);
	}
	return (1);
}
