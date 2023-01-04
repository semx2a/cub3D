#include "../inc/cub3d.h"

void	rotation(t_game *game)
{
	float	old_dir_x;
	float	old_plane_x;
	int		rot;

	if (game->k_left_rot == 1)
		rot = (-1);
	else
		rot = 1;
	old_dir_x = game->rays.dir_x;
	old_plane_x = game->rays.plane_x;
	game->rays.dir_x = game->rays.dir_x * cos(ROT_SPEED * rot) -
	game->rays.dir_y * sin(ROT_SPEED * rot);
	game->rays.dir_y = old_dir_x * sin(ROT_SPEED * rot) + game->rays.dir_y *
	cos(ROT_SPEED * rot);
	game->rays.plane_x = game->rays.plane_x * cos(ROT_SPEED * rot) -
	game->rays.plane_y * sin(ROT_SPEED * rot);
	game->rays.plane_y = old_plane_x * sin(ROT_SPEED * rot) +
	game->rays.plane_y * cos(ROT_SPEED * rot);
}

static	void	move_up_down(t_game *game)
{
	if (game->k_up == 1)
	{
		if (game->mappi[(int)game->pos_py]
		[(int)(game->pos_px + game->rays.dir_x * MOVE_SPEED + 1)] == 0)
			game->pos_px += game->rays.dir_x * MOVE_SPEED;
		if (game->mappi[(int)(game->pos_py + game->rays.dir_y *
		MOVE_SPEED + 1)][(int)game->pos_px] == 0)
			game->pos_py += game->rays.dir_y * MOVE_SPEED;
	}
	else if (game->k_down == 1)
	{
		if (game->mappi[(int)game->pos_py]
		[(int)(game->pos_px - game->rays.dir_x * MOVE_SPEED + 1)] == 0)
			game->pos_px -= game->rays.dir_x * MOVE_SPEED;
		if (game->mappi[(int)(game->pos_py - game->rays.dir_y *
		MOVE_SPEED + 1)][(int)game->pos_px] == 0)
			game->pos_py -= game->rays.dir_y * MOVE_SPEED;
	}
}

static	void	side_move(t_game *game)
{
	if (game->k_left == 1)
	{
		if (game->mappi[(int)(game->pos_py -
			game->rays.dir_x * MOVE_SPEED + 1)]
			[(int)(game->pos_px + game->rays.dir_y *
			MOVE_SPEED + 1)] == 0)
		{
			game->pos_px += game->rays.dir_y * MOVE_SPEED;
			game->pos_py -= game->rays.dir_x * MOVE_SPEED;
		}
	}
	else if (game->k_right == 1)
	{
		if (game->mappi[(int)(game->pos_py +
			game->rays.dir_x * MOVE_SPEED + 1)]
			[(int)(game->pos_px - game->rays.dir_y *
			MOVE_SPEED + 1)] == 0)
		{
			game->pos_px -= game->rays.dir_y * MOVE_SPEED;
			game->pos_py += game->rays.dir_x * MOVE_SPEED;
		}
	}
}

void			ft_move(t_game *game)
{
	if (game->k_up == 1 || game->k_down == 1)
		move_up_down(game);
	if (game->k_left_rot == 1 || game->k_right_rot == 1)
		rotation(game);
	if (game->k_left == 1 || game->k_right == 1)
		side_move(game);
}
