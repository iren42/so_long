/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import_xpm_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:01:04 by iren              #+#    #+#             */
/*   Updated: 2023/03/10 20:43:08 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init(int *i, int *wid, int *hei, t_data *data)
{
	*i = -1;
	*wid = 0;
	*hei = 0;
	data->tex = malloc(sizeof(t_img) * NB_TEX);
	if (data->tex == NULL)
		return (FAILURE);
	while (++(*i) < NB_TEX)
	{
		data->tex[*i].mlx_img = 0;
	}
	*i = -1;
	return (SUCCESS);
}

static int	free_previous(t_data *data, int i)
{
	if (data != 0)
	{
		while (i >= 0)
		{
			mlx_destroy_image(data->mlx_ptr, data->tex[i].mlx_img);
			data->tex[i].mlx_img = 0;
			i--;
		}
		free(data->tex);
		data->tex = 0;
	}
	return (FAILURE);
}

int	ft_import_xpm_file(t_data *data, t_map *map)
{
	int		wid;
	int		hei;
	int		i;
	char	*filename;

	if (init(&i, &wid, &hei, data) == SUCCESS)
	{
		while (++i < NB_TEX)
		{
			filename = map->texture[i];
			data->tex[i].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
					filename, &wid, &hei);
			if (data->tex[i].mlx_img == NULL)
				return (free_previous(data, i));
			data->tex[i].addr = mlx_get_data_addr(data->tex[i].mlx_img,
					&data->tex[i].bpp,
					&data->tex[i].line_len, &data->tex[i].endian);
			data->tex[i].hei = hei;
			data->tex[i].wid = wid;
		}
		return (SUCCESS);
	}
	return (FAILURE);
}
