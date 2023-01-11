#include "../inc/cub3d.h"

static int	ft_open(char *file_type, char *file_path)
{
	int	fd;

	fd = -1;
	if (file_path)
	{
		if (!ft_strnstr(file_path, file_type, ft_strlen(file_path)))
		{
			errno = EINVAL;
			exit(ft_error(ERR, file_path));
		}
		fd = open(file_path, O_RDONLY);
		if (fd == -1)
			exit(ft_error(ERR, NULL));
		if (read(fd, NULL, 0) == -1)
			exit(ft_error(ERR, NULL));
	}
	return (fd);
}

void	load_file(t_game *game, char *file_path)
{
	int		fd;
	char	buff[MAX];
	int		ret;

	fd = ft_open(".cub", file_path);
	if (fd == -1)
		exit(ft_error(ERR, NULL));
	ft_bzero(buff, MAX);
	ret = 1;
	while (ret)
	{		
		ret = read(fd, buff, MAX);
		if (ret == -1)
			exit(ft_error(ERR, NULL));
	}
	game->file_copy = ft_split(buff, '\n');
	if (!game->file_copy)
		exit(ft_error(ERR, ERR_MALLOC));
}

void	parser(t_game *game, char *file_path)
{		
	load_file(game, file_path);
	load_map(game);
	map_parser(game);
	load_paths(game);
	convert_map(game);
}
