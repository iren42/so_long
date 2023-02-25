/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_valid_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 17:42:39 by iren              #+#    #+#             */
/*   Updated: 2023/02/25 17:42:42 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_init_var(t_var_spread_b *var, int rows, int cols)
{
	var->rows = rows;
	var->cols = cols;
	var->exit_can_be_reached = 0;
}

static void	ft_spread_b(char **map, t_var_spread_b *var, int x, int y)
{
	if (y >= 0 && y <= var->rows - 1 && x >= 0 && x <= var->cols - 1)
	{
		if (ft_strchr("0PEC", map[y][x]) != NULL)
		{
			if (map[y][x] == 'E')
			{
				var->exit_can_be_reached = 1;
				return ;
			}
			map[y][x] = 'b';
			ft_spread_b(map, var, x + 1, y);
			ft_spread_b(map, var, x - 1, y);
			ft_spread_b(map, var, x, y + 1);
			ft_spread_b(map, var, x, y - 1);
		}
	}
}

int	ft_has_valid_path(t_map *tmap)
{
	t_var_spread_b	var;
	char			**cp;

	ft_init_var(&var, tmap->rows, tmap->cols);
	cp = ft_copy_mapchar(tmap->map, tmap->rows, tmap->cols);
	ft_spread_b(cp, &var, tmap->px, tmap->py);
	ft_free_mapchar(cp);
	return (var.exit_can_be_reached);
}
