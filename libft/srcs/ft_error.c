/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:15:54 by seozcan           #+#    #+#             */
/*   Updated: 2023/01/03 16:24:26 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_error(char *bin_name, char *err_msg)
{
	if (err_msg)
	{
		ft_putstr_fd(bin_name, STDERR_FILENO);
		perror(err_msg);
	}
	else
		perror(bin_name);
	exit(errno);
}
