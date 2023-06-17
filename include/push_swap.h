/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:15:03 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/03 18:31:55 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"

// **	node struct (libft.h)
typedef struct s_node	t_node;

// **	Initial stack that contains the given values 
typedef struct stack_a
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
	t_a		*s_a;
	t_b		*s_b;
	bool	print_stacks;
	bool	print_stacks_moves;
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

// **	Shift up all elements of stack a by 1.first element becomes the last one
void	ft_ra(t_data *data);
// **	Shift up all elements of stack b by 1.first element becomes the last one
void	ft_rb(t_data *data);
// **	ra and rb at the same time
void	ft_rr(t_data *data);

// **	Shift down all elements of stack a by 1.last element becomes the first
void	ft_rra(t_data *data);
// **	Shift down all elements of stack b by 1.last element becomes the first
void	ft_rrb(t_data *data);
// **	rra and rrb at the same time
void	ft_rrr(t_data *data);
// **	Index stack_A
/********************* Sorting ********************/

// **	Sort the given integers
void	sort_that_shit(t_data *data);
// **	Where the values should be placed
void	index_stack(t_node *head, int stk_size);
// **	Where the values are placed currently
void	current_index_instack(t_node *head, int n);
// **	Check if stack is sorted or not yet
bool	if_sorted_stop(t_node *head, int n);
// **	Starting from min val in A, keep pushing to B until STK_SIZE_A = 0
void	push_to_b(t_data *data, int div, int chunk_len, int half_chunk);
// **	Starting from max val in B, keep pushing to A until STK_SIZE_B = 0
void	push_to_a(t_data *data);

void	three_sort(t_data *data);
t_node	*get_node_position(t_data *data, int idx);
int		nbr_of_moves(int big, int small, int stk_size);
void	__assign_idx(t_node *head, int *arr, int stk_size);

//******************* BONUS ********************
// **	Swaps the two elements at top of stack A
void	ftb_sa(t_data *data);
// **	Swaps the two elements at top of stack B
void	ftb_sb(t_data *data);
// **	sa and sb at the same time
void	ftb_ss(t_data *data);

// **	Take the first element at the top of b and put it at the top of a
void	ftb_pa(t_data *data);
// **	Take the first element at the top of a and put it at the top of b
void	ftb_pb(t_data *data);

// **	Shift up all elements of stack a by 1.first element becomes the last one
void	ftb_ra(t_data *data);
// **	Shift up all elements of stack b by 1.first element becomes the last one
void	ftb_rb(t_data *data);
// **	ra and rb at the same time
void	ftb_rr(t_data *data);
// **	Shift down all elements of stack a by 1.last element becomes the first
void	ftb_rra(t_data *data);
// **	Shift down all elements of stack b by 1.last element becomes the first
void	ftb_rrb(t_data *data);
// **	rra and rrb at the same time
void	ftb_rrr(t_data *data);
// **	Parse given arguments, and stores them in STACK_A
void	parser_bonus(t_data *data, int ac, char **av);

/********************* Debugging ********************/
// void	fill_stk_b(t_data *data);
// void	test_instuctions(t_data *data, int ac);
void	print_stacks(t_data data);

#endif // PUSH_SWAP_H
