/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:57:27 by abonard           #+#    #+#             */
/*   Updated: 2023/01/13 16:57:28 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	wall_size(t_game *game)
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
	game->wall.line_height = (int)(HEIGHT
			/ game->rays.perp_wall_dist);
	game->wall.draw_start = (int)(-game->wall.line_height / 2
			+ HEIGHT / 2);
	if (game->wall.draw_start < 0)
		game->wall.draw_start = 0;
	game->wall.draw_end = (int)(game->wall.line_height / 2
			+ HEIGHT / 2);
	if (game->wall.draw_end >= HEIGHT)
		game->wall.draw_end = HEIGHT;
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

static void	raycast_init(t_game *game, int x)
{
	game->rays.cam_x = 2.0 * (float)(WIDTH - 1 - x)
		/ (float)WIDTH - 1;
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
	while (i < WIDTH)
	{
		raycast_init(game, i);
		step_and_side_dist(game);
		dda_algorithm(game);
		wall_size(game);
		draw_texture(game, i, game->wall.draw_start, game->wall.draw_end);
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->wall.img, 0, 0);
	return (0);
}
