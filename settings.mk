ifndef SETTINGS_MK
	SETTINGS_MK := 1

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::TARGET::

NAME	=	cub3D

ifeq ($(MAKECMDGOALS), bonus)
NAME	=	
endif

UNAME	=	$(shell uname)

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SOURCE::

SRC		=	$(addprefix $Scontrols/, \
				camera.c \
				controls.c) \
			$(addprefix $Sdrawing/, \
				dda_algo.c \
				raycaster.c \
				texturizer.c) \
			$(addprefix $Sinit/, \
				main.c \
				main_free.c \
				main_init.c \
				utils.c \
				window_init.c) \
			$(addprefix $Sparsing/, \
				color_loader.c \
				map_converter.c \
				map_loader.c \
				map_parser.c \
				parser.c \
				parser_texture.c \
				parser_walls.c \
				texture_loader.c)

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COMPILERS::

CC		=	gcc

ifeq ($(UNAME), Darwin)
CC	=	clang
endif

CFLAGS	=	-Wall -Wextra -Werror

AR		=	ar

ARFLAGS	=	rcs

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::LIBRARY::

IS_LIB	= 	true

LIB		= 	$Llibft.a

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::FT_PRINTF::

IS_PTF	= 	false

PTF		= 	$Plibftprintf.a

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::MINILIBX::

IS_MLX	= 	true

MLX		= 	$Mlibmlx_$(UNAME).a

endif