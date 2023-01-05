#include "../inc/cub3d.h"

int	k_press(int keycode, t_game *game)
{
	printf("key->%d\n", keycode);
	if (keycode == KEY_W)
		game->k_up = 1;
	if (keycode == KEY_A)
		game->k_left = 1;
	if (keycode == KEY_S)
		game->k_down = 1;
	if (keycode == KEY_D)
		game->k_right = 1;
	if (keycode == KEY_LEFT)
		game->k_left_rot = 1;
	if (keycode == KEY_RIGHT)
		game->k_right_rot = 1;
	if (keycode == KEY_ESC)
		k_exit(game);
	return (0);
}

int	k_pop(int keycode, t_game *game)
{
	if (keycode == KEY_A)
		game->k_left = 0;
	if (keycode == KEY_W)
		game->k_up = 0;
	if (keycode == KEY_S)
		game->k_down = 0;
	if (keycode == KEY_D)
		game->k_right = 0;
	if (keycode == KEY_LEFT)
		game->k_left_rot = 0;
	if (keycode == KEY_RIGHT)
		game->k_right_rot = 0;
	if (keycode == KEY_ESC)
		game->k_esc = 0;
	return (0);
}

int	k_exit(t_game *game)
{
	(void)game;
	exit(1);
	return (1);
}