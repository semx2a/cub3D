#include "../inc/cub3d.h"
#include "../minilibx-linux/mlx.h"

int     ft_error(char *str)
{
    ft_putstr_fd(str, 2);
    return (1);    
}

void    ft_destroy_img(t_game *game)
{
    if (game->wall.img != NULL)
	    {
		    mlx_destroy_image(game->mlix, game->wall.img);
		    game->wall.img = NULL;
	    }
}

void		ft_new_image(t_game *game)
{
	if (!(game->wall.img = mlx_new_image(game->mlix, game->res_x,
	game->res_y)))
	{
		printf("Error\nGenerating new image failed\n");
		exit(1);
	}
	game->wall.addr = (unsigned int *)mlx_get_data_addr(game->wall.img,
	&game->wall.bpp, &game->wall.line_length, &game->wall.endian);
}

int play_game(t_game *game)
{
    ft_destroy_img(game);
    ft_new_image(game);
    ft_move(game);
    ft_raycast(game);
	mlx_put_image_to_window(game->mlix, game->window, game->wall.img, 0,
	0);
    return (0);
}

int    ft_start(t_game *game)
{
    ft_get_resolution(game);
    ray_init(game);
    game->mlix = mlx_init();
    if (game->mlix == NULL)
        return (ft_error("Error: mlix init failed"));
    game->window = mlx_new_window(game->mlix, game->res_x, game->res_y, "cubmofo3d");
    if (load_texture(game)!= 0)
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


int main (int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        return (ft_error("Error: Wrong number arguments, sorreyyy\n"));
    if (ft_init(&game) == 1)
        return (1);
    if (ft_parcing(&game, argv[1]) == 1)
        return (1);
    ft_start(&game);
    exit(1); //kharas les leaks
    return (0);
}