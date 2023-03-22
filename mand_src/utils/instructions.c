/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:36:18 by mfouadi           #+#    #+#             */
/*   Updated: 2023/03/22 10:52:31 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ** Swap the first 2 elements at the top of stack a
void	ft_sa(t_data *data)
{
	t_node	*tmp_head;
	int		tmp;
	
	if (STK_SIZE_A > 1)
	{
		tmp_head = HEAD_A;
		if (STK_SIZE_A > 1)
		{
			tmp = HEAD_A->data;
			HEAD_A->data = HEAD_A->next->data;
			HEAD_A->next->data = tmp;
		}
	}
	return ;
}

// ** Swap the first 2 elements at the top of stack b
void	ft_sb(t_data *data)
{
	t_node	*tmp_head;
	int		tmp;

	tmp_head = HEAD_B;
	if (STK_SIZE_B > 1)
	{
		tmp = HEAD_B->data;
		HEAD_B->data = HEAD_B->next->data;
		HEAD_B->next->data = tmp;
	}
	return ;
}

// **	sa and sb at the same time
void	ft_ss(t_data *data)
{
	ft_sa(data);
	ft_sb(data);
	return ;
}

// ** Take the first element at the top of b and put it at the top of a.
void	ft_pa(t_data *data)
{
	t_node	*tmp;

	if (STK_SIZE_B > 0)
	{
		// **	store head of B
		tmp = data->s_b->head;
		// **	push node to top of of A
		push_node(&data->s_a->head, new_node(data->s_b->head->data));
		// **	new head of B is second node
		data->s_b->head = data->s_b->head->next;
		// **	free previous head
		free(tmp);
		// **	increment size of stack A
		STK_SIZE_A++;
		// **	decrement size of stack B
		STK_SIZE_B--;
	}
	return ;
}

// **	Take the first element at the top of a and put it at the top of b.
void	ft_pb(t_data *data)
{
	t_node	*tmp;

	if (STK_SIZE_A > 0)
	{
	// 	// **	Store head node in A
		tmp = HEAD_A;
	// 	// **	Push head node from A to B
		push_node(&HEAD_B, new_node(HEAD_A->data));
	// 	// **	New head of STACK_A is second node
		HEAD_A = HEAD_A->next;
		free(tmp);
		STK_SIZE_A--;
		STK_SIZE_B++;
	}
	return ;
}
