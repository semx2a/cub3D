/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonard <abonard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:57:19 by abonard           #+#    #+#             */
/*   Updated: 2023/01/13 16:57:20 by abonard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	close_window(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

int	k_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.k_up = 1;
	if (keycode == KEY_A)
		game->keys.k_left = 1;
	if (keycode == KEY_S)
		game->keys.k_down = 1;
	if (keycode == KEY_D)
		game->keys.k_right = 1;
	if (keycode == KEY_LEFT)
		game->keys.k_left_rot = 1;
	if (keycode == KEY_RIGHT)
		game->keys.k_right_rot = 1;
	if (keycode == KEY_ESC)
		close_window(game);
	return (0);
}

int	k_pop(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		game->keys.k_left = 0;
	if (keycode == KEY_W)
		game->keys.k_up = 0;
	if (keycode == KEY_S)
		game->keys.k_down = 0;
	if (keycode == KEY_D)
		game->keys.k_right = 0;
	if (keycode == KEY_LEFT)
		game->keys.k_left_rot = 0;
	if (keycode == KEY_RIGHT)
		game->keys.k_right_rot = 0;
	if (keycode == KEY_ESC)
		game->keys.k_esc = 0;
	return (0);
}

void	controls_init(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, k_press, game);
	mlx_hook(game->win, 3, 1L << 1, k_pop, game);
	mlx_hook(game->win, 33, 0, close_window, game);
}
