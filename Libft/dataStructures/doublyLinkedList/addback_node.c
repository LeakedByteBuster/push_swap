/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addback_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:10:24 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/01 06:16:44 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	addback_node(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!lst || !new)
		return ;
	if (!(*lst))
		return (*lst = new, (void)0);
	last = last_node(*lst);
	new->prev = last;
	last->next = new;
}
