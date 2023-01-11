#include "../inc/cub3d.h"

void	*ft_xcalloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = NULL;
	ptr = ft_calloc(count, size);
	if (!ptr)
	{
		errno = ENOMEM;
		ft_error(ERR, NULL);
	}
	return (ptr);
}
