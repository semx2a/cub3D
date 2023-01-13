/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:35:02 by seozcan           #+#    #+#             */
/*   Updated: 2023/01/13 16:35:03 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	is_map(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_strchr("NSWE10 ", str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	load_map(t_game *game)
{
	size_t	maplen;
	int		i;
	int		j;

	i = 0;
	while (game->filecp[i] && !is_map(game->filecp[i]))
		i++;
	maplen = ft_tablen(game->filecp + i);
	game->map = (char **)ft_xcalloc(maplen + 1, sizeof(char *));
	game->map[maplen] = 0;
	j = 0;
	while (game->filecp[i] && is_map(game->filecp[i]))
	{
		game->map[j] = ft_strdup(game->filecp[i]);
		if (game->map[j] == NULL)
		{
			ft_free_stab(game->map);
			ft_free_stab(game->filecp);
			free_game(game, ERR_MAPALLOC, false, true);
		}
		i++;
		j++;
	}
}
