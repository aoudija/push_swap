/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:52:48 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/17 10:10:38 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sa(t_stack_a *head)
{
	t_stack_a	*temp;

	temp = head->next;
	head->next = head;
	head = temp;
	while (head)
	{
		printf("%d\n", head->num);
		head = head->next;
	}
}

int	main(int argc, char *argv[])
{
	t_stack_a	*head;

	head = ft_lstnew(ft_atoi(argv[argc - 1]));
	argc -= 2;
	while (argc > 0)
	{
		ft_lstadd_front(&head, ft_lstnew(ft_atoi(argv[argc])));
		argc--;
	}
	sa(head);
}
