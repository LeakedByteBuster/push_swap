/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 03:50:21 by mfouadi           #+#    #+#             */
/*   Updated: 2023/03/29 09:07:08 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_msg(int status)
{
	write(2, "Error\n", 7);
	exit(status);
}

void	free_stacks(t_data *data)
{
	clear_node(&data->s_a->head);
	clear_node(&data->s_b->head);
	free(data->s_a);
	free(data->s_b);
	return ;
}

void	min_max(t_data *data, t_node *head)
{
	t_node *tmp;

	tmp = head;
	MAX_VAL_A = tmp;
	MIN_VAL_A = tmp;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->data > MAX_VAL_A->data)
			MAX_VAL_A = tmp;
		if (tmp->data < MIN_VAL_A->data)
			MIN_VAL_A = tmp;
	}
}

void	index_stack(t_node *head, int stk_size)
{
	t_node	*tmp;
	t_node	*tmp_2;
	int k = 0;
	int i = 0;
	
	tmp = head;
	while (i < stk_size)
	{
		tmp_2 = head;
		k = 0;
		tmp->idx = 0;
		while (k < stk_size)
		{
			if ((tmp->data > tmp_2->data) && (i != k))
				tmp->idx++;
			tmp_2 = tmp_2->next;
			k++;
		}
		tmp = tmp->next;
		i++;
	}
	return ;
}

void	current_index_instack(t_node *head, int n)
{
	t_node	*tmp;
	int		i;

	tmp = head;
	i = 0;
	while (i < n)
	{
		tmp->cur_idx = 0;
		tmp->cur_idx = i;
		i++;
		tmp = tmp->next;
	}
	return ;
}

bool	if_sorted_stop(t_node *head, int n)
{
	t_node	*node;
	int		i;

	i = n;
	node = head;
	while (i--)
	{
		if (node->next && (node->data < node->next->data))
			node = node->next;
		else
			break;
	}
	if (i == 0)
		return (1);
	return (0);
}
