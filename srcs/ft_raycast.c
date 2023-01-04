#include "../inc/cub3d.h"

int					which_plan(t_game *game)
{
	int		side;

	side = 0;
	if (game->rays.side == 0)
	{
		if (game->rays.step_x < 0)
			side = 3;
		else
			side = 1;
	}
	else
	{
		if (game->rays.step_y > 0)
			side = 0;
		else
			side = 2;
	}
	return (side);
}

void	dda_algorithm(t_game *game)
{
	int		hit;
	int		side;

	hit = 0;
	while (hit == 0)
	{
		if (game->rays.side_dist_x < game->rays.side_dist_y)
		{
			game->rays.side_dist_x += game->rays.delta_dist_x;
			game->rays.map_x += game->rays.step_x;
			game->rays.side = 0;
		}
		else
		{
			game->rays.side_dist_y += game->rays.delta_dist_y;
			game->rays.map_y += game->rays.step_y;
			game->rays.side = 1;
		}
		if (game->mappi[(int)(game->rays.map_y)]
		[(int)(game->rays.map_x)] == 1)
			hit = 1;
	}
	side = which_plan(game);
}

void	step_and_side_dist(t_game *game)
{
	if (game->rays.ray_dir_x < 0)
	{
		game->rays.step_x = (-1);
		game->rays.side_dist_x = (game->pos_px - game->rays.map_x) *
			game->rays.delta_dist_x;
	}
	else
	{
		game->rays.step_x = 1;
		game->rays.side_dist_x = (game->rays.map_x + 1.0 -
		game->pos_px) * game->rays.delta_dist_x;
	}
	if (game->rays.ray_dir_y < 0)
	{
		game->rays.step_y = (-1);
		game->rays.side_dist_y = (game->pos_py - game->rays.map_y) *
		game->rays.delta_dist_y;
	}
	else
	{
		game->rays.step_y = 1;
		game->rays.side_dist_y = (game->rays.map_y + 1.0 -
		game->pos_py) * game->rays.delta_dist_y;
	}
}

void	init_raycast(t_game *game, int x)
{
	game->rays.cam_x = 2.0 * (float)(game->res_x - 1 - x) /
		(float)game->res_x - 1;
	game->rays.ray_dir_x = game->rays.dir_x + game->rays.plane_x *
		game->rays.cam_x;
	game->rays.ray_dir_y = game->rays.dir_y + game->rays.plane_y *
		game->rays.cam_x;
	game->rays.map_x = (int)game->pos_px;
	game->rays.map_y = (int)game->pos_py;
	game->rays.delta_dist_x = fabs(1 / game->rays.ray_dir_x);
	game->rays.delta_dist_y = fabs(1 / game->rays.ray_dir_y);
}

void    ft_raycast(t_game *game)
{
    int     i;

    i = 0;
    while (i < game->res_x)
    {
        init_raycast(game, i);
        step_and_side_dist(game);
        dda_algorithm(game);
		ft_wall_size(game);
		ft_print_texture(game, i, game->wall.draw_start, game->wall.draw_end);
        i++;
    }
    return ;
}