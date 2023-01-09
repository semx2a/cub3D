#include "../inc/cub3d.h"

void	ft_destroy_img(t_game *game)
{
	if (game->wall.img != NULL)
	{
		mlx_destroy_image(game->mlix, game->wall.img);
		game->wall.img = NULL;
	}
}

int	play_game(t_game *game)
{
	ft_destroy_img(game);
	ft_new_image(game);
	ft_move(game);
	ft_raycast(game);
	mlx_put_image_to_window(game->mlix, game->window, game->wall.img, 0, 0);
	return (0);
}

int	ft_start(t_game *game)
{
	ft_get_resolution(game);
	ray_init(game);
	game->mlix = mlx_init();
	if (game->mlix == NULL)
		ft_error(ERR,  "Error: mlix init failed");
	game->window = mlx_new_window(game->mlix, game->res_x, game->res_y, "cubmofo3d");
	if (load_texture(game) != 0)
		return (1);
	if (get_texture(game) == -1)
		exit(1);
	mlx_hook(game->window, 2, 1L << 0, k_press, game);
	mlx_hook(game->window, 3, 1L << 1, k_pop, game);
	mlx_hook(game->window, 33, 0, k_exit, game);
	mlx_loop_hook(game->mlix, play_game, game);
	//kharas les leaks
	mlx_loop(game->mlix);
	return (0);
}


int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		ft_error(ERR,  "Error: Wrong number arguments, sorreyyy\n");
	if (ft_init(&game) == 1)
		return (1);
	if (ft_parsing(&game, argv[1]) == 1)
		return (1);
	ft_start(&game);
	destroy(&game);
	exit(1); //kharas les leaks
	return (0);
}
