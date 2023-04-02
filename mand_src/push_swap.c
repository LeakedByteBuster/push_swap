/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 01:24:30 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/02 14:52:46 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// **	Sorting two numbers
void	sort_two(t_data *data)
{
	if (data->s_a->head->next)
		if (data->s_a->head->next->data < data->s_a->head->data)
			ft_ra(data);
	return ;
}

void	sort_three(t_data *data)
{
	index_stack(data->s_a->head, data->s_a->stk_size);
	data->s_a->botm = last_node(data->s_a->head);
	if ((if_sorted_stop(data->s_a->head, data->s_a->stk_size) == 0)
		&& data->s_a->botm)
		return (three_sort(data), (void)0);
}

void	sort_four(t_data *data)
{
	min_max(data, data->s_a->head);
	current_index_instack(data->s_a->head, data->s_a->stk_size);
	if (data->s_a->min->cur_idx >= 0 && data->s_a->min->cur_idx <= 1)
	{
		if (data->s_a->min->cur_idx == 1)
			ft_sa(data);
	}
	else if (data->s_a->min->cur_idx > 1 && data->s_a->min->cur_idx <= 3)
	{
		if (data->s_a->min->cur_idx <= 2)
			ft_rra(data);
		ft_rra(data);
	}
	if (if_sorted_stop(data->s_a->head, data->s_a->stk_size) == 0)
	{
		ft_pb(data);
		sort_three(data);
		ft_pa(data);
	}
	return ;
}

void	sort_five(t_data *data)
{
	min_max(data, data->s_a->head);
	current_index_instack(data->s_a->head, data->s_a->stk_size);
	if (data->s_a->min->cur_idx <= 2)
	{
		if (data->s_a->min->cur_idx == 1)
			ft_sa(data);
		else if (data->s_a->min->cur_idx == 2)
		{
			ft_ra(data);
			ft_ra(data);
		}
	}
	else if (data->s_a->min->cur_idx > 2 && data->s_a->min->cur_idx <= 4)
	{
		if (data->s_a->min->cur_idx == 3)
			ft_rra(data);
		ft_rra(data);
	}
	if (if_sorted_stop(data->s_a->head, data->s_a->stk_size) == 0)
	{
		ft_pb(data);
		sort_four(data);
		ft_pa(data);
	}
	return ;
}

void	sort_that_shit(t_data *data)
{
	if (data->s_a->stk_size == 2)
		sort_two(data);
	else if (data->s_a->stk_size == 3)
		sort_three(data);
	else if (data->s_a->stk_size == 4)
		sort_four(data);
	else if (data->s_a->stk_size == 5)
		sort_five(data);
	else if ((data->s_a->stk_size > 5) && (data->s_a->stk_size <= 200))
	{
		push_to_b(data, 5, (data->s_a->stk_size / 5),
			(((data->s_a->stk_size / 5)) / 2));
		push_to_a(data);
	}
	else if (data->s_a->stk_size > 200)
	{
		push_to_b(data, 9, (data->s_a->stk_size / 9),
			(((data->s_a->stk_size / 9)) / 2));
		push_to_a(data);
	}
	return ;
}
