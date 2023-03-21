/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 09:06:31 by mfouadi           #+#    #+#             */
/*   Updated: 2023/03/21 11:52:51 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_data(t_data *data)
{
	data->s_a = (t_a *)malloc(sizeof(t_a));
	data->s_b = (t_b *)malloc(sizeof(t_b));
	ft_bzero(data->s_a, sizeof(t_a));
	ft_bzero(data->s_b, sizeof(t_b));
}

void	fill_stack_a(t_data *data, char **av, int ac)
{
	char **tmp;
	int i;

	i = 0;
	while (--ac != 0)
	{
		tmp = ft_split(av[ac], ' ');
		if (!tmp || !(*tmp))
			return (free_stacks(data), err_msg(1), (void)0);
		i = 0;
		while (tmp[i])
			i++;
		while (i--)
		{
			push_node(&HEAD_A, new_node(ft_atoi(tmp[i])));
			STK_SIZE_A++;
			free(tmp[i]);
		}
		free(tmp);
	}
	BOTM_A = last_node(HEAD_A);
}

void	find_duplicate_nbr(t_data *data)
{
	t_node *tmp;
	t_node *tmp2;
	int		check;

	tmp = HEAD_A;
	check = 0;
	while (tmp)
	{
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

void	parser(t_data *data, int ac, char **av)
{	
	init_data(data);
	fill_stack_a(data, av, ac);
	find_duplicate_nbr(data);
	return ;
}
