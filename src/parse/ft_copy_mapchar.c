/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_mapchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 19:36:21 by iren              #+#    #+#             */
/*   Updated: 2023/03/21 17:04:09 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_copy_mapchar(char **map, int nb_rows, int nb_cols)
{
	char	**res;
	int		i;
	int		j;

	res = malloc(sizeof(char *) * (nb_rows + 1));
	if (res == NULL || map == 0 || nb_rows < 3 || nb_cols < 3)
		return (0);
	i = 0;
	while (i < nb_rows)
	{
		j = -1;
		res[i] = malloc(sizeof(char) * (nb_cols + 1));
		if (res[i] == NULL)
		{
			ft_free_previously_malloced(res, i);
			return (0);
		}
		while (++j < nb_cols && map[i][j] != '\0')
			res[i][j] = map[i][j];
		while (j < nb_cols)
			res[i][j++] = ' ';
		res[i++][nb_cols] = '\0';
	}
	res[i] = 0;
	return (res);
}
