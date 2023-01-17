/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:52:48 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/17 13:52:55 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sa(t_stack_a **head)
{
	int			temp;

	temp = (*head)->num;
	(*head)->num = (*head)->next->num;
	(*head)->next->num = temp;
	while ((*head))
	{
		printf("%d\n", (*head)->num);
		(*head) = (*head)->next;
	}
}

void	ra(t_stack_a **head)
{
	int			temp;
	t_stack_a	*tempo;

	tempo = (*head)->next;
	temp = (*head)->num;
	while (tempo)
	{
		if (!tempo->next)
			break ;
		tempo = tempo->next;
	}
	printf("%d\n", tempo->num);
	(*head)->num = tempo->num;
	// temp = (*head)->num;
	// (*head)->num = (*head)->next->num;
	// (*head)->next->num = temp;
	// printf("%d\n", (*head)->num);
}

int	main(int argc, char *argv[])
{
	t_stack_a	*head;
	t_stack_a	*tempo;

	head = ft_lstnew(ft_atoi(argv[argc - 1]));
	argc -= 2;
	while (argc > 0)
	{
		ft_lstadd_front(&head, ft_lstnew(ft_atoi(argv[argc])));
		argc--;
	}
	tempo = head;
	printf("9abla\n");
	while (head)
	{
		printf("%d\n",head->num);
		head = head->next;
	}
	printf("ba3da\n");
	// sa(&tempo);
	ra(&tempo);
}
