#include "./libft.h"

void    ft_printtab(char **str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putstr_fd(str[i], 1);
        write(1, "\n", 1);
        i++;
    }
}