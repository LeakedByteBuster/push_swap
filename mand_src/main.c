/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:51:07 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/02 15:24:45 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// * read, write, malloc, free, exit, ft_printf : Sort stacks
/*
**	if no parameters are specified, the program must not display anything
		and give theprompt back
**	The first argument should be at the top of the stack
**	Instructions must be separated by a '\n' and nothing else.
**	The goal is to sort the stack with the lowest possible number of operations
**	In case of error, it must display "Error" followed by a '\n' on 
		the standard error. some arguments aren't integers, some arguments 
		are bigger than an integer and/or there are duplicates
*/

#include "push_swap.h"

/*
ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`; 
./push_swap $ARG | wc -l && ./push_swap $ARG | ./checker $ARG
*/
int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		exit(1);
	parser(&data, ac, av);
	sort_that_shit(&data);
	free_stacks(&data);
	return (0);
}
