/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:52:48 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/18 11:04:38 by aoudija          ###   ########.fr       */
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

void	sb(t_stack **head_b)
{
	int			temp;

	temp = (*head_b)->num;
	(*head_b)->num = (*head_b)->next->num;
	(*head_b)->next->num = temp;
}

void	ra(t_stack **head_a)
{
	t_stack	*tempo;

	tempo = (*head_a);
	(*head_a) = (*head_a)->next;
	ft_lstadd_back(head_a, ft_lstnew(tempo->num));
}

void	rb(t_stack **head_b)
{
	t_stack	*tempo;

	tempo = (*head_b);
	(*head_b) = (*head_b)->next;
	ft_lstadd_back(head_b, ft_lstnew(tempo->num));
}

void	rra(t_stack **head_a)
{
	t_stack	*tempo;
	int			temp;

	temp = ft_lstlast((*head_a))->num;
	ft_lstadd_front(head_a, ft_lstnew(temp));
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

void	rrb(t_stack **head_b)
{
	t_stack	*tempo;
	int			temp;

	temp = ft_lstlast((*head_b))->num;
	ft_lstadd_front(head_b, ft_lstnew(temp));
	temp = ft_lstsize((*head_b));
	tempo = (*head_b);
	while (tempo)
	{
		if (temp == 2)
			break ;
		tempo = tempo->next;
		temp--;
	}
	tempo->next = NULL;
}

void	rr(t_stack **head_b, t_stack **head_a)
{
	ra(head_a);
	rb(head_b);
}

void	ss(t_stack **head_b, t_stack **head_a)
{
	sa(head_a);
	sb(head_b);
}

void	rrr(t_stack **head_b, t_stack **head_a)
{
	rra(head_a);
	rrb(head_b);
}

void	pb(t_stack **head_b, t_stack **head_a)
{
	t_stack	*tempo;
	int		temp;

	temp = (*head_a)->num;
	(*head_a) = (*head_a)->next;
	ft_lstadd_front(head_b, ft_lstnew(temp));
}

void	pa(t_stack **head_b, t_stack **head_a)
{
	t_stack	*tempo;
	int		temp;

	temp = (*head_b)->num;
	(*head_b) = (*head_b)->next;
	ft_lstadd_front(head_a, ft_lstnew(temp));
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
