/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_img.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 23:10:16 by iren              #+#    #+#             */
/*   Updated: 2023/03/20 21:51:13 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	render_player(t_img *img, t_player p, t_img t)
{
	int		n;
	int		m;
	int		cl;
	float	tx;
	float	ty;

	n = p.y * TILE_SIZE;
	if (img != 0)
	{
		while (n < (p.y + 1) * TILE_SIZE)
		{
			m = p.x * TILE_SIZE;
			while (m < (p.x + 1) * TILE_SIZE)
			{
				tx = ((float)m) / TILE_SIZE * t.hei;
				ty = ((float)n) / TILE_SIZE * t.wid;
				cl = ft_get_pix_color(&t, ((int)tx) % t.hei, ((int)ty) % t.wid);
				if (ft_get_pix_color(img, m, n) != cl)
					ft_img_pix_put(img, m, n, cl);
				m++;
			}
			n++;
		}
	}
	return (0);
}

static int	render_tile(t_img *img, int j, int i, t_img t)
{
	int		n;
	int		m;
	int		cl;
	float	tx;
	float	ty;

	n = i * TILE_SIZE;
	if (img != 0)
	{
		while (n < (i + 1) * TILE_SIZE)
		{
			m = j * TILE_SIZE;
			while (m < (j + 1) * TILE_SIZE)
			{
				tx = ((float)m) / TILE_SIZE * t.hei;
				ty = ((float)n) / TILE_SIZE * t.wid;
				cl = ft_get_pix_color(&t, ((int)tx) % t.hei, ((int)ty) % t.wid);
				if (ft_get_pix_color(img, m, n) != cl)
					ft_img_pix_put(img, m, n, cl);
				m++;
			}
			n++;
		}
	}
	return (0);
}

static void	render_map(t_img *img)
{
	int	i;
	int	j;

	i = 0;
	if (img->tmap->map != NULL)
	{
		while (i < img->tmap->rows && i * TILE_SIZE < img->hei)
		{
			j = 0;
			while (j < img->tmap->cols && j * TILE_SIZE < img->wid)
			{
				if (img->tmap->map[i][j] == '1')
					render_tile(img, j, i, img->d->tex[wall]);
				else if (img->tmap->map[i][j] == 'E')
					render_tile(img, j, i, img->d->tex[map_exit]);
				else if (img->tmap->map[i][j] == 'C')
					render_tile(img, j, i, img->d->tex[collec]);
				else
					render_tile(img, j, i, img->d->tex[ground]);
				j++;
			}
			i++;
		}
	}
}

int	ft_refresh_img(t_data *d)
{
	if (d)
	{
		render_map(&d->img);
		render_player(&d->img, d->img.player, d->tex[player]);
		if (d->img.mlx_img != NULL && d->win_ptr != NULL && d->mlx_ptr != NULL)
			mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
				d->img.mlx_img, 0, 0);
	}
	return (0);
}
