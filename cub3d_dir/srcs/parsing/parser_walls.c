#include "../inc/cub3d.h"

static int	check_sides(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		if (map[i][0] != '1')
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
	int	ibis;

	ibis = i;
	while (map[ibis + 1] && ft_strlen(map[ibis + 1]) > j
		&& map[ibis + 1][j] != ' ')
		ibis++;
	while (i < ibis && map[i + 1])
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
