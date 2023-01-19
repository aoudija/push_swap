/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:52:48 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/19 13:58:08 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char *argv[])
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*tempo;

	head_a = ft_lstnew(ft_atoi(argv[argc - 1]));
	argc -= 2;
	while (argc > 0)
	{
		ft_lstadd_front(&head_a, ft_lstnew(ft_atoi(argv[argc])));
		argc--;
	}
	// ra(&head_a);
	// sa(&head_a);
	// rra(&head_a);
	pb(&head_b, &head_a);
	pb(&head_b, &head_a);
	pb(&head_b, &head_a);
	// pb(&head_b, &head_a);
	// pa(&head_b, &head_a);
	// sb(&head_b);
	// rb(&head_b);
	// rrb(&head_b);
	// rrr(&head_b, &head_a);
	// rr(&head_b, &head_a);
	tempo = head_b;
	while (tempo)
	{
		printf("%d\n",tempo->num);
		tempo = tempo->next;
	}
	printf("-b-\n");
	tempo = head_a;
	while (tempo)
	{
		printf("%d\n",tempo->num);
		tempo = tempo->next;
	}
	printf("-a-\n");
}
