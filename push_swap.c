/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:52:48 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/18 10:00:28 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sa(t_stack **head_a)
{
	int			temp;

	temp = (*head_a)->num;
	(*head_a)->num = (*head_a)->next->num;
	(*head_a)->next->num = temp;
}

void	ra(t_stack **head_a)
{
	t_stack	*tempo;

	tempo = (*head_a);
	(*head_a) = (*head_a)->next;
	ft_lstadd_back(head, ft_lstnew(tempo->num));
}

void	pb(t_stack **head_a, t_stack **head_a)
{
	t_stack
}

void	rra(t_stack **head_a)
{
	t_stack	*tempo;
	int			temp;

	temp = ft_lstlast((*head_a))->num;
	ft_lstadd_front(head, ft_lstnew(temp));
	temp = ft_lstsize((*head_a));
	tempo = (*head_a);
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
	rra(&head_a);
	while (head_a)
	{
		printf("%d\n",head_a->num);
		head_a = head_a->next;
	}
}
