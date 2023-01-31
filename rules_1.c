/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:19:27 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/30 22:38:53 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **head_a, int i)
{
	int			temp;

	if (!(*head_a))
		return ;
	temp = (*head_a)->num;
	(*head_a)->num = (*head_a)->next->num;
	(*head_a)->next->num = temp;
	if (i == 1)
		ft_putstr("sa\n");
}

void	sb(t_stack **head_b, int i)
{
	int			temp;

	if (!(*head_b))
		return ;
	temp = (*head_b)->num;
	(*head_b)->num = (*head_b)->next->num;
	(*head_b)->next->num = temp;
	if (i == 1)
		ft_putstr("sb\n");
}

void	ra(t_stack **head_a, int i)
{
	t_stack	*tempo;

	if (!(*head_a))
		return ;
	tempo = (*head_a);
	free(*head_a);
	(*head_a) = (*head_a)->next;
	ft_lstadd_back(head_a, ft_lstnew(tempo->num));
	if (i == 1)
		ft_putstr("ra\n");
}

void	rb(t_stack **head_b, int i)
{
	t_stack	*tempo;

	if (!(*head_b))
		return ;
	tempo = (*head_b);
	free(*head_b);
	(*head_b) = (*head_b)->next;
	ft_lstadd_back(head_b, ft_lstnew(tempo->num));
	if (i == 1)
		ft_putstr("rb\n");
}

void	rra(t_stack **head_a, int i)
{
	t_stack	*tempo;
	int		temp;

	if (!(*head_a))
		return ;
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
	free(tempo->next);
	tempo->next = NULL;
	if (i == 1)
		ft_putstr("rra\n");
}
