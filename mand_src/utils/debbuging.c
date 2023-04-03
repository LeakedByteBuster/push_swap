/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debbuging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:50:22 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/03 05:52:26 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_data data)
{
	t_node *tmp;

	tmp = data.s_a->head;
	ft_printf("\033[1;31m");
	ft_printf("\nSTACK_A: ");
	ft_printf("\033[0m");
	while (tmp)
	{
		ft_printf("%d ", tmp->data);
		tmp = tmp->next;
	}

// ********************************************
	ft_printf("\n\n");
	ft_printf("\033[1;32m");
	ft_printf("STACK_B: ");
	ft_printf("\033[0m");
	tmp = data.s_b->head;
	while (tmp)
	{
		ft_printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	ft_printf("\n\n");
	return;
}
