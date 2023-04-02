/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:24:17 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/02 14:38:48 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// **	Shift up all elements of stack a by 1.first element becomes the last one
void	ft_ra(t_data *data)
{
	t_node	*tmp;

	if (data->s_a->stk_size > 1)
	{
		tmp = data->s_a->head;
		addback_node(&data->s_a->head, new_node(data->s_a->head->data));
		data->s_a->botm = last_node(data->s_a->head);
		data->s_a->botm->idx = data->s_a->head->idx;
		data->s_a->head = data->s_a->head->next;
		free(tmp);
		data->s_a->head->prev = NULL;
		write(1, "ra\n", 3);
	}
	data->s_a->botm = last_node(data->s_a->head);
	return ;
}

void	ft_rb(t_data *data)
{
	t_node	*tmp;

	if (data->s_b && data->s_b->stk_size > 1)
	{
		tmp = data->s_b->head;
		addback_node(&data->s_b->head, new_node(data->s_b->head->data));
		data->s_b->botm = last_node(data->s_b->head);
		data->s_b->botm->idx = data->s_b->head->idx;
		data->s_b->head = data->s_b->head->next;
		free(tmp);
		data->s_b->head->prev = NULL;
		write(1, "rb\n", 3);
	}
	data->s_b->botm = last_node(data->s_b->head);
	return ;
}

// same problem here as function ss
// **	ra and rb at the same time
void	ft_rr(t_data *data)
{
	ft_ra(data);
	ft_rb(data);
	write(1, "rr\n", 3);
}

// **	Shift down all elements of stack a by 1.last element becomes the first
void	ft_rra(t_data *data)
{
	t_node	*tmp;

	if (data->s_a->stk_size > 1)
	{
		tmp = data->s_a->botm;
		push_node(&data->s_a->head, new_node(data->s_a->botm->data));
		data->s_a->head->idx = data->s_a->botm->idx;
		data->s_a->botm = data->s_a->botm->prev;
		free(tmp);
		data->s_a->botm->next = NULL;
		write(1, "rra\n", 4);
	}
	return ;
}

// **	Shift down all elements of stack b by 1.last element becomes the first
void	ft_rrb(t_data *data)
{
	t_node	*tmp;

	if (data->s_b->stk_size > 1)
	{
		tmp = data->s_b->botm;
		push_node(&data->s_b->head, new_node(data->s_b->botm->data));
		data->s_b->head->idx = data->s_b->botm->idx;
		data->s_b->botm = data->s_b->botm->prev;
		free(tmp);
		data->s_b->botm->next = NULL;
		write(1, "rrb\n", 4);
	}
	return ;
}
