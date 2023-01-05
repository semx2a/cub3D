##
## Makefile for MiniLibX in /home/boulon/work/c/raytraceur/minilibx
## 
## Made by Olivier Crouzet
## Login   <ol@epitech.net>
## 
## Started on  Tue Oct  5 15:56:43 2004 Olivier Crouzet
## Last update Tue May 15 15:44:41 2007 Olivier Crouzet
##

## Please use configure script

BPURPLE		=	\033[1;35m
BGREEN		=	\033[1;92m

all	: h1 message do_configure

do_configure	:
	./configure

clean	:
	./configure clean
h1:
	@echo "\n$(BPURPLE)::::::::::::::::::::::::::::::::::::::::::::::::::MINILIBX::\n$(NO_COLOR)"
	
message:
	@make -q $(NAME) && echo "$(BGREEN)All files are already up to date$(NO_COLOR)" || true

re	: clean all

