#include "../inc/cub3d.h"

int ft_replace_space(char **map, int i, unsigned long j)
{
    if (map[i][j + 1] != '\0' && map[i][j + 1] != ' ' && map[i][j + 1] != '1')
        return (1);
    if (map[i + 1] && ft_strlen(map[i + 1]) > j)
        if (map[i + 1][j] != ' ' && map[i + 1][j] != '1')
            return (1);
    if (j > 0 && map[i][j - 1] != ' ' && map[i][j - 1] != '1')
        return (1);
    if (i > 0 && ft_strlen(map[i - 1]) > j)
        if (map[i - 1][j] != ' ' && map[i - 1][j] != '1')
            return (1);
    map[i][j] = '1';
    return (0);
}

int ft_checksides(char **map)
{
    int i;
    int j;

    i = 0;
    while(map[i])
    {
        j = 0;
        if (map[i][0] != '1')
            return (1);
        while (map[i][j + 1])
            j++;
        if (map[i][j] != '1')
            return (1);
        i++;
    }
    return (0);
}

int ft_checkup(char **map, int i, unsigned long j)
{
    while (i >= 0 && ft_strlen(map[i]) >= j)
    {
        if (map[i][j] == '1')
            return (0);
        --i;
    }
    return (1);
}

int ft_checkdown(char **map, int i, unsigned long j)
{
    int ibis;

    ibis = i;
    while (map[ibis + 1] && ft_strlen(map[ibis + 1]) > j && map[ibis + 1][j] != ' ')
        ibis++;
    while (i < ibis && map[i + 1])
    {
        if (map[i + 1][j] == '1')
            return (0);
        i++;
    }
    return (1);
}

int ft_ismapclosed(char **map, int i, int j)
{
    if (ft_checksides(map) == 1)
        return (ft_error("Error: Map is not closed on the side, sorrey\n"));
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '1')
            {
                if (ft_checkup(map, i, j) == 1)
                    return (ft_error("Error: Map is not closed on the top, sorrey\n"));
                else if (ft_checkdown(map, i, j) == 1)
                    return (ft_error("Error: Map is not closed on the bottom, sorrey\n"));
            }
            j++;
        }
        i++;
    }
    return (0);
}
