/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:34:02 by seozcan           #+#    #+#             */
/*   Updated: 2023/01/13 16:34:03 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_dir_p(t_game *game)
{
	float	dir;

	dir = game->direction;
	if (dir > (5 * M_PI) / 4 && dir < (7 * M_PI) / 4)
	{
		game->rays.dir_x = (-1.0);
		game->rays.dir_y = 0.0;
	}
	else if (dir > (7 * M_PI) / 4 || dir < M_PI / 4)
	{
		game->rays.dir_x = 0.0;
		game->rays.dir_y = 1.0;
	}
	else if (dir > M_PI / 4 && dir < (3 * M_PI) / 4)
	{
		game->rays.dir_x = 1.0;
		game->rays.dir_y = 0.0;
	}
	else if (dir > (3 * M_PI) / 4 && dir < (5 * M_PI) / 4)
	{
		game->rays.dir_x = 0.0;
		game->rays.dir_y = (-1.0);
	}
}

void	init_plan(t_game *game)
{
	float	dir;

	dir = game->direction;
	if (dir > (5 * M_PI) / 4 && dir < (7 * M_PI) / 4)
	{
		game->rays.plane_x = 0.0;
		game->rays.plane_y = (0.66);
	}
	else if (dir > (7 * M_PI) / 4 || dir < M_PI / 4)
	{
		game->rays.plane_x = 0.66;
		game->rays.plane_y = 0.0;
	}
	else if (dir > M_PI / 4 && dir < (3 * M_PI) / 4)
	{
		game->rays.plane_x = 0.0;
		game->rays.plane_y = (-0.66);
	}
	else if (dir > (3 * M_PI) / 4 && dir < (5 * M_PI) / 4)
	{
		game->rays.plane_x = (-0.66);
		game->rays.plane_y = 0.0;
	}
}

int	game_init(t_game *game)
{	
	game->keys = (t_keys){0};
	game->wall = (t_wall){0};
	game->tex = (t_tex){0};
	game->rays = (t_rays){0};
	game->check = (t_check){0};
	init_dir_p(game);
	init_plan(game);
	return (0);
}
