/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:33:13 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/03 03:29:41 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Write a program named checker that takes as an argument the moveck a 
	formatted as a list of integers. The first argument should be at the top of 
	the stack (be careful about the order). If no argument is given, it stops 
	and displays nothing
*/
#include "push_swap.h"

static void	read_stdin(t_list **moves)
{
	char	*tmp;
	int		i;

	i = 0;
	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		tmp[ft_strlen(tmp)] = 0;
		ft_lstadd_back(&(*moves), ft_lstnew(tmp));
		i++;
	}
}

static void	which_move_is_2(t_data *data, char *move)
{
	if (ft_strncmp(move, "rb\n", 3) == 0)
		ftb_rb(data);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		ftb_rr(data);
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		ftb_rra(data);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		ftb_rrb(data);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		ftb_rra(data);
	else
	{
		write(2, "Error\n", 22);
		exit(1);
	}
	return ;
}

// pa pb -- sa sb ss -- ra rb rr -- rra rrb rrr
static void	which_move_is(t_data *data, char *move)
{
	if (!move)
		exit(2);
	if (ft_strncmp(move, "pa\n", 3) == 0)
		ftb_pa(data);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		ftb_pb(data);
	else if (ft_strncmp(move, "sa\n", 3) == 0)
		ftb_sa(data);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		ftb_sb(data);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		ftb_ss(data);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		ftb_ra(data);
	else
		which_move_is_2(data, move);
	return ;
}

static void	exec_move(t_data *data, t_list *moves)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = moves;
	while (tmp)
	{
		which_move_is(data, tmp->content);
		tmp = tmp->next;
	}
	return ;
}

int	main(int ac, char **av)
{
	t_data	data;
	t_list	*moves;

	if (ac < 2)
		return (1);
	parser_bonus(&data, ac, av);
	read_stdin(&moves);
	if (moves)
		exec_move(&data, moves);
	ft_lstclear(&moves, free);
	if ((if_sorted_stop(data.s_a->head, data.s_a->stk_size) == 1)
		&& (data.s_b->stk_size == 0))
	{
		write(2, "OK\n", 3);
	}
	else
	{
		write(1, "KO\n", 3);
	}
	free_stacks(&data);
	return (0);
}
