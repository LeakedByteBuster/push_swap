/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:36:18 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/02 18:36:23 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ** Swap the first 2 elements at the top of stack a
void	ftb_sa(t_data *data)
{
	int	tmp;

	if (data->s_a->stk_size > 1)
	{
		tmp = data->s_a->head->data;
		data->s_a->head->data = data->s_a->head->next->data;
		data->s_a->head->next->data = tmp;
	}
	return ;
}

// ** Swap the first 2 elements at the top of stack b
void	ftb_sb(t_data *data)
{
	int	tmp;

	if (data->s_b->stk_size > 1)
	{
		tmp = data->s_b->head->data;
		data->s_b->head->data = data->s_b->head->next->data;
		data->s_b->head->next->data = tmp;
	}
	return ;
}

// ** Take the first element at the top of b and put it at the top of a.
void	ftb_pa(t_data *data)
{
	t_node	*tmp;

	if (data->s_b->stk_size > 0)
	{
		tmp = data->s_b->head;
		push_node(&data->s_a->head, new_node(data->s_b->head->data));
		data->s_b->head = data->s_b->head->next;
		free(tmp);
		data->s_a->stk_size++;
		data->s_b->stk_size--;
	}
	return ;
}

// **	Take the first element at the top of a and put it at the top of b.
void	ftb_pb(t_data *data)
{
	t_node	*tmp;

	if (data->s_a->stk_size > 0)
	{
		tmp = data->s_a->head;
		push_node(&data->s_b->head, new_node(data->s_a->head->data));
		data->s_a->head = data->s_a->head->next;
		free(tmp);
		data->s_a->stk_size--;
		data->s_b->stk_size++;
	}
	return ;
}
