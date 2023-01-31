/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:50:18 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/30 20:22:28 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack **head_b, int i)
{
	t_stack	*tempo;
	int		temp;

	if (!(*head_b))
		return ;
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
	if (i == 1)
		ft_putstr("rrb\n");
}

void	rr(t_stack **head_b, t_stack **head_a, int i)
{
	ra(head_a, 0);
	rb(head_b, 0);
	if (i == 1)
		ft_putstr("rr\n");
}

void	ss(t_stack **head_b, t_stack **head_a, int i)
{
	sa(head_a, 0);
	sb(head_b, 0);
	if (i == 1)
		ft_putstr("ss\n");
}

void	rrr(t_stack **head_b, t_stack **head_a, int i)
{
	rra(head_a, 0);
	rrb(head_b, 0);
	if (i == 1)
		ft_putstr("rrr\n");
}
