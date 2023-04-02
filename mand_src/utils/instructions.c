/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:36:18 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/02 11:48:48 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ** Swap the first 2 elements at the top of stack a
void	ft_sa(t_data *data)
{
	int	tmp2;
	int	tmp;

	if (STK_SIZE_A > 1)
	{
		tmp = HEAD_A->data;
		tmp2 = HEAD_A->idx;
		HEAD_A->idx = HEAD_A->next->idx;
		HEAD_A->data = HEAD_A->next->data;
		HEAD_A->next->data = tmp;
		HEAD_A->next->idx = tmp2;
		write(1, "sa\n", 3);
	}
	return ;
}

// ** Swap the first 2 elements at the top of stack b
void	ft_sb(t_data *data)
{
	int	tmp2;
	int	tmp;

	if (STK_SIZE_B > 1)
	{
		tmp = HEAD_B->data;
		tmp2 = HEAD_B->idx;
		HEAD_B->idx = HEAD_B->next->idx;
		HEAD_B->data = HEAD_B->next->data;
		HEAD_B->next->data = tmp;
		HEAD_B->next->idx = tmp2;
		write(1, "sb\n", 3);
	}
	return ;
}

// ** Take the first element at the top of b and put it at the top of a.
void	ft_pa(t_data *data)
{
	t_node	*tmp;

	if (STK_SIZE_B > 0)
	{
		tmp = HEAD_B;
		push_node(&HEAD_A, new_node(HEAD_B->data));
		HEAD_A->idx = HEAD_B->idx;
		HEAD_B = HEAD_B->next;
		free(tmp);
		STK_SIZE_A++;
		STK_SIZE_B--;
		write(1, "pa\n", 3);
	}
	return ;
}

// **	Take the first element at the top of a and put it at the top of b.
void	ft_pb(t_data *data)
{
	t_node	*tmp;

	if (STK_SIZE_A > 0)
	{
		tmp = HEAD_A;
		push_node(&HEAD_B, new_node(HEAD_A->data));
		HEAD_B->idx = HEAD_A->idx;
		HEAD_A = HEAD_A->next;
		free(tmp);
		STK_SIZE_A--;
		STK_SIZE_B++;
		write(1, "pb\n", 3);
	}
	return ;
}
