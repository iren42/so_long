/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_has_wall_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 20:23:52 by iren              #+#    #+#             */
/*   Updated: 2023/03/20 21:00:08 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_msg(t_data *data, int x, int y)
{
	if (data)
	{
		if (data->img.tmap->map[y][x] == 'C')
		{
			ft_putendl_fd("Collectible found!", 1);
			data->img.tmap->map[y][x] = '0';
			data->img.tmap->comp.nb_collec--;
		}
		else if (data->img.tmap->map[y][x] == 'E')
		{
			if (data->img.tmap->comp.nb_collec == 0)
			{
				ft_putendl_fd("Success. Everything have been collected", 1);
				mlx_destroy_window(data->mlx_ptr, data->win_ptr);
				data->win_ptr = NULL;
			}
			else
				ft_msg(data->img.tmap->comp.nb_collec,
					"collectible(s) left", 1, 0);
		}
	}
}

int	ft_map_has_wall_at(t_data *data, int x, int y)
{
	if (data != 0)
	{
		if (x < 0 || x > data->img.tmap->cols || y < 0
			|| y > data->img.tmap->rows)
			return (1);
		else
			game_msg(data, x, y);
		if (data->img.tmap->map[y][x] != '1')
			ft_msg(++(data->img.player.nb_mvmt), "movements in total", 1, 0);
		return (data->img.tmap->map[y][x] == '1');
	}
	return (1);
}
