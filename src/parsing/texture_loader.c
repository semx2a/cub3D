/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:34:41 by seozcan           #+#    #+#             */
/*   Updated: 2023/01/13 16:34:42 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	texture_init(t_game *game)
{	
	int	i;

	i = 0;
	game->tex.img = (void **)ft_xcalloc(4, sizeof(void *));
	if (!game->tex.img)
		free_game(game, ERR_MALLOC, true, true);
	game->tex.tex = (unsigned int **)ft_xcalloc(4, sizeof(unsigned int *));
	if (!game->tex.tex)
		free_game(game, ERR_MALLOC, true, true);
	game->tex.addr = (unsigned int **)ft_xcalloc(4, sizeof(unsigned int *));
	if (!game->tex.addr)
		free_game(game, ERR_MALLOC, true, true);
	while (i < 4)
	{
		game->tex.width[i] = 0;
		game->tex.height[i] = 0;
		i++;
	}
}

static void	tex_alloc(t_game *game, int i)
{
	game->tex.img[i] = mlx_xpm_file_to_image(game->mlx,
			game->path[i], &game->tex.width[i], &game->tex.height[i]);
	if (!game->tex.img[i])
		free_game(game, ERR_MLXPM, true, true);
	game->tex.addr[i] = (unsigned int *)mlx_get_data_addr(game->tex.img[i],
			&game->tex.bpp, &game->tex.line_length, &game->tex.endian);
	if (!game->tex.addr[i])
		free_game(game, ERR_MLXMEM, true, true);
	game->tex.tex[i] = ft_xcalloc(game->tex.width[i] * game->tex.height[i],
			sizeof(unsigned int));
	if (!game->tex.tex[i])
		free_game(game, ERR_MALLOC, true, true);
}

void	load_texture(t_game *game)
{
	int		i;
	int		j;

	texture_init(game);
	i = 0;
	while (i < 4)
	{
		tex_alloc(game, i);
		j = 0;
		while (j < game->tex.width[i] * game->tex.height[i])
		{
			game->tex.tex[i][j] = game->tex.addr[i][j];
			++j;
		}
		++i;
	}
}
