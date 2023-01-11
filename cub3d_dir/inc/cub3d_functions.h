#ifndef CUB3D_FUNCTIONS_H
# define CUB3D_FUNCTIONS_H

# include "cub3d.h"
# include "cub3d_data.h"

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::INIT::

//		window_init.c
void	window_init(t_game *game);
void	img_init(t_game *game);

//		main_init.c
int		game_init(t_game *game);

//		main_free.c
void	destroy_tex(t_game *game, size_t len);
void	free_game(t_game *game, char *err_msg, bool is_mlx, bool is_err);

//		utils.c
void	*ft_xcalloc(size_t count, size_t size);

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::PARSING::

//		parser.c
void	parser(t_game *game, char *file_path);

//		map_parser.c
void	map_parser(t_game *game);

//		parser_walls.c
void	check_walls(t_game *game);

//		parser_texture.c
void	load_paths(t_game *game);

//		colors_loader.c
int		get_colors(t_game *game, char *str);

//		map_loader.c
void	load_map(t_game *game);

//		map_loader.c
void	convert_map(t_game *game);

//		texture_loader.c
//int		get_texture(t_game *game);
void	load_texture(t_game *game);

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::CONTROLS::

//		contols.c
int		close_window(t_game *game);
void	controls_init(t_game *game);

//		move.c
void	cam_move(t_game *game);

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::DRAWING::

//		raycaster.c
int		render(t_game *game);

//		dda_algo.c
void	dda_algorithm(t_game *game);

//		texturizer.c
void	ft_print_texture(t_game *game, int x, int start, int end);

#endif
