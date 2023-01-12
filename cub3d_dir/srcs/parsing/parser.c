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

static void	get_filelen(t_game *game, char *file_path)
{	
	int		fd;
	int		ret;
	char	*buf;

	fd = ft_open(".cub", file_path);
	ret = 1;
	while (ret)
	{
		ret = get_next_line_r(fd, &buf);
		free(buf);
		game->filelen++;
	}
	close(fd);
}

static void	load_file(t_game *game, char *file_path)
{	
	int		fd;
	int		ret;
	int		i;
	char	*buf;

	get_filelen(game, file_path);
	ret = 1;
	buf = NULL;
	game->filecp = NULL;
	game->filecp = (char **)ft_xcalloc((game->filelen + 1), sizeof(char *));
	game->filecp[game->filelen] = 0;
	i = 0;
	fd = ft_open(".cub", file_path);
	while (ret)
	{
		ret = get_next_line_r(fd, &buf);
		game->filecp[i] = ft_strdup(buf);
		free(buf);
		i++;
	}
	close(fd);
}

void	parser(t_game *game, char *file_path)
{		
	load_file(game, file_path);
	load_map(game);
	map_parser(game);
	load_paths(game);
	convert_map(game);
}
