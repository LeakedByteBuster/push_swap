/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:47:54 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/02 12:01:31 by mfouadi          ###   ########.fr       */
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
