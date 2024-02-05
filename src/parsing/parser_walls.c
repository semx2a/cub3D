/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:34:47 by seozcan           #+#    #+#             */
/*   Updated: 2023/01/13 16:34:48 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	check_sides(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j++;
		if (map[i][j] != '1')
			return (0);
		while (map[i][j + 1])
			j++;
		if (map[i][j] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_top(char **map, int i, unsigned long j)
{
	while (i >= 0 && ft_strlen(map[i]) >= j)
	{
		if (map[i][j] == '1')
			return (1);
		--i;
	}
	return (0);
}

static int	check_bottom(char **map, int i, unsigned long j)
{
	int	k;

	k = i;
	while (map[k + 1] && ft_strlen(map[k + 1]) > j && map[k + 1][j] != ' ')
		k++;
	while (i < k && map[i + 1])
	{
		if (map[i + 1][j] == '1')
			return (1);
		i++;
	}
	return (0);
}

void	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!check_sides(game->map))
		free_game(game, ERR_MCLOSE, false, true);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1')
			{
				while (game->map[i][j] == ' ' || game->map[i][j] == '\t')
					j++;
				if (!check_top(game->map, i, j))
					free_game(game, ERR_MTOP, false, true);
				else if (!check_bottom(game->map, i, j))
					free_game(game, ERR_MBOTTOM, false, true);
			}
			j++;
		}
		i++;
	}
}
