/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:31:41 by iren              #+#    #+#             */
/*   Updated: 2023/03/20 21:45:06 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>

static void	update_player_values(t_data *data, t_player *p)
{
	int	new_px;
	int	new_py;

	if (p && data)
	{
		new_px = p->x;
		new_py = p->y;
		if (p->walk_x != 0)
			new_px = p->x + (p->walk_x * 1);
		else if (p->walk_y != 0)
			new_py = p->y + (p->walk_y * 1);
		if (!ft_map_has_wall_at(data, new_px, new_py))
		{
			p->x = new_px;
			p->y = new_py;
		}
	}
}

static int	handle_keyrelease(int keysym, t_data *data)
{
	if (data)
	{
		if (keysym == XK_w || keysym == XK_s
			|| keysym == XK_W || keysym == XK_S)
			data->img.player.walk_y = 0;
		if (keysym == XK_A || keysym == XK_a
			|| keysym == XK_D || keysym == XK_d)
			data->img.player.walk_x = 0;
	}
	return (0);
}

static int	handle_keypress(int key, t_data *data)
{
	if (data)
	{
		if (key == XK_Escape)
		{
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			data->win_ptr = NULL;
		}
		else if (key == XK_a || key == XK_d || key == XK_w || key == XK_s
			|| key == XK_A || key == XK_D || key == XK_W || key == XK_S)
		{
			if (key == XK_a)
				data->img.player.walk_x = -1;
			else if (key == XK_d)
				data->img.player.walk_x = 1;
			else if (key == XK_w)
				data->img.player.walk_y = -1;
			else
				data->img.player.walk_y = 1;
			update_player_values(data, &(data->img.player));
		}
	}
	return (0);
}

void	ft_mlx_hook(t_data *data)
{
	if (data != NULL)
	{
		mlx_loop_hook(data->mlx_ptr, &ft_refresh_img, data);
		mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keypress, data);
		mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask,
			&handle_keyrelease, data);
		mlx_hook(data->win_ptr, 33, 1L << 2, &ft_close, data);
	}
}
