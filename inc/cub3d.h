/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:07:31 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/05 22:59:06 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

//		LIBRARIES
//		bool
# include <stdbool.h>

//		limits
# include <limits.h>

//		read, write, exit, close
# include <unistd.h>

//		malloc, free
# include <stdlib.h>

//		math
# include <math.h>

//		strerror
# include <string.h>

//		filedes, printf, perror
# include <stdio.h>

//		open
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

//		X11
# include <X11/X.h>
# include <X11/keysym.h>

//		libft
# include "libft.h"

//		minilibx
# include "mlx.h"

//		cub3d
# include "cub3d_functions.h"
# include "cub3d_macros.h"
# include "cub3d_data.h"

#endif
