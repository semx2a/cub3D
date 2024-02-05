/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:33:55 by seozcan           #+#    #+#             */
/*   Updated: 2023/01/13 16:33:56 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
