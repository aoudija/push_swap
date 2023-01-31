/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:50:18 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/29 19:26:54 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **head_b, t_stack **head_a, int i)
{
	int		temp;

	if (!(*head_a))
		return ;
	temp = (*head_a)->num;
	free(*head_a);
	(*head_a) = (*head_a)->next;
	ft_lstadd_front(head_b, ft_lstnew(temp));
	if (i == 1)
		ft_putstr("pb\n");
}

void	pa(t_stack **head_b, t_stack **head_a, int i)
{
	int	temp;

	if (!(*head_b))
		return ;
	temp = (*head_b)->num;
	free(*head_b);
	(*head_b) = (*head_b)->next;
	ft_lstadd_front(head_a, ft_lstnew(temp));
	if (i == 1)
		ft_putstr("pa\n");
}
