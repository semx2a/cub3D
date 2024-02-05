/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:33:58 by seozcan           #+#    #+#             */
/*   Updated: 2023/01/13 16:33:59 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	img_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		free_game(game, ERR_MLXINIT, true, true);
	game->wall.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->wall.img)
		free_game(game, ERR_IMG, true, true);
	game->wall.addr = (unsigned int *)mlx_get_data_addr(game->wall.img,
			&game->wall.bpp, &game->wall.line_length, &game->wall.endian);
	if (!game->wall.addr)
		free_game(game, ERR_IMG, true, true);
}

void	window_init(t_game *game)
{	
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, BIN_NAME);
	if (!game->win)
		free_game(game, ERR_WINX, true, true);
}
