#include "../../inc/cub3d.h"

void	destroy_tex(t_game *game, size_t len)
{
	size_t	i;

	i = 0;
	if (game->tex.img != NULL)
	{
		while (i < len)
		{
			if (game->tex.img[i])
				mlx_destroy_image(game->mlx, game->tex.img[i]);
			i++;
		}
	}
}

void	destroy(t_game *game)
{
	destroy_tex(game, 4);
	if (game->wall.img != NULL)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->win != NULL)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
	}
	if (game->mlx != NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	set_nul(t_game *game)
{
	game->rays = (t_rays){0};
	game->tex = (t_tex){0};
	game->wall = (t_wall){0};
	game->check = (t_check){0};
}

void	free_game(t_game *game, char *err_msg, bool is_mlx, bool is_err)
{
	if (is_err)
		ft_error(ERR, err_msg);
	if (is_mlx)
		destroy(game);
	if (game->file_copy != NULL)
		ft_free_stab(game->file_copy);
	if (game->map != NULL)
		ft_free_stab(game->map);
	if (game->path != NULL)
		ft_free_stab(game->path);
	if (game->mappi != NULL)
		free_tab(game->mappi, game->tablen);
	if (game->tex.addr != NULL)
		free(game->tex.addr);
	if (game->tex.img != NULL)
		free(game->tex.img);
	if (game->tex.tex != NULL)
		free_tab((int **)(game->tex.tex), 4);
	set_nul(game);
	exit(EXIT_FAILURE);
}
