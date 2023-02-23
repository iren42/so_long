/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_things.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 19:36:58 by iren              #+#    #+#             */
/*   Updated: 2021/08/14 14:33:47 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	affiche_str(void *c)
{
	static int	i = 0;

	printf("L %d:\t\t%s\n", i++, (char *) c);
}

void	affiche_list(t_list *l)
{
	printf("\nLIST BEGIN-----\n");
	if (l != 0)
		ft_lstiter(l, &affiche_str);
	printf("END-----\n");
}

void	ft_display_tmap(t_map map)
{
	if (map.map != 0)
	{
		printf("wall = %s\n", map.texture[wall]);
		printf("ground = %s\n", map.texture[ground]);
		printf("collec = %s\n", map.texture[collec]);
		printf("exit = %s\n", map.texture[map_exit]);
		printf("player = %s\n", map.texture[player]);
		printf("error = %d\n", map.error);
	}
}

void	ft_display_tmap_map(t_map map)
{
	int	i;

	i = 0;
	if (map.map != 0)
	{
		while (map.map[i] != 0)
		{
			printf("%s\n", map.map[i]);
			i++;
		}
	}
}

void	ft_display_chararray(char **map)
{
	int	i;

	i = 0;
	if (map != 0)
	{
		while (map[i] != 0)
		{
			printf("%s\n", map[i]);
			i++;
		}
	}
}
