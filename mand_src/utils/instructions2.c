/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 02:24:17 by mfouadi           #+#    #+#             */
/*   Updated: 2023/03/29 01:50:19 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// **	Shift up all elements of stack a by 1. The first element becomes the last one.
void	ft_ra(t_data *data)
{
	t_node	*tmp;

	if (STK_SIZE_A > 1)
	{
		// printf("ra : HEAD_A = %d | stacka_size = %d \n\n", HEAD_A->data, STK_A->stk_size);
		tmp = HEAD_A;
		addback_node(&HEAD_A, new_node(HEAD_A->data));
		HEAD_A = HEAD_A->next;
		free(tmp);
		HEAD_A->prev = NULL;
	}
	STK_A->botm = last_node(HEAD_A);
	write(1, "ra\n", 3);
	return;
}

void	ft_rb(t_data *data)
{
	t_node	*tmp;

	if (STK_SIZE_B > 1)
	{
		tmp = HEAD_B;
		addback_node(&HEAD_B, new_node(HEAD_B->data));
		HEAD_B = HEAD_B->next;
		free(tmp);
		HEAD_B->prev = NULL;
	}
	STK_B->botm = last_node(HEAD_B);
	write(1, "rb\n", 3);
	return;
}

// **	ra and rb at the same time
void	ft_rr(t_data *data)
{
		ft_ra(data);
		ft_rb(data);
		write(1, "rr\n", 3);
}

// **	Shift down all elements of stack a by 1. The last element becomes the first one.
void	ft_rra(t_data *data)
{
	t_node	*tmp;
	
	if (STK_SIZE_A > 1)
	{
		// printf("rra : HEAD_A = %d | stacka_size = %d | BOTM_A = %d \n\n", HEAD_A->next->data, STK_A->stk_size, STK_A->botm->data);
		tmp = STK_A->botm;
		push_node(&HEAD_A, new_node(STK_A->botm->data));
		STK_A->botm = STK_A->botm->prev;
		free(tmp);
		STK_A->botm->next = NULL;
	}
	write(1, "rra\n", 4);
	return ;
}

// **	Shift down all elements of stack b by 1. The last element becomes the first one.
void	ft_rrb(t_data *data)
{
	t_node	*tmp;
	
	if (STK_SIZE_B > 1)
	{
		tmp = BOTM_B;
		push_node(&HEAD_B, new_node(BOTM_B->data));
		BOTM_B = STK_B->botm->prev;
		BOTM_B->next = NULL;
		free(tmp);
	}
	write(1, "rrb\n", 4);
	return ;
}

// **	rra and rrb at the same time
void	ft_rrr(t_data *data)
{
	ft_rra(data);
	ft_rrb(data);
	write(1, "rrr\n", 4);
	return ;
}
