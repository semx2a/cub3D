# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 19:14:12 by seozcan           #+#    #+#              #
#    Updated: 2023/01/12 17:49:49 by seozcan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::PATHS::

PROJ	:=	cub3d_dir

ODIR	:=	$(addprefix $(PROJ)/,objs)

SDIR	:=	$(addprefix $(PROJ)/,srcs)

IDIR	:=	$(addprefix $(PROJ)/,inc)

BODIR	:=	$(addprefix $(PROJ)/,objs_bonus)

BDIR	:=	$(addprefix $(PROJ)/,bonus)

LDIR 	:=	libft

PFDIR	:=	ft_printf

MDIR	:=	minilibx

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::TARGET::

NAME	:=	cub3d

BNAME	:=	cub3d_bonus

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::SOURCES::

SRCS	:=	controls.c \
			camera.c \
			dda_algo.c \
			raycaster.c \
			texturizer.c \
			main.c \
			main_free.c \
			main_init.c \
			utils.c \
			window_init.c \
			color_loader.c \
			map_converter.c \
			map_loader.c \
			map_parser.c \
			parser_texture.c \
			parser_walls.c \
			parser.c \
			texture_loader.c

OBJS	=	$(addprefix $(ODIR)/, $(SRCS:.c=.o))

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::BONUS::

BSRCS	:= 

BOBJS	=	$(addprefix $(BODIR)/,$(BSRCS:.c=.o))

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COMPILERS::

CC		:=	clang

WFLAGS	:=	-MMD -Wall -Wextra -Werror

WCONV	:=	-Wconversion

GFLAG	:=	-g3

SANFLAG	:=	-fsanitize=address

AR		:=	ar

ARFLAGS	:=	rcs

XFLAGS	:=	-lXext -lX11

MFLAG	:=	-lm

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::HEADERS::

LINC	=	$(addprefix $(LDIR)/,inc)

PFINC	=	$(addprefix $(PFDIR)/,inc))

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::LIBRARY::

IS_LIBFT	:=	true

LIB			:=	libft.a

LIBTF_PATH	=	$(addprefix $(LDIR)/, ${LIB})

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::FT_PRINTF::

IS_PRINTF	:=	false

PRINTF		:=	libftprintf.a

PRINTF_PATH	=	$(addprefix $(PFDIR)/, $(PRINTF))

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::MINILIBX::

IS_MINILIBX	:=	true

MLX			:=	libmlx_$(shell uname).a

MLX_PATH	=	$(addprefix $(MDIR)/, ${MLX})

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::COLORS::

