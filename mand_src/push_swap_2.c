/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:47:27 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/02 15:14:39 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/inc/libft.h"

void	__push_b(t_data *data, int half_chunk, int *k)
{
	if (data->s_a->head->idx <= half_chunk)
	{
		ft_pb(data);
		ft_rb(data);
	}
	else
		ft_pb(data);
	(*k)++;
	return ;
}

void	init_var(int *k, int *g, int *min_idx, int chunk_len)
{
	*k = 0;
	*min_idx = 0;
	*g = chunk_len;
}

void	push_to_b(t_data *data, int div, int chunck_len, int half_chunk)
{
	int	k;
	int	g;
	int	min_idx;
	int	mod;

	init_var(&k, &g, &min_idx, chunck_len);
	mod = (data->s_a->stk_size % div);
	while (data->s_a->head && div--)
	{
		if (div == 0)
			chunck_len += mod;
		while (data->s_a->head && (k <= chunck_len))
		{
			if ((data->s_a->head->idx >= min_idx)
				&& (data->s_a->head->idx <= chunck_len))
				__push_b(data, half_chunk, &k);
			else
				ft_ra(data);
		}
		min_idx += g;
		chunck_len += g;
		half_chunk += g;
	}
}

void	__push_to_a(t_node *hold, t_data *data, int *bol, int set_bol)
{
	if (set_bol == 1)
		*bol = 1;
	if (hold->cur_idx < (data->s_b->stk_size / 2))
		while (hold->cur_idx-- > 0)
			ft_rb(data);
	else
		while (hold->cur_idx++ < data->s_b->stk_size)
			ft_rrb(data);
	ft_pa(data);
}

void	push_to_a(t_data *data)
{
	t_node	*hold;
	t_node	*hold2;
	int		bol;

	bol = 0;
	while (data->s_b->stk_size != 0)
	{
		current_index_instack(data->s_b->head, data->s_b->stk_size);
		hold = get_node_position(data, data->s_b->stk_size -1);
		if (hold && (data->s_b->stk_size > 1))
			hold2 = get_node_position(data, data->s_b->stk_size - 2);
		if ((hold2 != NULL) && (hold != NULL) && (data->s_b->stk_size > 2))
		{
			if (nbr_of_moves(hold->cur_idx, hold2->cur_idx,
					data->s_b->stk_size) == 1)
				__push_to_a(hold2, data, &bol, 1);
			current_index_instack(data->s_b->head, data->s_b->stk_size);
		}
		__push_to_a(hold, data, &bol, 0);
		if (bol == 1)
			ft_sa(data);
		bol = 0;
	}
}
