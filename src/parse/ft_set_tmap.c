/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_tmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 00:22:45 by iren              #+#    #+#             */
/*   Updated: 2021/08/15 08:20:23 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_map_content(char *line)
{
	int	i;

	i = 0;
	if (line != NULL)
	{
		if (line[0] == '\0')
			return (0);
		while (line[i] != '\0')
		{
			if (ft_strchr("10CEP", line[i]) != NULL)
			{
				i++;
			}
			else
				return (0);
		}
		return (1);
	}
	return (0);
}

static int	convert_maplst_to_char(t_list *l, t_map *tmap)
{
	int	i;

	if (tmap->rows < 3 || tmap->cols < 3)
		return (FAILURE);
	tmap->map = malloc(sizeof(char *) * (tmap->rows + 1));
	if (tmap->map == NULL)
		return (FAILURE);
	i = 0;
	printf("convert rows %d cols %d\n", tmap->rows, tmap->cols);
	while (l)
	{
		tmap->map[i] = malloc(sizeof(char) * (tmap->cols + 1));
		if (tmap->map[i] == NULL || !is_map_content(l->content))
		{
			ft_free_previously_malloced(tmap->map, i);
			tmap->map = 0;
			return (FAILURE);
		}
		ft_bzero(tmap->map[i], tmap->cols + 1);
		ft_strlcpy(tmap->map[i], l->content, tmap->cols + 1);
		l = l->next;
		i++;
	}
	tmap->map[i] = 0;
	tmap->error = 0;
	return (SUCCESS);
}

static void	loop(t_var_set_tmap *t)
{
	while (t->ret > 0)
	{
		ft_lstadd_back(&t->lst, ft_lstnew(t->line));
		t->tmap->rows++;
		if (ft_strlen(t->line) > (unsigned int)t->tmap->cols)
			t->tmap->cols = ft_strlen(t->line);
		t->ret = get_next_line(t->fd, &t->line);
	}
	if (t->ret == 0)
	{
		ft_lstadd_back(&t->lst, ft_lstnew(t->line));
		t->tmap->rows++;
	}
}

int	ft_set_tmap(int fd, t_map *tmap)
{
	t_var_set_tmap	t;

	t.line = 0;
	t.lst = 0;
	t.ret = get_next_line(fd, &t.line);
	t.fd = fd;
	t.tmap = tmap;
	if (t.ret > 0)
	{
		loop(&t);
	}
	affiche_list(t.lst);
//	if (tmap->rows != tmap->cols)
		//free(t.line);
	if (convert_maplst_to_char(t.lst, tmap) == FAILURE)
		ft_putstr_fd("Error\nNo tmap. Error found in map content.\n", 2);
	ft_lstclear(&t.lst, &free);
	return (tmap->error);
}
