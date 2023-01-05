# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonard <abonard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/08 19:48:37 by abonard           #+#    #+#              #
#    Updated: 2023/01/05 16:39:49 by abonard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NC = \033[0m
RED = \033[0;91m
ORANGE = \033[93m
GREEN = \033[0;92m
PURPLE = \033[0;95m
BLUE = \033[0;34m
BOLD = \033[1m

SRCS		=	./srcs/main.c \
				./srcs/ft_parcing.c \
				./srcs/ft_parcing_utils.c \
				./srcs/ft_init.c \
				./srcs/ft_getcolors.c \
				./srcs/ft_mapparcer.c \
				./srcs/ft_mapparcer_utils.c \
				./srcs/ft_keycodes.c \
				./srcs/ft_general_utils.c \
				./srcs/ft_raycast.c \
				./srcs/ft_texture.c \
				./srcs/ft_get_texture.c \
				./srcs/ft_move.c


INCLUDES	=	./libft/inc/libft.h \
				./inc/cub3d.h \

HEAD		= ./inc/

MLX 		= minilibx-linux/libmlx_Linux.a

MLX_DIR		= ./minilibx-linux/

LIBFT		= ./libft/libft.a

LIB_DIR		= ./libft/

NAME		= cub3d

CC			= clang

OBJS		= ${SRCS:.c=.o}

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -g

LFLAGS		= -lm -lX11 -lXext -lbsd

#LINK		= -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext

.c.o:
		@${CC} ${CFLAGS} -I${HEAD} -c $< -o ${<:.c=.o}
		@echo "${GREEN}[ OK ]	${ORANGE}${<:.s=.o}${NC}"

all:		${NAME}

${NAME}:	${OBJS}
			@make -C ${LIB_DIR}
			@make -C ${MLX_DIR}
			@echo "${GREEN}\nlibft.a		has been created"
			@echo "${GREEN}\nlibmlx_Linux.a	has been created"
			@${CC} ${CFLAGS} ${LFLAGS} -I${HEAD} -o ${NAME} $(OBJS) ${LIBFT} ${MLX}
			@echo "cub3d		has been created\n${NC}"

clean:
			@make -C $(LIB_DIR) clean
			@make -C ${MLX_DIR} clean
			@${RM} ${OBJS}
			@echo "${GREEN}[ OK ]${RED}	*.o files	deleted${NC}"

fclean:		clean
			@make -C $(LIB_DIR) fclean
			@echo "${GREEN}[ OK ]${RED}	libft.a		deleted${NC}"
			@${RM} ${NAME}
			@echo "${GREEN}[ OK ]${RED}everything	deleted${NC}"

re :		fclean all

.PHONY:		all	clean	fclean re