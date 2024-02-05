/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:35:06 by seozcan           #+#    #+#             */
/*   Updated: 2023/01/13 16:35:07 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	**map_alloc(size_t size, char **src)
{
	int		**map;
	size_t	i;

	map = (int **)ft_xcalloc(size, sizeof(int *));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		map[i] = (int *)ft_xcalloc(ft_strlen(src[i]), sizeof(int));
		if (map[i] == NULL)
		{
			free_tab(map, i);
			return (NULL);
		}
		i++;
	}
	return (map);
}

void	convert_map(t_game *game)
{
	size_t	i;
	size_t	j;

	game->tablen = ft_tablen(game->map);
	game->mappi = map_alloc(game->tablen, game->map);
	if (!game->mappi)
		free_game(game, ERR_MAPALLOC, false, true);
	i = 0;
	j = 0;
	while (i < game->tablen)
	{
		j = 0;
		while (j < ft_strlen(game->map[i]))
		{
			if (game->map[i][j] == '0' || game->map[i][j] == '1')
				game->mappi[i][j] = game->map[i][j] - 48;
			else
				game->mappi[i][j] = 0;
			j++;
		}
		i++;
	}
}
