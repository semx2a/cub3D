#include "../inc/cub3d.h"

int	ft_kurkipucheck(t_check check)
{
    /*printf("%d\n", check.no);
    printf("%d\n", check.so);
    printf("%d\n", check.ea);
    printf("%d\n", check.we);
    printf("%d\n", check.f);
    printf("%d\n", check.c);*/
	if (check.no != 1)
		ft_error(ERR, "Only one texture is allowed for north, sorrey \n");
	if (check.so != 1)
		ft_error(ERR, "Only one texture is allowed for south, sorrey \n");
	if (check.ea != 1)
		ft_error(ERR, "Only one texture is allowed for east, sorrey \n");
	if (check.we != 1)
		ft_error(ERR, "Only one texture is allowed for west, sorrey \n");
	if (check.f != 1)
		ft_error(ERR, "Only one color is allowed for the floor, sorrey \n");
	if (check.c != 1)
		ft_error(ERR, "Only one color is allowed for the ceiling, sorrey \n");
	return (0);
}

int	ft_iscub(char *file)
{
	int		i;
	char	buff[4] = ".cub";

	i = ft_strlen(file) - 4;
	if (ft_strcmp(file + i, buff) == 0)
		return (0);
	return (1);
}

char	**ft_getfilecontent(char *file)
{
	int		fd;
	char	**copycontent;
	char	buff[MAX];
	int		ret;

	ft_bzero(buff, MAX);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read(fd, buff, MAX);
	while (ret)
	{
		if (ret == -1)
			return (NULL);
		else if (ret == 0)
			break ;
		ret = read(fd, buff, MAX);
	}
	copycontent = ft_split(buff, '\n');
	return (copycontent);
}

int	ft_parcefile(t_game *game, char **file)
{
	int	i;
	int	begining;

	i = 0;
	begining = -2;
	while (file[i])
	{
		if (ft_izmap(file[i]) == 1 && begining == -2)
			begining = i;
		if (begining == -2 && ft_get_info(game, file[i]) == 1)
			return (1);
		i++;
	}
	if (ft_map_parser(game, file, begining) == 1)
		return (1);
	if (ft_kurkipucheck(game->check) == 1)
		return (1);
	return (0);
}

int	ft_copy_map(t_game *game, int tablen)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	tablen = ft_tablen(game->map);
	game->mappi = malloc(sizeof(int *) * tablen);
	if (game->mappi == NULL)
		return (1);
	while (i < tablen)
	{
		game->mappi[i] = malloc(sizeof(int)* (int)ft_strlen(game->map[i]));
		if (game->mappi[i] == NULL)
			return (1);
		i++;
	}
	i = 0;
	while (i < tablen)
	{
		j = 0;
		while (j < (int)ft_strlen(game->map[i]))
		{
			if (game->map[i][j] == '0' || game->map[i][j] == '1')
				game->mappi[i][j] = game->map[i][j] - 48;
			else
				game->mappi[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_parsing(t_game *game, char *file)
{
	char	**copyfile;

	(void)game;
	if (ft_iscub(file) == 1)
		ft_error(ERR, "Error: it's not a .cub, sorrey!\n");
	copyfile = ft_getfilecontent(file);
	if (copyfile == NULL)
		ft_error(ERR, "Error: Cannot open or read file, sorrey \n");
	if (ft_parcefile(game, copyfile) == 1)
		return (1);
	if (ft_copy_map(game, 0) == 1)
		return (1);
	return (0);
}