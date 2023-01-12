#include "../../inc/cub3d.h"

void	img_init(t_game *game)
{
	game->wall.img = mlx_new_image(game->mlx, game->res_x, game->res_y);
	if (!game->wall.img)
		free_game(game, ERR_IMG, true, true);
	game->wall.addr = (unsigned int *)mlx_get_data_addr(game->wall.img,
			&game->wall.bpp, &game->wall.line_length, &game->wall.endian);
	if (!game->wall.addr)
		free_game(game, ERR_IMG, true, true);
}

void	window_init(t_game *game)
{	
	game->res_x = 1500;
	game->res_y = 1200;
	game->mlx = mlx_init();
	if (!game->mlx)
		free_game(game, ERR_MLXINIT, true, true);
	game->win = mlx_new_window(game->mlx, game->res_x, game->res_y, BIN_NAME);
	if (!game->win)
		free_game(game, ERR_WINX, true, true);
}
