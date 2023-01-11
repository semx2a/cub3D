#include "../inc/cub3d.h"

static void	ft_wall_size(t_game *game)
{
	if (game->rays.side == 0)
		game->rays.perp_wall_dist = (game->rays.map_x
				- game->pos_px + (1.0 - (int)game->rays.step_x) / 2.0)
			/ game->rays.ray_dir_x;
	else
		game->rays.perp_wall_dist = (game->rays.map_y - game->pos_py
				+ (1 - (int)game->rays.step_y) / 2) / game->rays.ray_dir_y;
	if (game->rays.perp_wall_dist < 0.005)
		game->rays.perp_wall_dist = 0.005;
	game->wall.line_height = (int)(game->res_y
			/ game->rays.perp_wall_dist);
	game->wall.draw_start = (int)(-game->wall.line_height / 2
			+ game->res_y / 2);
	if (game->wall.draw_start < 0)
		game->wall.draw_start = 0;
	game->wall.draw_end = (int)(game->wall.line_height / 2
			+ game->res_y / 2);
	if (game->wall.draw_end >= game->res_y)
		game->wall.draw_end = game->res_y;
}

static void	step_and_side_dist(t_game *game)
{
	if (game->rays.ray_dir_x < 0)
	{
		game->rays.step_x = (-1);
		game->rays.side_dist_x = (game->pos_px - game->rays.map_x)
			* game->rays.delta_dist_x;
	}
	else
	{
		game->rays.step_x = 1;
		game->rays.side_dist_x = (game->rays.map_x + 1.0
				- game->pos_px) * game->rays.delta_dist_x;
	}
	if (game->rays.ray_dir_y < 0)
	{
		game->rays.step_y = (-1);
		game->rays.side_dist_y = (game->pos_py - game->rays.map_y)
			* game->rays.delta_dist_y;
	}
	else
	{
		game->rays.step_y = 1;
		game->rays.side_dist_y = (game->rays.map_y + 1.0
				- game->pos_py) * game->rays.delta_dist_y;
	}
}

static void	init_raycast(t_game *game, int x)
{
	game->rays.cam_x = 2.0 * (float)(game->res_x - 1 - x)
		/ (float)game->res_x - 1;
	game->rays.ray_dir_x = game->rays.dir_x + game->rays.plane_x
		* game->rays.cam_x;
	game->rays.ray_dir_y = game->rays.dir_y + game->rays.plane_y
		* game->rays.cam_x;
	game->rays.map_x = (int)game->pos_px;
	game->rays.map_y = (int)game->pos_py;
	game->rays.delta_dist_x = fabs(1 / game->rays.ray_dir_x);
	game->rays.delta_dist_y = fabs(1 / game->rays.ray_dir_y);
}

int	render(t_game *game)
{
	int	i;

	i = 0;
	cam_move(game);
	while (i < game->res_x)
	{
		init_raycast(game, i);
		step_and_side_dist(game);
		dda_algorithm(game);
		ft_wall_size(game);
		ft_print_texture(game, i, game->wall.draw_start, game->wall.draw_end);
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->wall.img, 0, 0);
	return (0);
}
