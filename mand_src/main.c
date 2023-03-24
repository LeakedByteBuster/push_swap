/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:51:07 by mfouadi           #+#    #+#             */
/*   Updated: 2023/03/24 05:50:43 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// * read, write, malloc, free, exit, ft_printf : Sort stacks
/*
**	if no parameters are specified, the program must not display anything and give the
		prompt back

**	The first argument should be at the top of the stack
**	Instructions must be separated by a '\n' and nothing else.
**	The goal is to sort the stack with the lowest possible number of operations
**	In case of error, it must display "Error" followed by a '\n' on the standard error.
		some arguments aren't integers, some arguments are bigger than an integer and/or there are duplicates
*/

void	print_stacks(t_data data)
{
	t_node *tmp;

	// ft_pa(&data);
	tmp = data.s_a->head;
	/*Prints stack a*/
	printf("STACK_A: ");
	while (tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	// ** Testing swap b
	printf("\n\n");
	printf("STACK_B: ");
	tmp = data.s_b->head;
	// // ** prints stack B
	while (tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n\n");
	return ;
}

void	test_instuctions(t_data *data, int ac)
{
	// ** Testing Instructions

	// **	pa pb pb ss
	for (size_t i = 0; i < 1000; i++)
	{
		ft_pa(data);
		ft_pb(data);
		ft_pb(data);
		ft_ss(data);
	}
	// // // **	pa sa
	for (size_t i = 0; i < 1000; i++)
	{
		ft_pa(data);
		ft_sa(data);
		ft_rr(data);
	}
	// // ** SINGLE INSTRUCTION LAB
	for (size_t i = 0; i < 100; i++)
	{
		ft_pa(data);
		// ft_sa(data);
		ft_rb(data);
		// // printf("1 : a_size = %d | b_size = %d | ac = %d \n\n", STK_SIZE_A, STK_SIZE_B, ac);
		ft_rrb(data);
		// // printf("2 : a_size = %d | b_size = %d | ac = %d \n\n", STK_SIZE_A, STK_SIZE_B, ac);
		ft_ra(data);
		ft_rr(data);
		ft_rrr(data);
	}
	(void)ac;
	ft_pb(data);
	ft_rb(data);
	ft_rb(data);
	ft_rrb(data);
	ft_pa(data);
	ft_pb(data);
	ft_pb(data);
	ft_rrr(data);
	ft_sb(data);
	ft_pa(data);
	ft_pb(data);
	ft_pb(data);
	ft_pb(data);
	ft_pb(data);
	ft_rra(data);
	ft_rb(data);
	// printf("a_size = %d | b_size = %d | ac = %d | BOTM_A = %d | BOTM_B = %d\n\n",
	// 	   STK_SIZE_A, STK_SIZE_B, ac, BOTM_A->data, BOTM_B->data);
	return ;
}

void	fill_stk_b(t_data *data)
{
	for (int i = 0; i < 10; i++)
	{
		push_node(&HEAD_B, new_node(i));
		push_node(&HEAD_B, new_node(i - 100));
		push_node(&HEAD_B, new_node(i+100));
		data->s_b->stk_size += 3;
	}
	BOTM_B = last_node(HEAD_B);
	return ;
}

void	lk()
{
	system("leaks a.out");
}

// **	Still have to check if input is sorted
// **	(ra rra || rb rrb) ==> leaks, (while(i < 1000) ==> SIGFAULT)
int main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		exit(1);
	// ** Parsing arguments
	parser(&data, ac, av);
	// printf("PARSER : HEAD_A = %d | stacka_size = %d \n\n", data.s_a->head->data, data.s_a->stk_size);

	//	** Fill Stack_b for testing instructions
	fill_stk_b(&data);

	// **	Test instructions
	// printf("INPUT: a_size = %d | b_size = %d | ac = %d \n\n", data.s_a->stk_size, data.s_b->stk_size, ac);
	test_instuctions(&data, ac);

	// **	Print content of both stacks
	print_stacks(data);
	// printf("\n\na_size = %d | b_size = %d | ac = %d | BOTM_A = %d | BOTM_B = %d\n",
	// 	   data.s_a->stk_size, data.s_b->stk_size, ac, data.s_a->botm->data, data.s_b->botm->data);
	
	printf("a_size = %d | b_size = %d | ac = %d HEAD_A = %d | HEAD_B = %d | BOTM_B = %d | BOTM_A = %d\n\n",
		   data.s_a->stk_size, data.s_b->stk_size, ac, data.s_a->head->data, data.s_b->head->data, data.s_b->botm->data, data.s_a->botm->data);

	// **	free both stacks
	free_stacks(&data);
	
	// **	Checks leaks
	atexit(lk);

	return (0);
}

