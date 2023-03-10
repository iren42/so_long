/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 19:14:08 by iren              #+#    #+#             */
/*   Updated: 2023/03/10 20:37:42 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"

# define SUCCESS 1
# define FAILURE -1

# define TILE_SIZE 20
# define SCR_WID 1000
# define SCR_HEI 1000

# define NB_TEX 5

///////// LIBFT FUNCTIONS
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *s);

//////// ENUM
enum e_tex{wall, ground, collec, map_exit, player};

//////// STRUCT. Go to line 124 to skip
typedef struct s_var_spread_b
{
	int	rows;
	int	cols;
	int	exit_can_be_reached;
}	t_var_spread_b;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct s_map_comp
{
	int	nb_starting_points;
	int	nb_collec;
	int	nb_exits;
	int	player_x;
	int	player_y;

}	t_map_comp;

typedef struct s_player
{
	int		nb_mvmt;
	int		x;
	int		y;
	int		walk_x;
	int		walk_y;
}	t_player;

typedef struct s_map
{
	int			error;
	int			px;
	int			py;
	char		**map;
	char		**texture;
	int			rows;
	int			cols;
	t_map_comp	comp;
}	t_map;

typedef struct s_var_set_tmap
{
	t_list	*lst;
	char	*line;
	t_map	*tmap;
	int		ret;
	int		fd;
}	t_var_set_tmap;

typedef struct s_img {
	void			*mlx_img;
	int				wid;
	int				hei;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	t_player		player;
	t_map			*tmap;
	struct s_data	*d;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_img	*tex;
}	t_data;

//////// MAP PARSING FUNCTIONS
int		ft_init_tmap(t_map *map);
int		ft_parse_all(char *name, t_map *map);
int		ft_walls_are_good(t_map *tmap);
int		ft_map_has_necessary_components(t_map *tmap);
int		ft_has_valid_path(t_map *tmap);
int		ft_skip_spaces(char *s, int i);
void	ft_free_tmap(t_map *map);
int		ft_isspace(char c);
int		ft_is_player_char(char c);

//////// IN src/
int		ft_mlx(t_map *map);
void	ft_img_pix_put(t_img *img, int x, int y, int color);
int		ft_close(t_data *data);
char	**ft_copy_mapchar(char **map, int nb_rows, int nb_cols);
char	**ft_rotate_mapchar(char **map, int rows, int cols);
void	ft_free_mapchar(char **map);
void	ft_free_previously_malloced(char **tab, int i);
char	**ft_mirror(char **map, int rows, int cols);
int		ft_set_tmap(int fd, t_map *map);
int		ft_is_map_closed(t_map *map, int px, int py);
void	ft_msg(int nb, char *s, int fd);
void	ft_clear_mlx(t_data *d);

//////// MLX 2D MAP FUNCTIONS
void	ft_update(t_player *p);
int		ft_refresh_img(t_data *data);
void	ft_mlx_hook(t_data *data);
int		ft_map_has_wall_at(t_data *data, int x, int y);

////// MLX 3D MAP
int		ft_import_xpm_file(t_data *data, t_map *map);
int		ft_get_pix_color(t_img *img, int x, int y);

//// display things
void	affiche_str(void *c);
void	affiche_list(t_list *l);
void	ft_display_tmap_map(t_map map);
void	ft_display_tmap(t_map map);
void	ft_display_chararray(char **map);
void	ft_render_rays(t_data *data);
#endif
