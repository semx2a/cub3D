#ifndef CUB3D_H
# define CUB3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include "../libft/inc/libft.h"
# include "../minilibx/mlx.h"

# define MAX 50000
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define FOV				1.3/*1.1780972*/
# define MOVE_SPEED			0.08
# define ROT_SPEED			0.05

typedef struct s_check
{
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
	int				line_length;
	int				endian;
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
	unsigned int	**addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				line_height;
	int				width[4];
	int				height[4];
	unsigned int	**tex;
	int				tex_x;
	int				tex_y;
	float			wall_x;
	float			step;
}	t_tex;

typedef struct s_game
{
	char	**map;
	int		**mappi;
	void	*mlix;
	void	*window;
	int		res_x;
	int		res_y;
	float	pos_px;
	float	pos_py;
	float	direction;
	int		k_up;
	int		k_down;
	int		k_left;
	int		k_right;
	int		k_left_rot;
	int		k_right_rot; //rotation
	int		k_esc; //escape
	char	**textpath;
	int		floor_c;
	int		ceiling_c;
	t_rays	rays;
	t_tex	tex;
	t_wall	wall;
	t_check	check;

}	t_game;



int		ft_parcing(t_game *game, char *file);
int		ft_error(char *str);
int		ft_izmap(char *str);
int		ft_get_info(t_game *game, char *str);
int		ft_init(t_game *game);
int		ft_getcolors(t_game *game, char *str, int i);
int		ft_mapparcer(t_game *game, char **tab, int begining);
int		ft_replace_space(char **map, int i, unsigned long j);
int		ft_ismapclosed(char **map, int i, int j);
int		k_press(int keycode, t_game *game);
int		k_pop(int keycode, t_game *game);
int		k_exit(t_game *game);
void	ft_get_resolution(t_game *game);
void	ray_init(t_game *game);
void	ft_raycast(t_game *game);
int		load_texture(t_game *game);
void	ft_wall_size(t_game *game);
void	ft_print_texture(t_game *game, int x, int start, int end);
void	ft_put_pixels(t_game *game, int x, int y, unsigned int color);
int		get_texture(t_game *game);
void	ft_move(t_game *game);
#endif
