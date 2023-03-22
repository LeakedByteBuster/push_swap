/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushnode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:46:23 by mfouadi           #+#    #+#             */
/*   Updated: 2023/03/22 11:44:57 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push_node(t_node **lst, t_node *new)
{
	if (lst && *lst)
	{
		(*lst)->prev = new;
		new->next = *lst;
	}
	*lst = new;
	new->prev = NULL;
}
