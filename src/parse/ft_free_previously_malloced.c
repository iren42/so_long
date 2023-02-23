/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_previously_malloced.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 23:25:22 by iren              #+#    #+#             */
/*   Updated: 2021/08/14 10:13:25 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_previously_malloced(char **t, int i)
{
	if (t != 0)
	{
		while (i >= 0)
			free(t[i--]);
		free(t);
		t = 0;
	}
}
