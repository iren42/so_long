/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 20:34:01 by iren              #+#    #+#             */
/*   Updated: 2023/03/10 20:34:16 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clear_tex(t_data *data)
{
	int	i;

	i = -1;
	if (data->tex != 0)
	{
		while (++i < NB_TEX)
		{
			if (data->tex[i].mlx_img != 0)
			{
				mlx_destroy_image(data->mlx_ptr, data->tex[i].mlx_img);
				data->tex[i].mlx_img = 0;
			}
		}
		free(data->tex);
	}
}

void	ft_clear_mlx(t_data *data)
{
	if (data->img.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	clear_tex(data);
	if (data->mlx_ptr != 0)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}