NO_COLOR		=	\033[m

BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE 		 	=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
WHITE			= 	\033[0;37m

# High Intensty
HIGREEN			=	\033[0;92m
HIORANGE	 	=	\033[0;93m
HIPURPLE		=	\033[0;95m

# Bold
BORANGE 		=	\033[1;33m
BBLUE			=	\033[1;34m
BPURPLE			=	\033[1;35m
BCYAN			=	\033[1;36m

# Bold High Intensity
BHIGREEN		=	\033[1;92m
BHIORANGE	 	=	\033[1;93m
BHIPURPLE		=	\033[1;95m

# Italic
ICYAN			=	\033[3;36m

# ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::PARAMS::

INCLUDE_FLAGS		=	$(addprefix -I , $(IDIR))

ifeq ($(IS_LIBFT),true)
	INCLUDE_FLAGS	+=	$(addprefix -I , $(LINC))
endif

ifeq ($(IS_PRINTF), true)
	INCLUDE_FLAGS	+= $(addprefix -I , $(PFINC))
endif

ifeq ($(IS_MINILIBX), true)
	INCLUDE_FLAGS	+= $(addprefix -I , $(MDIR))
endif

DEPS				= $(OBJS:.o=.d)
BDEPS				= $(BOBJS:.o=.d)

vpath %.c $(SDIR)\
		$(BDIR)\
		$(addprefix $(SDIR)/,parsing)\
		$(addprefix $(SDIR)/,controls)\
		$(addprefix $(SDIR)/,drawing)\
		$(addprefix $(SDIR)/,init)
vpath %.o $(ODIR)\
		$(BODIR)

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::MANDATORY::

all:			header lib h2 message $(NAME)

$(ODIR)/%.o:	%.c 
	@$(CC) $(WFLAGS) $(GFLAG) $(SANFLAG) $(INCLUDE_FLAGS) -c $< -o $@ 
	@echo "$(HIGREEN)compilation:\t\t\t\t\t\t[OK]$(NO_COLOR)"

$(NAME):		$(OBJS)	
	@$(CC) $(WFLAGS) $(GFLAG) $(SANFLAG) $(OBJS) $(LIBTF_PATH) $(MLX_PATH) $(XFLAGS) $(MFLAG) -o $(NAME)
	@echo "$(HIGREEN)mandatory exe:\t\t\t\t\t\t[OK]$(NO_COLOR)"

$(OBJS):		| $(ODIR)

$(ODIR):
	@mkdir -p $(ODIR)
	@echo "$(HIGREEN)objs folder:\t\t\t\t\t\t[OK]$(NO_COLOR)"

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::BONUS::

bonus:			header lib h3 message_b $(BNAME)

$(BODIR)/%.o:	%.c 
	@$(CC) $(WFLAGS) $(SANFLAG) $(INCLUDE_FLAGS) -c $< -o $@ 
	@echo "$(HIGREEN)bonus compilation:\t\t\t\t\t[OK]$(NO_COLOR)"

$(BNAME):		$(BOBJS)
	@$(CC) $(GFLAGS) $(SANFLAG) $(BOBJS) $(LIBTF_PATH) $(MLX_PATH) $(XFLAGS) $(MFLAG) -o $(BNAME)
	@echo "$(HIGREEN)bonus exe:\t\t\t\t\t\t[OK]$(NO_COLOR)"

$(BOBJS):		| $(BODIR)

$(BODIR):
	@mkdir -p $(BODIR)
	@echo "$(HIGREEN)objs_bonus folder:\t\t\t\t\t[OK]$(NO_COLOR)"

# :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::RULES::

update:		header fclean
	@git pull

push:		header fclean fcleanlib
	@echo "$(HIGREEN)"
	@git add .
	@git commit --quiet
	@git push --quiet
	@echo "$(HIGREEN)git push:\t\t\t\t\t\t[OK]$(NO_COLOR)"

clean:		header
	@rm -rf $(ODIR)
	@echo "$(HIORANGE)objs folder:\t\t\t\t\t\t[RM]$(NO_COLOR)"

fclean:		header clean
	@rm -f $(NAME)
	@echo "$(HIORANGE)$(NAME) bin:\t\t\t\t\t\t[RM]$(NO_COLOR)"

lib:
ifeq ($(IS_LIBFT),true)
	@make -C $(LDIR) --quiet
endif
ifeq ($(IS_PRINTF),true)
	@make -C $(PFDIR) --quiet
endif
ifeq ($(IS_MINILIBX),true)
	@make -C $(MDIR) --quiet 
endif

relib:	header
ifeq ($(IS_LIBFT),true)
	@make -C $(LDIR) --quiet re
endif
ifeq ($(IS_PRINTF),true)
	@make -C $(PFDIR) --quiet re
endif
ifeq ($(IS_MINILIBX),true)
	@make -C $(MDIR) --quiet re
endif

fcleanlib:	header
ifeq ($(IS_LIBFT),true)
	@make -C $(LDIR) --quiet fclean
endif
ifeq ($(IS_PRINTF),true)
	@make -C $(PFDIR) --quiet fclean
endif
ifeq ($(IS_MINILIBX),true)
	@make -C $(MDIR) --quiet clean
endif

header:
	@echo "$(BHIPURPLE)"
	@echo "   ______________________________________________________"
	@echo "  /\     __________    ________    ___   ___    _______  \ "
	@echo " /  \   /\         \  /\   __  \  /\  \ /\  \  /\  ____\  \ "
	@echo "/    \  \ \  \ _/\  \ \ \   __  \ \ \  \ /_ /_ \ \  _\_/_  \ "
	@echo "\     \  \ \__\_/ \__\ \ \__\-\__\ \ \__\  \__\ \ \______\  \ "
	@echo " \     \  \/__/  \/__/  \/__/ /__/  \/__/ \/__/  \/______/   \ "
	@echo "  \     \_____________________________________________________\ "
	@echo "   \    /                                                     / "
	@echo "    \  /         $(CYAN) A B O N A R D  &&  S E O Z C A N \$(NO_COLOR)$(BHIPURPLE)   ____   / "
	@echo "     \/______________________________________________/\   \_/ "
	@echo "                                                     \ \___\ "
	@echo "                                                      \/___/ "
	@echo "$(NO_COLOR)"

h2:
	@echo "\n$(BHIPURPLE):::::::::::::::::::::::::::::::::::::::::::::::::::::CUB3D::\n$(NO_COLOR)"

message:
	@make -q $(NAME) && echo "$(BHIGREEN)All files are already up to date$(NO_COLOR)" || true

message_b:
	@make -q $(BNAME) && echo "$(BHIGREEN)All bonus files are already up to date$(NO_COLOR)" || true

re:		header fclean fcleanlib 
	@make all 

-include $(DEPS)

.PHONY:	all bonus clean fclean re push update o_dir h1 h2 header 
