/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import_xpm_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:01:04 by iren              #+#    #+#             */
/*   Updated: 2023/02/25 19:24:43 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init(int *i, int *wid, int *hei, t_data *data)
{
	*i = -1;
	*wid = 0;
	*hei = 0;
	data->tex = malloc(sizeof(t_img) * NB_TEX);
	if (data->tex != NULL)
	{
		while (++(*i) < NB_TEX)
			data->tex[*i].mlx_img = 0;
	}
	*i = -1;
}

int	ft_import_xpm_file(t_data *data, t_map *map)
{
	int		wid;
	int		hei;
	int		i;
	char	*filename;

	init(&i, &wid, &hei, data);
	if (data->tex != NULL)
	{
		while (++i < NB_TEX)
		{
			filename = map->texture[i];
			data->tex[i].mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
					filename, &wid, &hei);
			if (data->tex[i].mlx_img == NULL)
				return (FAILURE);
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
