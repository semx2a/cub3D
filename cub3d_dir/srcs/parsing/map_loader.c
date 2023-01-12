#include "../inc/cub3d.h"

int	is_map(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			while (str[i] == ' ' || str[i] == '\t')
				i++;
			if (str[i] != '1' && str[i] != '0')
				return (0);
			i++;
		}
	}
	return (1);
}

void	load_map(t_game *game)
{
	size_t	maplen;
	int		i;
	int		j;

	i = 0;
	while (!is_map(game->file_copy[i]))
		i++;
	maplen = ft_tablen(game->file_copy + i);
	game->map = (char **)ft_xcalloc(maplen + 1, sizeof(char *));
	game->map[maplen] = 0;
	j = 0;
	while (game->file_copy[i])
	{
		game->map[j] = ft_strdup(game->file_copy[i]);
		if (game->map[j] == NULL)
		{
			ft_free_stab(game->map);
			ft_free_stab(game->file_copy);
			free_game(game, ERR_MAPALLOC, false, true);
		}
		i++;
		j++;
	}
	print_stab(game->map);
}
