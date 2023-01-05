/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 18:45:23 by seozcan           #+#    #+#             */
/*   Updated: 2022/10/14 18:46:45 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_node	*last_node(t_node *n)
{
	if (n)
	{
		while (n->next)
			n = n->next;
		return (n);
	}
	return (NULL);
}
