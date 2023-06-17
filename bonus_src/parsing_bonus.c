/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 02:06:41 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/03 23:27:57 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_data(t_data *data)
{
	data->s_a = (t_a *)malloc(sizeof(t_a));
	data->s_b = (t_b *)malloc(sizeof(t_b));
	ft_bzero(data->s_a, sizeof(t_a));
	ft_bzero(data->s_b, sizeof(t_b));
}

static void	check_program_options(t_data *data, char **av, int *a)
{
	if (ft_strncmp(av[1], "-v", 2) == 0)
	{
		data->print_stacks = 1;
		*a = 1;
	}
	if (ft_strncmp(av[1], "-V", 2) == 0)
	{
		data->print_stacks_moves = 1;
		*a = 1;
	}
	return ;
}

static void	fill_stack_a(t_data *data, char **av, int ac)
{
	char	**tmp;
	int		i;
	int		a;

	i = 0;
	a = 0;
	check_program_options(data, av, &a);
	while (--ac != a)
	{
		tmp = ft_split(av[ac], ' ');
		if (!tmp || !(*tmp))
			return (free_stacks(data), err_msg(1), (void)0);
		i = 0;
		while (tmp[i])
			i++;
		while (i--)
		{
			push_node(&data->s_a->head, new_node(ft_atoi(tmp[i])));
			data->s_a->stk_size++;
			free(tmp[i]);
		}
		free(tmp);
	}
	data->s_a->botm = last_node(data->s_a->head);
}

static void	find_duplicate_nbr(t_data *data)
{
	t_node	*tmp;
	t_node	*tmp2;
	int		check;

	tmp = data->s_a->head;
	check = 0;
	while (tmp)
	{
		data->s_a->max = tmp;
		data->s_a->min = tmp;
		check = tmp->data;
		tmp2 = tmp;
		while (tmp2->next)
		{
			tmp2 = tmp2->next;
			if (tmp2->data == check)
				err_msg(1);
		}
		tmp = tmp->next;
	}
	return ;
}

void	parser_bonus(t_data *data, int ac, char **av)
{	
	init_data(data);
	fill_stack_a(data, av, ac);
	find_duplicate_nbr(data);
	min_max(data, data->s_a->head);
	index_stack(data->s_a->head, data->s_a->stk_size);
	current_index_instack(data->s_a->head, data->s_a->stk_size);
	return ;
}
