/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:51:07 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/02 11:26:43 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

#include "push_swap.h"

int main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		exit(1);
	// ** Parsing arguments
	parser(&data, ac, av);
	// **	Sorting
	sort_that_shit(&data);
	// **	Print content of both stacks
	// print_stacks(data);
	// **	free both stacks
	free_stacks(&data);
	return (0);
}
