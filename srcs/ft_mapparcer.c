#include "../inc/cub3d.h"

int	ft_lachose(char c)
{
	if (c == '1' || c == '0')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (2);
	else if (c == ' ')
		return (3);
	return (0);
}

void	ft_onedirection(t_game *game, int i, int j, int *pos)
{
	char	harry;

	harry = game->map[i][j];
	if (harry == 'N')
		game->direction = M_PI;
	else if (harry == 'S')
		game->direction = 0;
	else if (harry == 'E')
		game->direction = M_PI / 2;
	else if (harry == 'W')
		game->direction = (3 * M_PI) / 2;
	game->pos_py = (float)i + 0.5;
	game->pos_px = (float)j + 0.5;
	*pos += 1;
}

int	ft_checkcharmap(t_game *game, int i, int pos)
{
	int	j;

	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (ft_lachose(game->map[i][j]) == 0)
				return (ft_error("Error: Eww, this is not a proper map, sorrey\n"));
			else if (ft_lachose(game->map[i][j]) == 2)
				ft_onedirection(game, i, j, &pos);
			else if (ft_lachose(game->map[i][j]) == 3)
			if (ft_replace_space(game->map, i, j) == 1)
				return (ft_error("Error: Invalid spaces in map, sorrey\n"));
		j++;
		}
		i++;
	}
	if (pos != 1)
		return (ft_error("Error: Wrong number of player, sorrey\n"));
	return (0);
}

int	ft_getmapinfo(t_game *game)
{
	if (ft_checkcharmap(game, 0, 0) != 0)
		return (1);
	if (ft_ismapclosed(game->map, 0, 0) == 1)
		return (1);
	return (0);
}

int	ft_mapparcer(t_game *game, char **tab, int begining)
{
	int	i;

	i = ft_tablen(tab + begining);
	game->map = malloc(sizeof(char *) * i + 1);
	if (game->map == NULL)
		return (ft_error("Error: Map allocation has failed\n"));
	game->map[i] = NULL;
	i = 0;
	while (tab[begining])
	{
		game->map[i] = ft_strdup(tab[begining]);
		if (game->map[i] == NULL)
			return (ft_error("Error: Map allocation has failed\n"));
		i++;
		begining++;
	}
	ft_free_stab(tab);
	if (ft_getmapinfo(game) == 1)
		return (1);
	return (0);
}