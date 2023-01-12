#include "../inc/cub3d.h"

void	print_wrong(char *str, int i, int j)
{
	int	k;

	k = 0;
	printf("game->map[%d] = [", i);
	while (str[k])
	{
		printf("%c", str[k]);
		k++;
		if (k == j)
			printf("\033[0;31m%c\033[m", str[k]);
	}
	printf("]\n");
}

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
		{
			print_wrong(map[i], i, j);
			return (0);
		}
		while (map[i][j + 1])
			j++;
		if (map[i][j] != '1')
		{
			print_wrong(map[i], i, j);
			return (0);
		}
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
				{
					print_wrong(game->map[i], i, j);
					free_game(game, ERR_MTOP, false, true);
				}
				else if (!check_bottom(game->map, i, j))
				{
					print_wrong(game->map[i], i, j);
					free_game(game, ERR_MBOTTOM, false, true);
				}
			}
			j++;
		}
		i++;
	}
}
