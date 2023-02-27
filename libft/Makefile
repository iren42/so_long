# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iren <iren@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/01 16:49:57 by iren              #+#    #+#              #
#    Updated: 2023/02/27 21:43:20 by iren             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
NAME1	= libft.so
HEADER	= libft.h
DIR_OBJ = obj/

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

SRCS	=	ft_strlcat.c \
			ft_atoi.c \
			ft_strlcpy.c \
			ft_bzero.c \
			ft_strlen.c \
			ft_calloc.c \
			ft_strmapi.c \
			ft_isalnum.c \
			ft_memccpy.c \
			ft_strncmp.c \
			ft_isalpha.c \
			ft_memchr.c \
			ft_strnstr.c \
			ft_isascii.c \
			ft_memcmp.c \
			ft_strrchr.c \
			ft_isdigit.c \
			ft_memcpy.c \
			ft_strtrim.c \
			ft_isprint.c \
			ft_memmove.c \
		 	ft_substr.c \
			ft_itoa.c \
			ft_memset.c \
			ft_tolower.c \
			ft_putchar_fd.c \
		   	ft_toupper.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
		   	ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c	\
			ft_strjoin.c 

SRCS_BONUS = ft_lstnew.c \
			 ft_lstadd_front.c \
			 ft_lstsize.c \
			 ft_lstlast.c \
			 ft_lstadd_back.c \
			 ft_lstdelone.c \
			 ft_lstclear.c \
			 ft_lstiter.c \
			 ft_lstmap.c

OBJS    = $(addprefix $(DIR_OBJ), $(SRCS:.c=.o))

OBJS_BONUS    = $(addprefix $(DIR_OBJ), $(SRCS_BONUS:.c=.o))


all		: $(NAME)

$(DIR_OBJ)%.o: %.c $(HEADER)
			@mkdir -p $(DIR_OBJ)
			$(CC) $(CFLAGS) -c $< -o $@

#so		:
#		$(CC) -c -fPIC $(CFLAGS) $(SRCS)
#	    gcc -shared -o $(NAME1) $(OBJS) $(OBJS_BONUS)

$(NAME) :  $(HEADER) $(OBJS) $(OBJS_BONUS)
		ar rc $(NAME) $(OBJS) $(OBJS_BONUS)
		ranlib $(NAME)


norm	:
		norminette $(SRCS)
		norminette $(SRCS_BONUS)
		norminette $(HEADER)

clean	:
		rm -rf $(DIR_OBJ)

fclean	: clean
		rm -f $(NAME) $(NAME1)

re		: fclean all

.PHONY:	all clean fclean re
