/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:15:03 by mfouadi           #+#    #+#             */
/*   Updated: 2023/03/21 12:24:09 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"

#define HEAD_A data->s_a->head
#define HEAD_B data->s_b->head

#define BOTM_A data->s_a->botm
#define BOTM_B data->s_b->botm

#define STK_SIZE_A data->s_a->stk_size
#define STK_SIZE_B data->s_b->stk_size

typedef struct s_node t_node;

// **	Initial stack that contains the given values 
typedef struct	stack_a
{
	t_node		*head;
	t_node		*botm;
	int			stk_size;
}	t_a;

// **	Empty stack used for sorting
typedef struct stack_b
{
	t_node	*head;
	t_node	*botm;
	int		stk_size;
}	t_b;

typedef struct s_data
{
	t_a	*s_a;
	t_b	*s_b;
}	t_data;


// **	Parses arguments
void	parser(t_data *data, int ac, char **av);
// **	Prints "Error" on STDERR, and exit with the given status
void	err_msg(int status);
// **	Frees stack_a and stack_b
void	free_stacks(t_data *data);

/* ************* Instuctions ************* */
// **	Swaps the two elements at top of stack A
void	ft_sa(t_data *data);
// **	Swaps the two elements at top of stack B
void	ft_sb(t_data *data);
// **	sa and sb at the same time
void	ft_ss(t_data *data);
// ** Take the first element at the top of b and put it at the top of a.
void	ft_pa(t_data *data);

#endif // PUSH_SWAP_H
