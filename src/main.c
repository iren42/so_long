/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:46:11 by iren              #+#    #+#             */
/*   Updated: 2023/02/25 19:16:00 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac < 2 || ac > 2)
	{
		ft_putstr_fd("Error\nNeed one argument.\n", 2);
		return (1);
	}
	if (ac == 2)
	{
		if (ft_init_tmap(&map) == SUCCESS)
		{
			if (ft_parse_all(av[1], &map) == SUCCESS)
			{
				if (ft_mlx(&map) == SUCCESS)
					ft_putstr_fd("MLX went well\n", 1);
			}
			ft_free_tmap(&map);
		}
	}
	return (0);
}
