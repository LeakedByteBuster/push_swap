/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:47:54 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/02 14:44:12 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// same problem here as function ss
// **	rra and rrb at the same time
void	ft_rrr(t_data *data)
{
	ft_rra(data);
	ft_rrb(data);
	write(1, "rrr\n", 4);
	return ;
}

// potentiel problem of printing sb and sa then ss
// **	sa and sb at the same time
void	ft_ss(t_data *data)
{
	ft_sa(data);
	ft_sb(data);
	write(1, "ss\n", 3);
	return ;
}

void	min_max(t_data *data, t_node *head)
{
	t_node	*tmp;

	if (!head)
		return ;
	tmp = head;
	data->s_a->max = tmp;
	data->s_a->min = tmp;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->data > data->s_a->max->data)
			data->s_a->max = tmp;
		if (tmp->data < data->s_a->min->data)
			data->s_a->min = tmp;
	}
}

void	three_sort(t_data *data)
{
	t_node	*mid;

	mid = data->s_a->head->next;
	if (mid->idx == 0)
	{
		if (data->s_a->botm->idx == 1)
			return (ft_rra(data), ft_rra(data), (void)0);
		if (data->s_a->botm->idx == 2)
			return (ft_sa(data), (void)0);
	}
	else if (mid->idx == 1)
	{
		if (data->s_a->botm->idx == 0)
			return (ft_sa(data), ft_rra(data), (void)0);
	}
	else if (mid->idx == 2)
	{
		if (data->s_a->botm->idx == 0)
			return (ft_rra(data), (void)0);
		else
			return (ft_rra(data), ft_sa(data), (void)0);
	}
}

t_node	*get_node_position(t_data *data, int idx)
{
	t_node	*tmp;
	int		j;

	j = 0;
	tmp = data->s_b->head;
	while (j < data->s_b->stk_size)
	{
		if (tmp->idx == idx)
			return (tmp);
		tmp = tmp->next;
		j++;
	}
	return (NULL);
}
