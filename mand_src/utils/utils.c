/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 03:50:21 by mfouadi           #+#    #+#             */
/*   Updated: 2023/03/21 10:21:11 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	err_msg(int status)
{
	write(2, "Error\n", 7);
	exit(status);
}

void	free_stacks(t_data *data)
{
	clear_node(&data->s_a->head);
	clear_node(&data->s_b->head);
	free(data->s_a);
	free(data->s_b);
	return ;
}
