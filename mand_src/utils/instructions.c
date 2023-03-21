/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:36:18 by mfouadi           #+#    #+#             */
/*   Updated: 2023/03/21 13:02:00 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ** Swap the first 2 elements at the top of stack a
void	ft_sa(t_data *data)
{
	t_node	*tmp_head;
	int		tmp;
	
	tmp_head = HEAD_A;
	if (data->s_a->stk_size > 1)
	{
		tmp = HEAD_A->data;
		HEAD_A->data = HEAD_A->next->data;
		HEAD_A->next->data = tmp;
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
	t_node	*tmp4;
	if (data->s_b->stk_size > 0)
	{
		tmp4 = data->s_b->head;
		push_node(&data->s_a->head, new_node(data->s_b->head->data));
		// printf("node_a=%d\n", data->s_a->head->data);
		data->s_b->head = data->s_b->head->next;
		free(tmp4);
		// printf("node_b=%d\n", data->s_b->head->data);
		data->s_a->stk_size++;
		data->s_b->stk_size--;
	}
}
