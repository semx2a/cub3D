#include "../inc/cub3d.h"

int	ft_basic_checkcolors(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if ((str[i] < '0' && str[i] > '9') && str[i] != ' ' && str[i] != ',')
			ft_error(ERR,  "Invalid characters in color\n");
		i++;
	}
	return (0);
}

int	ft_validcolor(t_game *game, int rgb[3], char *str)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			ft_error(ERR, "That's not a color, sorrey\n");
		i++;
	}
	if (str[0] == 'F')
	{
		game->floor_c = (256 * 256 *rgb[0] + 256 * rgb[1] + rgb[2]);
		game->check.f++;
	}
	else if (str[0] == 'C')
	{
		game->ceiling_c = (256 * 256 *rgb[0] + 256 * rgb[1] + rgb[2]);
		game->check.c++;
	}
	return (0);
}

int	ft_getcolors(t_game *game, char *str, int i)
{
	char	**tab;
	char	*tronc;
	int		rgb[3];

	if (ft_basic_checkcolors(str) == 1)
		return (1);
	tab = ft_split(str + 1, ',');
	if (ft_tablen(tab) != 3)
		ft_error(ERR, "Error: Colors size is way too big, sorrey\n");
	while (tab[i])
	{
		tronc = ft_strtrim(tab[i], " ");
		if (ft_strlen(tronc) > 3)
		{
			ft_free_stab(tab);
			free(tronc);
			ft_error(ERR, "Error: Invalid colors, sorrey\n");
		}
		rgb[i] = ft_atoi(tronc);
		free(tronc);
		i++;
	}
	if (ft_validcolor(game, rgb, str) == 1)
		return (1);
	return (0);
}
