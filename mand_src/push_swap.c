/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 01:24:30 by mfouadi           #+#    #+#             */
/*   Updated: 2023/03/29 09:26:41 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// **	Sorting two numbers
void	sort_two(t_data *data)
{
	if (HEAD_A->next)
		if (HEAD_A->next->data < HEAD_A->data)
			ft_ra(data);
	return ;
}

void	sort_three(t_data *data)
{
	t_node	*mid;

	min_max(data, HEAD_A);
	index_stack(HEAD_A, STK_SIZE_A);
	BOTM_A = last_node(HEAD_A);
	mid = HEAD_A->next;
	if (if_sorted_stop(HEAD_A, STK_SIZE_A) == 0 && BOTM_A)
	{
		if (mid->idx == 0)
		{
			if (BOTM_A->idx == 1)
				return (ft_rra(data), ft_rra(data), (void)0);
			if (BOTM_A->idx == 2)
				return (ft_sa(data), (void)0);
		}
		if (mid->idx == 1)
		{
			if (BOTM_A->idx == 0)
			{
				ft_sa(data);
				ft_rra(data);
			}
		}
		if (mid->idx == 2)
		{
			if (BOTM_A->idx == 0)
				return (ft_rra(data), (void)0);
			else
				return (ft_rra(data), ft_sa(data), (void)0);
		}
	}
	return;
}

void	sort_four(t_data *data)
{
	min_max(data, HEAD_A);
	current_index_instack(HEAD_A, STK_SIZE_A);
	index_stack(HEAD_A, STK_SIZE_A);
	if (MIN_VAL_A->cur_idx >= 0 && MIN_VAL_A->cur_idx <= 1)
	{
		if (MIN_VAL_A->cur_idx == 1)
			ft_sa(data);
	}
	else if (MIN_VAL_A->cur_idx > 1 && MIN_VAL_A->cur_idx <= 3)
	{
		if (MIN_VAL_A->cur_idx <= 2)
			ft_rra(data);
		ft_rra(data);
	}
	if (if_sorted_stop(HEAD_A, STK_SIZE_A) == 0)
	{
		ft_pb(data);
		sort_three(data);
		ft_pa(data);
	}
	return;
	}

void	sort_five(t_data *data)
{
	min_max(data, HEAD_A);
	current_index_instack(HEAD_A, STK_SIZE_A);
	index_stack(HEAD_A, STK_SIZE_A);
	if (MIN_VAL_A->cur_idx <= 2)
	{
		if (MIN_VAL_A->cur_idx == 1)
			ft_sa(data);
		if (MIN_VAL_A->cur_idx == 2)
		{
			ft_ra(data);
			ft_ra(data);
		}
	}
	else if (MIN_VAL_A->cur_idx > 2 && MIN_VAL_A->cur_idx <= 4)
	{
		if (MIN_VAL_A->cur_idx == 3)
			ft_rra(data);
		ft_rra(data);
	}
	if (if_sorted_stop(HEAD_A, STK_SIZE_A) == 0)
	{
		ft_pb(data);
		sort_four(data);
		ft_pa(data);
	}
	return ;
}
/*
- 1 2 0 4 3 (10 instr)
// ** need a function to re-initialize the following data re_init_data(STK_SIZE, max_min, BOTM, idx_CurrIdx)
*/
void	sort_that_shit(t_data *data)
{
	if (STK_SIZE_A == 2)
		sort_two(data);
	if (STK_SIZE_A == 3)
		sort_three(data);
	if (STK_SIZE_A == 4)
		sort_four(data);
	if (STK_SIZE_A == 5)
		sort_five(data);
	return ;
}
