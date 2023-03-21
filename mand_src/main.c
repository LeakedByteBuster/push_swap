/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:51:07 by mfouadi           #+#    #+#             */
/*   Updated: 2023/03/21 10:34:29 by mfouadi          ###   ########.fr       */
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

void	lk()
{
	system("leaks a.out");
}

int main(int ac, char **av)
{
	t_data	data;
	t_node	*tmp;

	if (ac < 2)
		exit(1);
	// ** Parsing arguments
	parser(&data, ac, av);

	/*Prints input as it is in stack a*/
	printf("\nstk_size = %d | ac = %d | last = %d \n", data.s_a->stk_size, ac, data.s_a->botm->data);
	tmp = data.s_a->head;
	while (data.s_a->stk_size-- != 0)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}

	// **	free both stacks
	free_stacks(&data);
	
	// **	Checks leaks
	// atexit(lk);
	return (0);
}

