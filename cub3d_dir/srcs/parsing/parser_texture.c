#include "../../inc/cub3d.h"

static void	check_params(t_game *game)
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
	game->check.total++;
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

void	find_params(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->filecp[i] && game->check.total != 6)
	{
		j = 0;
		while (game->filecp[i][j] == ' ')
			j++;
		if (game->filecp[i][j] == 'N' && game->filecp[i][j + 1] == 'O')
			get_path(game, game->filecp[i] + j, &game->path[0], 1);
		else if (game->filecp[i][j] == 'S' && game->filecp[i][j + 1] == 'O')
			get_path(game, game->filecp[i] + j, &game->path[1], 2);
		else if (game->filecp[i][j] == 'W' && game->filecp[i][j + 1] == 'E')
			get_path(game, game->filecp[i] + j, &game->path[2], 3);
		else if (game->filecp[i][j] == 'E' && game->filecp[i][j + 1] == 'A')
			get_path(game, game->filecp[i] + j, &game->path[3], 4);
		else if (game->filecp[i][j] == 'F')
			get_colors(game, game->filecp[i] + j);
		else if (game->filecp[i][j] == 'C')
			get_colors(game, game->filecp[i] + j);
		else
			ft_invalidchar(game, game->filecp[i]);
		i++;
	}
}

void	load_paths(t_game *game)
{
	game->path = (char **)ft_xcalloc(5, sizeof(char *));
	game->path[4] = 0;
	find_params(game);
	check_params(game);
}
