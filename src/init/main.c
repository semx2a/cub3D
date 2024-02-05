/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:33:50 by seozcan           #+#    #+#             */
/*   Updated: 2023/01/13 16:33:51 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		errno = E2BIG;
		return (ft_error(ERR, BIN_NAME));
	}
	game = (t_game){0};
	game_init(&game);
	parser(&game, argv[1]);
	img_init(&game);
	load_texture(&game);
	window_init(&game);
	controls_init(&game);
	mlx_loop_hook(game.mlx, &render, &game);
	mlx_loop(game.mlx);
	free_game(&game, NULL, true, false);
	return (0);
}
