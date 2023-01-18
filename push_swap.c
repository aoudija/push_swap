/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:52:48 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/18 09:28:30 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sa(t_stack_a **head)
{
	int			temp;

	temp = (*head)->num;
	(*head)->num = (*head)->next->num;
	(*head)->next->num = temp;
}

void	ra(t_stack_a **head)
{
	t_stack_a	*tempo;

	tempo = (*head);
	(*head) = (*head)->next;
	ft_lstadd_back(head, ft_lstnew(tempo->num));
}

void	rra(t_stack_a **head)
{
	t_stack_a	*tempo;
	int			temp;

	temp = ft_lstlast((*head))->num;
	ft_lstadd_front(head, ft_lstnew(temp));
	temp = ft_lstsize((*head));
	tempo = (*head);
	while (tempo)
	{
		if (temp == 2)
			break ;
		tempo = tempo->next;
		temp--;
	}
	tempo->next = NULL;
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
	ra(&head);
	sa(&head);
	rra(&head);
}
