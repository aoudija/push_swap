/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:52:48 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/25 13:10:09 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*head_a;
	t_stack	*head_b;
	int		*tab;
	int		*r_max_tab;
	int		size;

	head_a = ft_lstnew(ft_atoi(argv[argc - 1]));
	argc -= 2;
	while (argc > 0)
	{
		ft_lstadd_front(&head_a, ft_lstnew(ft_atoi(argv[argc])));
		argc--;
	}
	if (ft_lstsize(head_a) == 3)
		sort_three(&head_a);
	else if (ft_lstsize(head_a) == 5)
		sort_five(&head_a, &head_b);
	else
	{
		tab = sorted_in_tab(head_a);
		push_to_stack_b(tab, &head_a, &head_b, ft_lstsize(head_a));
		size = ft_lstsize(head_b);
		tab = sorted_in_tab(head_b);
		r_max_tab = sorted_max_tab(tab, size);
		push_to_stack_a(&head_b, &head_a, r_max_tab, size);
	}
	// while (head_b)
	// {
	// 	printf("%d\n", head_b->num);
	// 	head_b = head_b->next;
	// }
	// while (head_a)
	// {
	// 	printf("%d\n", head_a->num);
	// 	head_a = head_a->next;
	// }
}
