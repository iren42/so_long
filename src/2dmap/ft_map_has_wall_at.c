/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_has_wall_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 20:23:52 by iren              #+#    #+#             */
/*   Updated: 2021/08/14 19:15:06 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_has_wall_at(t_data *data, int x, int y)
{
	if (x < 0 || x > data->img.tmap->rows || y < 0 || y > data->img.tmap->cols)
		return (1);
	else if (data->img.tmap->map[x][y] == 'C')
	{
		data->img.tmap->map[x][y] = '0';
		data->img.tmap->comp.nb_collec--;
	}
	else if (data->img.tmap->map[x][y] == 'E')
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
	if (data->img.tmap->map[x][y] != '1')
		ft_msg(++(data->img.player.nb_mvmt), "movements in total\n", 1);
	return (data->img.tmap->map[x][y] == '1');
}
