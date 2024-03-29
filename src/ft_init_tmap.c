/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 22:14:11 by iren              #+#    #+#             */
/*   Updated: 2023/03/20 21:49:46 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_free_tex(char **str)
{
	int	i;

	i = NB_TEX;
	if (str)
	{
		while (--i >= 0)
		{
			free(str[i]);
			str[i] = 0;
		}
		free(str);
		str = 0;
	}
}

static int	test_allocs(t_map *tmap)
{
	int	i;

	i = NB_TEX - 1;
	if (tmap)
	{
		while (i >= 0)
		{
			if (tmap->texture[i] == NULL)
			{
				ft_free_tex(tmap->texture);
				return (FAILURE);
			}
			else
				i--;
		}
		return (SUCCESS);
	}
	return (FAILURE);
}

int	ft_init_tmap(t_map *tmap)
{
	int	i;

	i = -1;
	if (tmap)
	{
		tmap->error = 1;
		tmap->map = 0;
		tmap->rows = 0;
		tmap->cols = 0;
		tmap->texture = malloc(sizeof(char *) * NB_TEX);
		if (tmap->texture != NULL)
		{
			while (++i < NB_TEX)
				tmap->texture[i] = 0;
			tmap->texture[wall] = ft_strdup("./texture/eagle.xpm");
			tmap->texture[ground] = ft_strdup("./texture/wood.xpm");
			tmap->texture[collec] = ft_strdup("./texture/elixir.xpm");
			tmap->texture[map_exit] = ft_strdup("./texture/door.xpm");
			tmap->texture[player] = ft_strdup("./texture/sans_player.xpm");
		}
	}
	return (test_allocs(tmap));
}
