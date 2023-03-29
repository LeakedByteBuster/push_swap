/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:15:03 by mfouadi           #+#    #+#             */
/*   Updated: 2023/03/29 09:05:40 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"

#define STK_A data->s_a
#define STK_B data->s_b

#define HEAD_A data->s_a->head
#define HEAD_B data->s_b->head

#define BOTM_A data->s_a->botm
#define BOTM_B data->s_b->botm

#define STK_SIZE_A data->s_a->stk_size
#define STK_SIZE_B data->s_b->stk_size

#define MIN_VAL_A data->s_a->min
#define MAX_VAL_A data->s_a->max

#define MIN_VAL_B data->s_b->min
#define MAX_VAL_B data->s_b->max

// **	node struct (libft.h)
typedef struct s_node	t_node;

// **	Initial stack that contains the given values 
typedef struct	stack_a
{
	t_node		*head;
	t_node		*botm;
	t_node		*min;
	t_node		*max;
	int			stk_size;
}	t_a;

// **	Empty stack used for sorting
typedef struct stack_b
{
	t_node	*head;
	t_node	*botm;
	t_node	*min;
	t_node	*max;
	int		stk_size;
}	t_b;

typedef struct s_data
{
	t_a	*s_a;
	t_b	*s_b;
}	t_data;

/********************* Parser ********************/

// **	Parses arguments
void	parser(t_data *data, int ac, char **av);
// **	Retrive min and max values from given stack
void	min_max(t_data *data, t_node *head);

// **	Prints "Error" on STDERR, and exit with the given status
void	err_msg(int status);

/********************* Freeing Stacks ********************/

// **	Frees stack_a and stack_b
void	free_stacks(t_data *data);

/********************* Instuctions ********************/

// **	Swaps the two elements at top of stack A
void	ft_sa(t_data *data);
// **	Swaps the two elements at top of stack B
void	ft_sb(t_data *data);
// **	sa and sb at the same time
void	ft_ss(t_data *data);

// **	Take the first element at the top of b and put it at the top of a
void	ft_pa(t_data *data);
// **	Take the first element at the top of a and put it at the top of b
void	ft_pb(t_data *data);

// **	Shift up all elements of stack a by 1. The first element becomes the last one
void	ft_ra(t_data *data);
// **	Shift up all elements of stack b by 1. The first element becomes the last one
void	ft_rb(t_data *data);
// **	ra and rb at the same time
void	ft_rr(t_data *data);

// **	Shift down all elements of stack a by 1. The last element becomes the first one.
void	ft_rra(t_data *data);
// **	Shift down all elements of stack b by 1. The last element becomes the first one.
void	ft_rrb(t_data *data);
// **	rra and rrb at the same time
void	ft_rrr(t_data *data);
// **	Index stack_A

/********************* Sorting ********************/

// **	Sort given integers
void	sort_that_shit(t_data *data);

void	index_stack(t_node *head, int stk_size);

void	current_index_instack(t_node *head, int n);

bool	if_sorted_stop(t_node *head, int n);

/********************* Debugging ********************/
void	lk();
void	fill_stk_b(t_data *data);
void	test_instuctions(t_data *data, int ac);
void	print_stacks(t_data data);

#endif // PUSH_SWAP_H
