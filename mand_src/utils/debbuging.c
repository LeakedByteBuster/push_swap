#include "push_swap.h"


void print_stacks(t_data data)
{
	t_node *tmp;

	// ft_pa(&data);
	tmp = data.s_a->head;
	/*Prints stack a*/
	printf("\nSTACK_A: ");
	// while (tmp)
	// {
	// 	printf("[ %d|cur_idx=%d|idx=%d ] ", tmp->data, tmp->cur_idx, tmp->idx);
	// 	tmp = tmp->next;
	// }
	while (tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}

	printf("\n\n");
	printf("STACK_B: ");
	tmp = data.s_b->head;
	// // ** prints stack B
	while (tmp)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n\n");
	printf("a_size = %d | b_size = %d | HEAD_A = %d | BOTM_A = %d | MIN_VAL_A = %d |  MAX_VAL_A = %d \n\n",
		   data.s_a->stk_size, data.s_b->stk_size, data.s_a->head->data, data.s_a->botm->data, data.s_a->min->data, data.s_a->max->data);
	return;
}

void test_instuctions(t_data *data, int ac)
{
	// ** Testing Instructions

	// **	pa pb pb ss
	for (size_t i = 0; i < 1000; i++)
	{
		ft_pa(data);
		ft_pb(data);
		ft_pb(data);
		ft_ss(data);
	}
	// // // **	pa sa
	for (size_t i = 0; i < 1000; i++)
	{
		ft_pa(data);
		ft_sa(data);
		ft_rr(data);
	}
	// // ** SINGLE INSTRUCTION LAB
	for (size_t i = 0; i < 100; i++)
	{
		ft_pa(data);
		// ft_sa(data);
		ft_rb(data);
		// // printf("1 : a_size = %d | b_size = %d | ac = %d \n\n", STK_SIZE_A, STK_SIZE_B, ac);
		ft_rrb(data);
		// // printf("2 : a_size = %d | b_size = %d | ac = %d \n\n", STK_SIZE_A, STK_SIZE_B, ac);
		ft_ra(data);
		ft_rr(data);
		ft_rrr(data);
	}
	(void)ac;
	ft_pb(data);
	// ft_rb(data);
	// ft_rb(data);
	// ft_rrb(data);
	// ft_pa(data);
	// ft_pb(data);
	// ft_pb(data);
	// ft_rrr(data);
	// ft_sb(data);
	// ft_pa(data);
	// ft_pb(data);
	// ft_pb(data);
	// ft_pb(data);
	// ft_pb(data);
	// ft_rra(data);
	// ft_rb(data);
	// printf("a_size = %d | b_size = %d | ac = %d | BOTM_A = %d | BOTM_B = %d\n\n",
	// 	   STK_SIZE_A, STK_SIZE_B, ac, BOTM_A->data, BOTM_B->data);
	return;
}

void fill_stk_b(t_data *data)
{
	for (int i = 0; i < 10; i++)
	{
		push_node(&HEAD_B, new_node(i));
		push_node(&HEAD_B, new_node(i - 100));
		push_node(&HEAD_B, new_node(i + 100));
		data->s_b->stk_size += 3;
	}
	BOTM_B = last_node(HEAD_B);
	return;
}

void lk()
{
	system("leaks push_swap");
}
