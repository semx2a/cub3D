/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:51:07 by seozcan           #+#    #+#             */
/*   Updated: 2023/01/02 20:09:12 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;

	i = 0;
	a = (char)c;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == a || (s[i] == '\0' && a == 0))
				return ((char *)s + i);
			i++;
		}
		if (s[i] == '\0' && a == 0)
			return ((char *)s + ft_strlen(s));
	}
	return (0);
}
