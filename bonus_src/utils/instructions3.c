/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:47:54 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/02 18:40:03 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// same problem here as function ss
// **	rra and rrb at the same time
void	ftb_rrr(t_data *data)
{
	ftb_rra(data);
	ftb_rrb(data);
	return ;
}

// potentiel problem of printing sb and sa then ss
// **	sa and sb at the same time
void	ftb_ss(t_data *data)
{
	ftb_sa(data);
	ftb_sb(data);
	return ;
}

void	min_max(t_data *data, t_node *head)
{
	t_node	*tmp;

	if (!head)
		return ;
	tmp = head;
	data->s_a->max = tmp;
	data->s_a->min = tmp;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->data > data->s_a->max->data)
			data->s_a->max = tmp;
		if (tmp->data < data->s_a->min->data)
			data->s_a->min = tmp;
	}
}
