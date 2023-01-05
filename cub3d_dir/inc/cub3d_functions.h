#ifndef CUB3D_FUNCTIONS_H
# define CUB3D_FUNCTIONS_H

# include "cub3d.h"
# include "cub3d_data.h"

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::INIT::

//		main.c
int		ft_error(char *str);

//		ft_general utils.c
void	ft_get_resolution(t_game *game);

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::PARSING::

//		ft_parcing.c
int		ft_parcing(t_game *game, char *file);

//		ft_init.c
int		ft_init(t_game *game);

//		ft_parcing_utils.c
int		ft_izmap(char *str);
int		ft_get_info(t_game *game, char *str);

//		ft_getcolors.c
int		ft_getcolors(t_game *game, char *str, int i);

//		ft_mapparcer.c
int		ft_mapparcer(t_game *game, char **tab, int begining);

//		ft_mapparcer_utils.c
int		ft_replace_space(char **map, int i, unsigned long j);
int		ft_ismapclosed(char **map, int i, int j);

//		ft_init.c
int		load_texture(t_game *game);
void	ray_init(t_game *game);

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::CONTROLS::

//		ft_keycodes.c
int		k_press(int keycode, t_game *game);
int		k_pop(int keycode, t_game *game);
int		k_exit(t_game *game);

//		ft_move.c
void	ft_move(t_game *game);

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::DRAWING::

//		ft_raycast.c
void	ft_raycast(t_game *game);

//		ft_texture.c
void	ft_wall_size(t_game *game);
void	ft_print_texture(t_game *game, int x, int start, int end);
void	ft_put_pixels(t_game *game, int x, int y, unsigned int color);

//		ft_get_texture.c
int		get_texture(t_game *game);

#endif
