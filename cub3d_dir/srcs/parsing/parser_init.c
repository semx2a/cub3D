#include "../inc/cub3d.h"

int	ft_init(t_game *game)
{
	game->map = NULL;
	game->mappi = NULL;
	game->mlix = NULL;
	game->window = NULL;
	game->textpath = malloc(sizeof(char *) * 4);
	if (game->textpath == NULL)
		ft_error(ERR, "Error: Cannot allocate texture from path, sorrey \n");
	game->textpath[4] = NULL;
	game->check.no = 0;
	game->check.so = 0;
	game->check.ea = 0;
	game->check.we = 0;
	game->check.f = 0;
	game->check.c = 0;	
	return (0);
}

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

void	ray_init(t_game *game)
{
	game->rays.cam_x = 0.0;
	game->rays.ray_dir_x = 0.0;
	game->rays.ray_dir_y = 0.0;
	game->rays.delta_dist_x = 0.0;
	game->rays.delta_dist_y = 0.0;
	game->rays.step_x = 0.0;
	game->rays.step_y = 0.0;
	game->rays.side_dist_x = 0.0;
	game->rays.side_dist_y = 0.0;
	game->rays.perp_wall_dist = 0.0;
	game->rays.map_x = 0;
	game->rays.map_y = 0;
	game->rays.side = 0;
	init_dir_p(game);
	init_plan(game);
}

static	void	text_init_2(t_game *game)
{
	game->k_left = 0;
	game->k_up = 0;
	game->k_right = 0;
	game->k_down = 0;
	game->k_left_rot = 0;
	game->k_right_rot = 0;
	game->tex.tex = NULL;
	game->tex.img = NULL;
	game->tex.bpp = 0;
	game->tex.line_length = 0;
	game->tex.endian = 0;
	game->tex.line_height = 0;
	game->tex.tex_x = 0;
	game->tex.tex_y = 0;
	game->tex.wall_x = 0.0;
	game->tex.step = 0.0;
}

static int	text_init(t_game *game, int i)
{
	text_init_2(game);
	if (!(game->tex.tex = (unsigned int **)ft_calloc(sizeof(unsigned int *), 4)))
		ft_error(ERR,  "texture alloc memory failed");
	if (!(game->tex.addr = (unsigned int **)ft_calloc(sizeof(unsigned int *), 4)))
		ft_error(ERR,  "texture alloc memory failed");
	if (!(game->tex.img = (void **)ft_calloc(sizeof(void *), 4)))
		ft_error(ERR,  "texture alloc memory failed");
	while (i < 4)
	{
		game->tex.width[i] = 0;
		game->tex.height[i] = 0;
		game->tex.tex[i] = NULL;
		game->tex.addr[i] = NULL;
		i++;
	}
	return (1);
}

void	wall_init(t_game *game)
{
	game->wall.img = NULL;
	game->wall.addr = 0;
	game->wall.bpp = 0;
	game->wall.line_length = 0;
	game->wall.endian = 0;
	game->wall.line_height = 0;
	game->wall.draw_start = 0;
	game->wall.draw_end = 0;
	game->wall.color = 0;
	game->wall.ceil_color = 0;
	game->wall.floor_color = 0;
}

int	load_texture(t_game *game)
{
	int		end;
	int		i;
	int		j;

	text_init(game, 0);
	i = 0;
	while (i < 4)
	{
		game->tex.img[i] = mlx_xpm_file_to_image(game->mlix,
				game->textpath[i], &game->tex.width[i], &game->tex.height[i]);
		if (!game->tex.img[i])
			ft_error(ERR ,"Can't get textures, sorrey");
		game->tex.addr[i] = (unsigned int *)mlx_get_data_addr(game->tex.img[i],
				&game->tex.bpp, &game->tex.line_length, &game->tex.endian);
		game->tex.tex[i] = ft_calloc(game->tex.width[i]
				* game->tex.height[i], sizeof(unsigned int));
		if (!game->tex.tex[i])
			ft_error(ERR ,"Texture alloc memory failed, sorrey");
		j = 0;
		end = game->tex.width[i] * game->tex.height[i];
		while (j < end)
		{
			game->tex.tex[i][j] = game->tex.addr[i][j];
			++j;
		}
		++i;
	}
	wall_init(game);
	return (0);
}
