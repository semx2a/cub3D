#ifndef CUB3D_MACROS_H
# define CUB3D_MACROS_H

# include "cub3d.h"

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::PROJECT::

# define BIN_NAME		"cub3d"
# define ERR			"Error\n"
# define ERR_MALLOC		"Memory Allocation failed"
# define ERR_COPY		"Content copy failed"
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::MINILIBX::

# define ERR_IMG		"Image generation failed"
# define ERR_MLXINIT	"Minilibx initialization failed"
# define ERR_WINX		"Window generation failed"
# define ERR_MLXPM		"Minilibx XPM to IMG failed"
# define ERR_MLXMEM		"Minilibx failed to alloc address"

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::PARSING::

// FILE
# define ERR_ICHAR		"Invalid character found"
# define ERR_PSPACE		"Space missing before texture path"

//	TEXTURE
# define ERR_TEXLOAD	"Texture load failed"
# define ERR_TEXVIEW	"Only one texture is allowed for each direction"

// COLORS
# define ERR_COLORS		"RGB format: R,G,B"
# define ERR_RGB		"RGB values: Select between 0 & 255"
# define ERR_RGBLEN		"RGB values: Select one value per color"
# define ERR_RGBVIEW	"Only one color is allowed for the floor or ceiling"

// MAP
# define ERR_MAPALLOC	"Map allocation failed"
# define ERR_PLAYER		"Wrong number of players"
# define ERR_IMAP		"Invalid map"
# define ERR_MSPACE		"Space found in map"
# define ERR_MCLOSE		"Map has an open wall"
# define ERR_MTOP		"Map is open on the top"
# define ERR_MBOTTOM	"Map is open on the bottom"

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::KEYCODES::

# define MAX 				1024
# define KEY_A 				97
# define KEY_D 				100
# define KEY_S 				115
# define KEY_W 				119
# define KEY_LEFT 			65361
# define KEY_RIGHT 			65363
# define KEY_ESC 			65307

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::MATH::

# define FOV				1.3/*1.1780972*/
# define MOVE_SPEED			0.08
# define ROT_SPEED			0.05

//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::WINDOW::

# define HEIGHT				1200
# define WIDTH				1500


#endif