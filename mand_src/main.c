/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:51:07 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/01 10:51:13 by mfouadi          ###   ########.fr       */
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

int main(int ac, char **av)
{
	t_data	data;

	if (ac < 3)
		exit(77);
	// ** Parsing arguments
	parser(&data, ac, av);

	//	** Fill Stack_b for testing instructions
	// fill_stk_b(&data);
	// index_stack(data.s_a->head, data.s_a->stk_size);

	// **	Sorting
	// printf("\n\n****************** Instructions ******************\n");
	sort_that_shit(&data);
	// index_stack(data.s_a->head, data.s_a->stk_size);
	// current_index_instack(data.s_a->head, data.s_a->stk_size);

	// **	Test instructions
	// test_instuctions(&data, ac);
	
	// **	Print content of both stacks
	// print_stacks(data);

	// **	free both stacks
	free_stacks(&data);

	// **	Checks leaks
	// atexit(lk);
	
	return (0);
}
