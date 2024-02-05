/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:34:53 by seozcan           #+#    #+#             */
/*   Updated: 2023/01/13 16:34:54 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	is_token(char c)
{
	if (c == '1' || c == '0')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (2);
	else if (c == '\t' || c == ' ')
		return (3);
	return (0);
}

static void	assign_direction(t_game *game, int i, int j, int *pos)
{
	char	buf;

	buf = game->map[i][j];
	if (buf == 'N')
		game->direction = M_PI;
	else if (buf == 'S')
		game->direction = 0;
	else if (buf == 'E')
		game->direction = M_PI / 2;
	else if (buf == 'W')
		game->direction = (3 * M_PI) / 2;
	game->pos_py = (float)i + 0.5;
	game->pos_px = (float)j + 0.5;
	*pos += 1;
}

static int	replace_space(char **map, int i, unsigned long j)
{
	if (map[i][j + 1] != '\0' && map[i][j + 1] != ' ' && map[i][j + 1] != '1')
		return (1);
	if (map[i + 1] && ft_strlen(map[i + 1]) > j)
		if (map[i + 1][j] != ' ' && map[i + 1][j] != '1')
			return (1);
	if (j > 0 && map[i][j - 1] != ' ' && map[i][j - 1] != '1')
		return (1);
	if (i > 0 && ft_strlen(map[i - 1]) > j)
		if (map[i - 1][j] != ' ' && map[i - 1][j] != '1')
			return (1);
	map[i][j] = '1';
	return (0);
}

void	map_parser(t_game *game)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	pos = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!is_token(game->map[i][j]))
				free_game(game, ERR_IMAP, false, true);
			else if (is_token(game->map[i][j]) == 2)
				assign_direction(game, i, j, &pos);
			else if (is_token(game->map[i][j]) == 3)
				if (replace_space(game->map, i, j) == 1)
					free_game(game, ERR_MSPACE, false, true);
			j++;
		}
		i++;
	}
	check_walls(game);
	if (pos != 1)
		free_game(game, ERR_PLAYER, false, true);
}
