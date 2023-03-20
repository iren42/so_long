# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iren <iren@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 17:41:07 by iren              #+#    #+#              #
#    Updated: 2023/03/10 20:33:39 by iren             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

LIBFT	= libft

MLX		= mlx_linux

HEADER	= include/so_long.h

HEADER1	= include/get_next_line.h

DIR_SOURCES	= src/

DIR_OBJ	= obj/

DIR_PARSE = parse/

DIR_2DMAP = 2dmap/

DIR_3DMAP	= 3dmap/

SOURCES_PARSE	=	ft_parse_all.c \
					get_next_line.c \
					get_next_line_utils.c \
					ft_free_previously_malloced.c \
					ft_set_tmap.c \
					ft_is_player_char.c \
					ft_copy_mapchar.c \
					ft_free_mapchar.c  \
					ft_walls_are_good.c \
					ft_map_has_necessary_components.c \
					ft_has_valid_path.c 
			#		ft_display_things.c

SOURCES_2DMAP	=	ft_map_has_wall_at.c 

SOURCES_3DMAP	=	ft_get_pix_color.c 

SOURCES		=	main.c \
				ft_init_tmap.c \
				ft_free_tmap.c \
				ft_mlx.c \
				ft_clear_mlx.c \
				ft_import_xpm_file.c \
				ft_close.c \
				ft_mlx_hook.c \
				ft_img_pix_put.c \
				ft_refresh_img.c \
				ft_msg.c \
				$(addprefix $(DIR_2DMAP), $(SOURCES_2DMAP)) \
				$(addprefix $(DIR_3DMAP), $(SOURCES_3DMAP)) \
				$(addprefix $(DIR_PARSE), $(SOURCES_PARSE))

SRCS	=	$(addprefix $(DIR_SOURCES), $(SOURCES))

OBJS	= $(SRCS:.c=.o)

CC		= gcc

CFLAGS	=  -Wall -Wextra -Werror 

RM		= rm -f

all		: $(NAME)

%.o		: %.c $(HEADER)
		$(CC) $(CFLAGS) -Iinclude -Imlx_linux -c $< -o $@

$(NAME) : $(OBJS) $(HEADER) $(MLX) $(LIBFT)
		make -C $(MLX)
		make -C $(LIBFT)
		$(CC) $(CFLAGS) -o $@ $(OBJS) -Llibft -lft -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm

clean	:
		$(RM) $(OBJS)
		make clean -C $(LIBFT)
		make clean -C $(MLX)

fclean	: clean
		make fclean -C $(LIBFT)
		$(RM) $(NAME)

re		: fclean all

.PHONY:	all clean fclean re
