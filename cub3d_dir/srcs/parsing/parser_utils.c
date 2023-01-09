#include "../inc/cub3d.h"

int	ft_izmap(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	ft_invalidchar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' || str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_path(t_game *game, char *str, char **path, int nb)
{
	int	i;

	i = 2;
	if (str[i] != ' ')
		ft_error(ERR, "Error: space missing before texture path\n");
	while (str[i] == ' ')
		i++;
	*path = ft_strdup(str + i);
	if (path == NULL)
		ft_error(ERR, "Error: Cannot allocate path for texture\n");
	if (nb == 1)
		game->check.no++;
	if (nb == 2)
		game->check.so++;
	if (nb == 3)
		game->check.we++;
	if (nb == 4)
		game->check.ea++;
	return (0);
}

int	ft_get_info(t_game *game, char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
		return (ft_get_path(game, str, &game->textpath[0], 1));
	else if (str[0] == 'S' && str[1] == 'O')
		return (ft_get_path(game, str, &game->textpath[1], 2));
	else if (str[0] == 'W' && str[1] == 'E')
		return (ft_get_path(game, str, &game->textpath[2], 3));
	else if (str[0] == 'E' && str[1] == 'A')
		return (ft_get_path(game, str, &game->textpath[3], 4));
	else if (str[0] == 'F')
		return (ft_getcolors(game, str, 0));
	else if (str[0] == 'C')
		return (ft_getcolors(game, str, 0));
	else if (ft_invalidchar(str) == 1)
		ft_error(ERR, "Error: Invalid character in file\n");
	return (0);
}
