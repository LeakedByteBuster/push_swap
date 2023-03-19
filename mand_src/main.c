/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:51:07 by mfouadi           #+#    #+#             */
/*   Updated: 2023/03/19 08:38:45 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_bubble(int a[], int n)
// {
// 	printf("Bubble sort		input=%d:	", n);
// 	for (int i = 0; i < n; i++)
// 		printf("%d ", a[i]);
// 	printf("\n");
// }

// void	print_insertion(int a[], int n)
// {
// 	printf("Insertion sort		input=%d:	", n);
// 	for (int i = 0; i < n; i++)
// 		printf("%d ", a[i]);
// 	printf("\n");
// }

// void	print_opt_bubsort(int a[], int n)
// {
// 	printf("Opt bubble sort		input=%d:	", n);
// 	for (int i = 0; i < n; i++)
// 		printf("%d ", a[i]);
// 	printf("\n");
// }

// void	print_selectsort(int a[], int n)
// {
// 	printf("Select sort		input=%d:	", n);
// 	for (int i = 0; i < n; i++)
// 		printf("%d ", a[i]);
// 	printf("\n");
// }

// int	main()
// {
// 	int	a[] = {6, 2, 3, 4};
// 	int n = sizeof(a) / sizeof(int);
// 	// bubble_sort(a, n);
// 	// print_bubble(a, n);
	
// 	// int b[] = {1, 2, 66, -565, -5, 644, 22, 33, 0, 01, 1004, 9999, -98, 54, -9956, 8745, -663, -662, -661, 50, 10000};
// 	// int n1 = sizeof(a) / sizeof(int);
// 	// opt_bubble_sort(b, n1);
// 	// print_opt_bubsort(b, n1);
	
// 	// int c[] = {1, 2, 66, -565, -5, 644, 22, 33, 0, 01, 1004, 9999, -98, 54, -9956, 8745, -663, -662, -661, 50, 10000};
// 	// int n2 = sizeof(c) / sizeof(int);
// 	// insertion_sort(c, n2);
// 	// print_insertion(c, n2);

// 	// int d[] = {1, 2, 66, -565, -5, 644, 22, 33, 0, 01, 1004, 9999, -98, 54, -9956, 8745, -663, -662, -661, 50, 10000};
// 	// int n3 = sizeof(d) / sizeof(int);
// 	// selection_sort(d, n3);
// 	// print_selectsort(d, n3);
// 	merge_sort(a, 0, n);
// 	printf("\nFinished\n");

// }

int	main(int ac, char **av)
{
	int i = 1;
	t_node	*p;
	t_node	*head;
	
	if (ac < 2)
		exit(1);
	while (ac != 1)
	{
		p = new_node(av[i]);
		addback_node(&head, p);
		i++;
		ac--;
	}
	push_node(&head, new_node(av[8]));
	addafter_node(head, new_node(av[7]));
	addbefore_node(head->next, new_node(av[6]));
	p = head;
	while (p)
	{
		printf("%s\n", p->data);
		p = p->next;
	}
	// printf("last node == %s\n", head->next->data);
	printf("last node == %s\n", last_node(head)->data);
	return (0);
}
