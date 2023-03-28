/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_pix_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 14:01:24 by iren              #+#    #+#             */
/*   Updated: 2023/03/20 20:40:43 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	line_len is the amount of bytes taken by one row of our image.
	It is equivalent to img->wid * (img->bpp / 8)
*/

void	ft_img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (img != 0)
	{
		i = img->bpp - 8;
		if (img->addr != 0)
		{
			pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
			while (i >= 0)
			{
				if (img->endian != 0)
					*pixel++ = (color >> i) & 0xFF;
				else
					*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
				i -= 8;
			}
		}
	}
}
