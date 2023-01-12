#include "../inc/cub3d.h"

static void	simple_colorcheck(t_game *game, char *str)
{
	int	i;
	int	comma;

	i = 1;
	comma = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			comma++;
			if (comma > 2)
				free_game(game, ERR_COLORS, false, true);
		}
		if (!ft_strchr("0123456789, ", str[i]))
			free_game(game, ERR_COLORS, false, true);
		i++;
	}
}

static void	is_validcolor(t_game *game, char *str)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->rgb[i] < 0 || game->rgb[i] > 255)
			free_game(game, ERR_RGB, false, true);
		i++;
	}
	if (str[0] == 'F')
	{
		game->floor_c = (256 * 256 * game->rgb[0] + 256 * game->rgb[1]
				+ game->rgb[2]);
		game->check.f++;
	}
	else if (str[0] == 'C')
	{
		game->ceiling_c = (256 * 256 * game->rgb[0] + 256 * game->rgb[1]
				+ game->rgb[2]);
		game->check.c++;
	}
}

static void	color_alloc(t_game *game, char **tab)
{
	char	*nb;
	int		i;

	if (ft_tablen(tab) != 3)
	{
		ft_free_stab(tab);
		free_game(game, ERR_RGBLEN, false, true);
	}
	i = 0;
	while (tab[i])
	{
		nb = ft_strtrim(tab[i], " ");
		if (ft_strlen(nb) > 3)
		{
			ft_free_stab(tab);
			free(nb);
			free_game(game, ERR_COLORS, false, true);
		}
		game->rgb[i] = ft_atoi(nb);
		free(nb);
		i++;
	}
}

int	get_colors(t_game *game, char *str)
{	
	char	**tab;

	simple_colorcheck(game, str);
	tab = ft_split(str + 1, ',');
	if (!tab)
		free_game(game, ERR_MALLOC, false, true);
	color_alloc(game, tab);
	is_validcolor(game, str);
	ft_free_stab(tab);
	return (0);
}
