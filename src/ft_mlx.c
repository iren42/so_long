/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 23:08:32 by iren              #+#    #+#             */
/*   Updated: 2023/02/25 18:16:58 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_setup_player(t_data *d)
{
	d->img.player.x = d->img.tmap->px;
	d->img.player.y = d->img.tmap->py;
	d->img.player.walk_x = 0;
	d->img.player.walk_y = 0;
	d->img.player.nb_mvmt = 0;
	return (SUCCESS);
}

int	create_new_img(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, data->img.wid,
			data->img.hei);
	if (data->img.mlx_img == NULL)
	{
		ft_putstr_fd("Error\nCould not create a new image.\n", 2);
		return (FAILURE);
	}
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	return (SUCCESS);
}

int	ft_create_mlx_win_and_img(t_data *d, t_map *map)
{
	d->mlx_ptr = 0;
	d->win_ptr = 0;
	d->img.mlx_img = 0;
	d->img.wid = SCR_WID;
	d->img.hei = SCR_HEI;
	d->tex = 0;
	d->mlx_ptr = mlx_init();
	if (d->mlx_ptr == NULL)
	{
		ft_putstr_fd("Error\nCould not init mlx.\n", 2);
		return (FAILURE);
	}
	if (ft_import_xpm_file(d, map) == FAILURE)
	{
		ft_putstr_fd("Error\nCould not import xpm file.\n", 2);
		return (FAILURE);
	}
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->img.wid, d->img.hei,
			"SO_LONG");
	if (d->win_ptr == NULL)
	{
		ft_putstr_fd("Error\nCould not create a new window.\n", 2);
		return (FAILURE);
	}
	return (create_new_img(d));
}

int	ft_mlx(t_map *map)
{
	t_data	data;

	data.img.tmap = map;
	data.img.d = &data;
	if (ft_create_mlx_win_and_img(&data, map) == SUCCESS)
	{
		ft_setup_player(&data);
		ft_mlx_hook(&data);
		mlx_loop(data.mlx_ptr);
	}
	ft_clear_mlx(&data);
	return (SUCCESS);
}
