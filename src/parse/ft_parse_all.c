/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:18:44 by iren              #+#    #+#             */
/*   Updated: 2023/03/10 22:10:26 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "so_long.h"

static int	ft_is_filename_valid(char *name)
{
	char	*ptr;
	char	*filename;

	if (name != 0)
	{
		filename = ft_strrchr(name, '/');
		if (filename != NULL)
		{
			if (ft_strlen(filename) < 5)
				return (FAILURE);
			ptr = ft_strrchr(++filename, '.');
			if (ptr == NULL)
				return (FAILURE);
			if (*filename == '.' && ft_strchr(filename, '.') == ptr)
				return (FAILURE);
			if (ft_strncmp(ptr, ".ber", 5) == 0)
				return (SUCCESS);
		}
	}
	return (FAILURE);
}

static int	ft_is_map_valid(t_map *map)
{
	if (!ft_walls_are_good(map))
		return (ft_msg(-1, "Invalid walls", 2, FAILURE));
	if (!ft_map_has_necessary_components(map))
		return (ft_msg(-1, "Invalid number of components", 2, FAILURE));
	if (!ft_has_valid_path(map))
		return (ft_msg(-1, "Invalid path", 2, FAILURE));
	return (1);
}

static int	ft_open_close_fd(char *name, int *fd, t_map *map)
{
	*fd = open(name, O_RDWR);
	if (*fd < 0 && errno == EISDIR)
		return (ft_msg(-1, "This is directory", 2, FAILURE));
	*fd = open(name, O_RDONLY);
	if (*fd < 0)
		return (ft_msg(-1, "Could not open file", 2, FAILURE));
	if (ft_set_tmap(*fd, map) != 0)
		return (ft_msg(-1, "Function ft_set_tmap failed.", 2, FAILURE));
	if (close(*fd) < 0)
		return (ft_msg(-1, "File could not close", 2, FAILURE));
	return (SUCCESS);
}

int	ft_parse_all(char *name, t_map *tmap)
{
	int	fd;

	fd = 0;
	if (ft_is_filename_valid(name) == FAILURE)
		return (ft_msg(-1, "Invalid filename", 2, FAILURE));
	if (ft_open_close_fd(name, &fd, tmap) == FAILURE)
		return (FAILURE);
	if (ft_is_map_valid(tmap) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
