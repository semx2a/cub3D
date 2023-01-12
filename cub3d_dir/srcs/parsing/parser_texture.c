#include "../../inc/cub3d.h"

static void	check_paths(t_game *game)
{
	if (game->check.no != 1)
		free_game(game, ERR_TEXVIEW, false, true);
	if (game->check.so != 1)
		free_game(game, ERR_TEXVIEW, false, true);
	if (game->check.ea != 1)
		free_game(game, ERR_TEXVIEW, false, true);
	if (game->check.we != 1)
		free_game(game, ERR_TEXVIEW, false, true);
	if (game->check.f != 1)
		free_game(game, ERR_RGBVIEW, false, true);
	if (game->check.c != 1)
		free_game(game, ERR_RGBVIEW, false, true);
}

static int	get_path(t_game *game, char *str, char **path, int nb)
{
	int	i;

	i = 2;
	if (str[i] != ' ')
		free_game(game, ERR_PSPACE, false, true);
	while (str[i] == ' ')
		i++;
	if (*path == 0)
		*path = ft_strdup(str + i);
	if (path == NULL)
		free_game(game, ERR_MALLOC, false, true);
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

static void	ft_invalidchar(t_game *game, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr("NOSWEAFC \n", str[i]))
			free_game(game, ERR_ICHAR, false, true);
		i++;
	}
}

void	load_paths(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	game->path = (char **)ft_xcalloc(5, sizeof(char *));
	game->path[4] = 0;
	while (game->file_copy[i])
	{
		j = 0;
		while (!ft_strchr("NOSWEAFC \n", game->file_copy[i][j]))
			j++;
//			free_game(game, "Map description should be at the end of the file", false, true);
		if (game->file_copy[i][j] == 'N' && game->file_copy[i][j + 1] == 'O')
			get_path(game, game->file_copy[i], &game->path[0], 1);
		else if (game->file_copy[i][j] == 'S' && game->file_copy[i][j + 1] == 'O')
			get_path(game, game->file_copy[i], &game->path[1], 2);
		else if (game->file_copy[i][j] == 'W' && game->file_copy[i][j + 1] == 'E')
			get_path(game, game->file_copy[i], &game->path[2], 3);
		else if (game->file_copy[i][j] == 'E' && game->file_copy[i][j + 1] == 'A')
			get_path(game, game->file_copy[i], &game->path[3], 4);
		else if (game->file_copy[i][j] == 'F')
			get_colors(game, game->file_copy[i]);
		else if (game->file_copy[i][j] == 'C')
			get_colors(game, game->file_copy[i]);
		else
			ft_invalidchar(game, game->file_copy[i]);
		i++;
	}
	check_paths(game);
}
