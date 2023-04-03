/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:24:17 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/02 18:46:07 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// **	Shift up all elements of stack a by 1.first element becomes the last one
void	ftb_ra(t_data *data)
{
	t_node	*tmp;

	if (data->s_a->stk_size > 1)
	{
		tmp = data->s_a->head;
		addback_node(&data->s_a->head, new_node(data->s_a->head->data));
		data->s_a->head = data->s_a->head->next;
		free(tmp);
		data->s_a->head->prev = NULL;
	}
	data->s_a->botm = last_node(data->s_a->head);
	return ;
}

void	ftb_rb(t_data *data)
{
	t_node	*tmp;

	if (data->s_b && data->s_b->stk_size > 1)
	{
		tmp = data->s_b->head;
		addback_node(&data->s_b->head, new_node(data->s_b->head->data));
		data->s_b->head = data->s_b->head->next;
		free(tmp);
		data->s_b->head->prev = NULL;
	}
	data->s_b->botm = last_node(data->s_b->head);
	return ;
}

// same problem here as function ss
// **	ra and rb at the same time
void	ftb_rr(t_data *data)
{
	ftb_ra(data);
	ftb_rb(data);
}

// **	Shift down all elements of stack a by 1.last element becomes the first
void	ftb_rra(t_data *data)
{
	t_node	*tmp;

	if (data->s_a->stk_size > 1)
	{
		tmp = data->s_a->botm;
		push_node(&data->s_a->head, new_node(data->s_a->botm->data));
		data->s_a->botm = data->s_a->botm->prev;
		free(tmp);
		data->s_a->botm->next = NULL;
	}
	return ;
}

// **	Shift down all elements of stack b by 1.last element becomes the first
void	ftb_rrb(t_data *data)
{
	t_node	*tmp;

	if (data->s_b->stk_size > 1)
	{
		tmp = data->s_b->botm;
		push_node(&data->s_b->head, new_node(data->s_b->botm->data));
		data->s_b->botm = data->s_b->botm->prev;
		free(tmp);
		data->s_b->botm->next = NULL;
	}
	return ;
}
