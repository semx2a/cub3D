#ifndef CUB3D_DATA_H
# define CUB3D_DATA_H

# include "cub3d.h"

typedef struct s_check
{
	int	total;
	int	no;
	int	so;
	int	ea;
	int	we;
	int	f;
	int	c;
}	t_check;

typedef struct s_rays
{
	float			cam_x;
	float			ray_dir_x;
	float			ray_dir_y;
	float			dir_x;
	float			dir_y;
	float			plane_x;
	float			plane_y;
	float			delta_dist_x;
	float			delta_dist_y;
	float			step_x;
	float			step_y;
	float			side_dist_x;
	float			side_dist_y;
	float			perp_wall_dist;
	float			map_x;
	float			map_y;
	int				side;
}	t_rays;

typedef struct s_wall
{
	void			*img;
	unsigned int	*addr;
	int				bpp;
	int				endian;
	int				line_length;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				color;
	int				ceil_color;
	int				floor_color;
}	t_wall;

typedef struct s_tex
{
	void			**img;
	unsigned int	**tex;
	unsigned int	**addr;
	int				bpp;
	int				endian;
	int				line_length;
	int				line_height;
	int				width[4];
	int				height[4];
	int				tex_x;
	int				tex_y;
	float			wall_x;
	float			step;
}	t_tex;

typedef struct s_keys
{
	int		k_up;
	int		k_down;
	int		k_left;
	int		k_right;
	int		k_left_rot;
	int		k_right_rot;
	int		k_esc;
}	t_keys;

typedef struct s_game
{
	char	**filecp;
	char	**map;
	char	**path;
	int		**mappi;
	int		rgb[3];
	size_t	tablen;
	size_t	filelen;
	void	*mlx;
	void	*win;
	float	direction;
	float	pos_px;
	float	pos_py;	
	int		floor_c;
	int		ceiling_c;
	t_keys	keys;
	t_rays	rays;
	t_tex	tex;
	t_wall	wall;
	t_check	check;

}	t_game;

#endif
