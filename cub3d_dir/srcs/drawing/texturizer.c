#include "../inc/cub3d.h"

static void	ft_put_pixels(t_game *game, int x, int y, unsigned int color)
{
	unsigned int	*dst;

	dst = NULL;
	if (x < 800 && y < 600 && x >= 0 && y >= 0)
	{
		dst = game->wall.addr + (y * game->res_x + x);
		*(unsigned int *)dst = color;
	}
}

static int	ft_print_wall(t_game *game, int side, int y, int x)
{
	float			tex_y;
	unsigned int	color;

	tex_y = 0.0;
	color = 0;
	while (y >= game->wall.draw_start && y < game->wall.draw_end)
	{
		tex_y = (int)(((y - game->res_y
						/ 2 + game->wall.line_height / 2)
					* game->tex.height[side]) / game->wall.line_height);
		color = game->tex.tex[side][game->tex.width[side]
			* (int)floor(tex_y) + game->tex.tex_x];
		ft_put_pixels(game, x, y, color);
		++y;
	}
	return (y);
}

static int	ft_get_plan(t_game *game)
{
	int	side;

	side = 0;
	if (game->rays.side == 0)
	{
		if (game->rays.step_x > 0)
			side = 1;
		else
			side = 3;
	}
	else
	{
		if (game->rays.step_y < 0)
			side = 2;
		else
			side = 0;
	}
	return (side);
}

static int	ft_calcul_x_text(t_game *game, int side)
{
	int		tex_x;
	float	wall_x;

	tex_x = 0;
	wall_x = 0;
	if (game->rays.side == 0)
		wall_x = game->pos_py + game->rays.perp_wall_dist
			* game->rays.ray_dir_y;
	else
		wall_x = game->pos_px + game->rays.perp_wall_dist
			* game->rays.ray_dir_x;
	wall_x = wall_x - floor(wall_x);
	tex_x = (int)(wall_x * (float)game->tex.width[side]);
	if (side == 0)
		tex_x = game->tex.width[side] - tex_x - 1;
	if (side == 3)
		tex_x = game->tex.width[side] - tex_x - 1;
	return (tex_x);
}

void	ft_print_texture(t_game *game, int x, int start, int end)
{
	int	y;
	int	text_y;
	int	side;

	y = 0;
	side = ft_get_plan(game);
	game->tex.tex_x = ft_calcul_x_text(game, side);
	text_y = 0;
	while (y < start)
	{
		ft_put_pixels(game, x, y, game->ceiling_c);
		++y;
	}
	y = ft_print_wall(game, side, y, x);
	while (y >= end && y < game->res_y)
	{
		ft_put_pixels(game, x, y, game->floor_c);
		++y;
	}
}
