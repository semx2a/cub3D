#include "../inc/cub3d.h"

int	get_texture(t_game *game)
{
	int	end;
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		game->tex.img[i] = mlx_xpm_file_to_image(game->mlix,
				game->textpath[i], &game->tex.width[i], &game->tex.height[i]);
		if (!game->tex.img[i])
			return (ft_error("Texture doesn't download"));
		game->tex.addr[i] = (unsigned int *)mlx_get_data_addr(game->tex.img[i],
				&game->tex.bpp, &game->tex.line_length, &game->tex.endian);
		if (!(game->tex.tex[i] = ft_calloc(game->tex.width[i] *
					game->tex.height[i], sizeof(unsigned int))))
			return (ft_error("Texture alloc memory failed"));
		j = 0;
		end = game->tex.width[i] * game->tex.height[i];
		while (j < end)
		{
			game->tex.tex[i][j] = game->tex.addr[i][j];
			++j;
		}
		++i;
	}
	return (1);
}
