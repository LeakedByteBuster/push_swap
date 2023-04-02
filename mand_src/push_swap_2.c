/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:47:27 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/02 11:28:33 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/inc/libft.h"

void	push_to_b(t_data *data, int div, int chunck_len)
{
	int 	k;
	int		g;
	int		min_idx;
	int		half_chunk;
	int 	mod;

	k = 0;
	min_idx = 0;
	mod = (STK_SIZE_A % div);
	g = chunck_len;
	half_chunk = chunck_len / 2;
	while (HEAD_A && div--)
	{
		if (div == 0)
			chunck_len += mod;
		while (HEAD_A && (k <= chunck_len))
		{
			if ((HEAD_A->idx >= min_idx) && (HEAD_A->idx <= chunck_len))
			{
				if (HEAD_A->idx <= half_chunk)
				{
					ft_pb(data);
					ft_rb(data);
				}
				else
					ft_pb(data);
				k++;
			}
			else
				ft_ra(data);
		}
		min_idx += g;
		chunck_len += g;
		half_chunk += g;
	}
	return ;
}


t_node	*get_node_position(t_data *data, int idx)
{
	t_node	*tmp;
	int		j;

	j = 0;
	tmp = HEAD_B;
	while (j < STK_SIZE_B)
	{
		if (tmp->idx == idx)
			return (tmp);
		tmp = tmp->next;
		j++;
	}
	return (NULL);
}

int	nbr_of_moves(int big, int small, int stk_size)
{
	int	b;
	int	s;

	b = 0;
	s = 0;

	if (big < (stk_size / 2))
		b = big + 1;
	else
		b = stk_size - big + 1;
	// ** '+ 2' because i have to pa(), then sa()
	if (small < (stk_size / 2))
		s = small + 2;
	else
		s = stk_size - small + 2;
	if (s < b)
		return (1);
	return (0);
}

void	push_to_a(t_data *data)
{
	t_node	*hold;
	t_node	*hold2;
	int		bol;

	bol = 0;
	hold = NULL;
	hold2 = NULL;
	while (STK_SIZE_B != 0)
	{
		current_index_instack(HEAD_B, STK_SIZE_B);	
		hold = get_node_position(data, STK_SIZE_B-1);
		if (hold && (STK_SIZE_B > 1))
			hold2 = get_node_position(data, STK_SIZE_B - 2);
		if ((hold2 != NULL) && (hold != NULL) && (STK_SIZE_B > 2))
		{
			if (nbr_of_moves(hold->cur_idx, hold2->cur_idx, STK_SIZE_B) == 1)
			{
				// **	if node is located in the upper half of the STACK_B ==> rb(), else ==> rrb()
				bol =  1;
				if (hold2->cur_idx < (STK_SIZE_B / 2))
				{
					while (hold2->cur_idx-- > 0)
						ft_rb(data);
				}
				else
				{
					while (hold2->cur_idx++ < STK_SIZE_B)
						ft_rrb(data);
				}
				ft_pa(data);
			}
			current_index_instack(HEAD_B, STK_SIZE_B);
		}
		// **	Push biggest number to STACK_A
		if (hold->cur_idx < (STK_SIZE_B / 2))
			while (hold->cur_idx-- > 0)
				ft_rb(data);
		else
			while (hold->cur_idx++ < STK_SIZE_B)
				ft_rrb(data);
		ft_pa(data);
		// **	Swap STACK_A
		if (bol == 1)
		{
			bol = 0;
			ft_sa(data);
		}
	}
	return ;
}
