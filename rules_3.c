/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:50:18 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/29 10:08:05 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack **head_b)
{
	t_stack	*tempo;
	int		temp;

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
	free(tempo->next);
	tempo->next = NULL;
	ft_putstr("rrb\n");
}

void	rr(t_stack **head_b, t_stack **head_a)
{
	ra(head_a);
	rb(head_b);
	ft_putstr("rr\n");
}

void	ss(t_stack **head_b, t_stack **head_a)
{
	sa(head_a);
	sb(head_b);
	ft_putstr("ss\n");
}

void	rrr(t_stack **head_b, t_stack **head_a)
{
	rra(head_a);
	rrb(head_b);
	ft_putstr("rrr\n");
}
