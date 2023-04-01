/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:47:27 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/01 10:48:31 by mfouadi          ###   ########.fr       */
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

t_node	*get_node(t_data *data, int idx)
{
	t_node	*hold;
	t_node	*tmp;
	int		j;

	j = 0;
	tmp = HEAD_B;
	while (j < STK_SIZE_B)
	{
		if (tmp->idx == idx)
		{
			hold = tmp;
			return (hold);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void	push_to_a(t_data *data)
{
	t_node	*hold;
	// t_node	*hold2;
	t_node	*tmp;
	int		j;

	j = 0;
	while (STK_SIZE_B != 0)
	{
		tmp = HEAD_B;
		current_index_instack(HEAD_B, STK_SIZE_B);
		hold = get_node(data, STK_SIZE_B -1);
		// if (STK_SIZE_B > 2)
		// {
		// 	hold2 = get_node(data, STK_SIZE_B - 2);
		// 	printf("hold1 = %d | hold2 = %d\n", hold->data, hold2->data);
		// 	if ((STK_SIZE_B - hold2->cur_idx) < hold->cur_idx)
		// 		hold = hold2;
		// }
		if (hold->cur_idx <= (STK_SIZE_B / 2))
			while (hold->cur_idx--)
				ft_rb(data);
		else
			while(hold->cur_idx++ < STK_SIZE_B)
				ft_rrb(data);
		ft_pa(data);
	}
	return ;
}
