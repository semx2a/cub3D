#include "../../inc/cub3d.h"

void	ft_new_image(t_game *game)
{
	game->wall.img = mlx_new_image(game->mlix, game->res_x, game->res_y);
	if (!game->wall.img)
		free_and_exit(game->wall.img, ERR_IMG);
	game->wall.addr = (unsigned int *)mlx_get_data_addr(game->wall.img,
			&game->wall.bpp, &game->wall.line_length, &game->wall.endian);
}

void	ft_get_resolution(t_game *game)
{
	game->res_x = 800;
	game->res_y = 600;
}
