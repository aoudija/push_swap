/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:19:27 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/25 13:11:11 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **head_a)
{
	int			temp;

	temp = (*head_a)->num;
	(*head_a)->num = (*head_a)->next->num;
	(*head_a)->next->num = temp;
	printf("sa\n");
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
	printf("ra\n");
}

void	rb(t_stack **head_b)
{
	t_stack	*tempo;

	tempo = (*head_b);
	(*head_b) = (*head_b)->next;
	ft_lstadd_back(head_b, ft_lstnew(tempo->num));
	printf("rb\n");
}

void	rra(t_stack **head_a)
{
	t_stack	*tempo;
	int		temp;

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
	printf("rra\n");
}
