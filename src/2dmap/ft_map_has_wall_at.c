/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_has_wall_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 20:23:52 by iren              #+#    #+#             */
/*   Updated: 2023/02/26 05:56:04 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_has_wall_at(t_data *data, int x, int y)
{
	if (x < 0 || x > data->img.tmap->cols || y < 0 || y > data->img.tmap->rows)
		return (1);
	else if (data->img.tmap->map[y][x] == 'C')
	{
		data->img.tmap->map[y][x] = '0';
		data->img.tmap->comp.nb_collec--;
	}
	else if (data->img.tmap->map[y][x] == 'E')
	{
		if (data->img.tmap->comp.nb_collec == 0)
		{
			ft_putendl_fd("Success. All collectibles have been collected.", 1);
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			data->win_ptr = NULL;
		}
		else
			ft_msg(data->img.tmap->comp.nb_collec, "collectibles left.", 1);
	}
	if (data->img.tmap->map[y][x] != '1')
		ft_msg(++(data->img.player.nb_mvmt), "movements in total\n", 1);
	return (data->img.tmap->map[y][x] == '1');
}
