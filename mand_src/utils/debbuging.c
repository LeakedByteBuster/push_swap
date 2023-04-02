/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debbuging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:50:22 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/02 15:24:30 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void print_stacks(t_data data)
// {
// 	t_node *tmp;

// 	// ft_pa(&data);
// 	tmp = data.s_a->head;
// 	/*Prints stack a*/
// 	printf("\nSTACK_A: ");
// 	// while (tmp)
// 	// {
// 	// 	printf("[ %d|cur_idx=%d|idx=%d ] ", tmp->data, tmp->cur_idx, tmp->idx);
// 	// 	tmp = tmp->next;
// 	// }
// 	while (tmp)
// 	{
// 		printf("%d ", tmp->data);
// 		tmp = tmp->next;
// 	}
// // ********************************************
// 	printf("\n\n");
// 	printf("STACK_B: ");
// 	tmp = data.s_b->head;
// 	// while (tmp)
// 	// {
// 	// 	printf("[ %d|cur_idx=%d|idx=%d ] ", tmp->data, tmp->cur_idx, tmp->idx);
// 	// 	tmp = tmp->next;
// 	// }
// 	// // ** prints stack B
// 	while (tmp)
// 	{
// 		printf("%d ", tmp->data);
// 		tmp = tmp->next;
// 	}
// 	printf("\n\n");
// 	return;
// }

// void test_instuctions(t_data *data, int ac)
// {
// 	// ** Testing Instructions

// 	// **	pa pb pb ss
// 	for (size_t i = 0; i < 100054; i++)
// 	{
// 		ft_pa(data);
// 		ft_pb(data);
// 		ft_pb(data);
// 		ft_pa(data);
// 		// ft_ss(data);
// 	}
// 	for (size_t i = 0; i < 10051; i++)
// 	{
// 	ft_pa(data);
// 	ft_pb(data);
// 	ft_pb(data);
// 		ft_rb(data);
// 	// ft_ss(data);
// 	}
// 	ft_pb(data);
// 	ft_pb(data);
// 	(void)ac;
// 	// printf("a_size = %d | b_size = %d | ac = %d | BOTM_A = %d | BOTM_B = %d",
// 	// 	   STK_SIZE_A, STK_SIZE_B, ac, BOTM_A->data, BOTM_B->data);
// 	return;
// }

// void fill_stk_b(t_data *data)
// {
// 	for (int i = 0; i < 10; i++)
// 	{
// 		push_node(&HEAD_B, new_node(i));
// 		push_node(&HEAD_B, new_node(i - 100));
// 		push_node(&HEAD_B, new_node(i + 100));
// 		data->s_b->stk_size += 3;
// 	}
// 	BOTM_B = last_node(HEAD_B);
// 	return;
// }
