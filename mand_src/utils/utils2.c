/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:31:05 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/02 14:07:07 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (small < (stk_size / 2))
		s = small + 2;
	else
		s = stk_size - small + 2;
	if (s < b)
		return (1);
	return (0);
}

void	__assign_idx(t_node *head, int *arr, int stk_size)
{
	t_node	*tmp;
	int		i;
	int		k;

	i = -1;
	tmp = head;
	while (++i < stk_size)
	{
		k = -1;
		while (++k < stk_size)
			if (tmp->data == arr[k])
				tmp->idx = k;
		tmp = tmp->next;
	}
}
