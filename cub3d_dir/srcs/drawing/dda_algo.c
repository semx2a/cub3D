#include "../../inc/cub3d.h"

static int	which_plan(t_game *game)
{
	int	side;

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
	int	hit;


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
	which_plan(game);
}
