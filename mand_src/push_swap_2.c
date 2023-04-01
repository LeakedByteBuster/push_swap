/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:47:27 by mfouadi           #+#    #+#             */
/*   Updated: 2023/04/01 07:23:24 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/inc/libft.h"

void	sort_a_bunch(t_data *data, int div)
{
	int		i = -1;
	int 	k;
	int		min_idx = 0;
	int		chunck_len;
	int		half_chunk;

	chunck_len = (STK_SIZE_A / div);
	int mod = 0;
	mod = (STK_SIZE_A % div);
	int g = chunck_len;
	half_chunk = chunck_len / 2;
	k = 0;
	while (HEAD_A && ++i < div)
	{
		// min_idx = k;
		if (i == div - 1)
			chunck_len += mod;
		printf("STK_SIZE= %d | minidx= %d | chucklen = %d | halfchunck = %d | k = %d\n", STK_SIZE_A, min_idx, chunck_len, half_chunk, k);
		while (HEAD_A && (k <= chunck_len))
		{
			if ((HEAD_A->idx >= min_idx) && (HEAD_A->idx <= chunck_len))
			{
				if (HEAD_A->idx <= half_chunk)
				{
					ft_pb(data);
					ft_rb(data);
				}
				else
					ft_pb(data);
				k++;
			}
			else
			{
				// printf("i= %d | data = %d | minidx= %d | HED_INDX=%d  | chucklen = %d | halfchunck = %d\n", i, HEAD_A->data, min_idx, HEAD_A->idx, chunck_len, half_chunk);
				ft_ra(data);
			}
		}
		min_idx += g;
		chunck_len += g;
		half_chunk += g;
	printf("\nHEY\n");
	}
	// printf("stk_b size = %d", STK_SIZE_B);
	return ;
}

/*
void	sort_a_bunch(t_data *data, int div)
{
	int		i = -1;
	int 	k;
	int		min_idx = 0;
	int		chunck_len;
	int		half_chunk;

	int g = div;
	int d = STK_SIZE_A;
	chunck_len = (STK_SIZE_A / div);
	half_chunk = chunck_len / 2;
	k = 0;
	while (HEAD_A && ++i < div)
	{
		// min_idx = k;
		printf("STK_SIZE= %d | minidx= %d | chucklen = %d | halfchunck = %d | k = %d\n", STK_SIZE_A, min_idx, chunck_len, half_chunk, k);
		while (HEAD_A && (k <= chunck_len))
		{
			if ((HEAD_A->idx >= min_idx) && (HEAD_A->idx <= chunck_len))
			{
				printf("i= %d | data = %d | minidx= %d | HED_INDX=%d  | chucklen = %d | halfchunck = %d\n", i, HEAD_A->data, min_idx, HEAD_A->idx, chunck_len, half_chunk);
				// printf("%d | idx=%d | k=%d | c_l=%d\n", HEAD_A->data, HEAD_A->idx, k, chunck_len);
				ft_pb(data);
				k++;
			}
			else
			{
				// printf("i= %d | data = %d | minidx= %d | HED_INDX=%d  | chucklen = %d | halfchunck = %d\n", i, HEAD_A->data, min_idx, HEAD_A->idx, chunck_len, half_chunk);
				ft_ra(data);
			}
		}
		min_idx += (d / g);
		chunck_len += (d / --g);
	}
	return ;
}
*/
