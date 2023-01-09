#include "../inc/cub3d.h"

void	free_and_exit(void *ptr, char *err_msg)
{
	free(ptr);
	ft_error(ERR,  err_msg);
}

void	destroy(t_game *game)
{
	mlx_destroy_image(game->mlix, &game->wall);
	mlx_clear_window(game->mlix, &game->window);
	mlx_destroy_window(game->mlix, &game->window);
	mlx_destroy_display(game->mlix);
	game->window = NULL;
}
