/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pix_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 08:06:02 by iren              #+#    #+#             */
/*   Updated: 2023/02/25 18:17:56 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_pix_color(t_img *img, int x, int y)
{
	int	a;

	a = 0x0;
	if (img != 0)
	{
		if (x >= 0 && x < img->wid && y >= 0 && y <= img->hei && img->addr != 0)
			a = *(int *)(img->addr + (x + y * img->wid) * img->bpp / 8);
	}
	return (a);
}
