/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:50:18 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/19 13:53:06 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pb(t_stack **head_b, t_stack **head_a)
{
	t_stack	*tempo;
	int		temp;

	if (!(*head_a))
		return ;
	temp = (*head_a)->num;
	(*head_a) = (*head_a)->next;
	ft_lstadd_front(head_b, ft_lstnew(temp));
}

void	pa(t_stack **head_b, t_stack **head_a)
{
	t_stack	*tempo;
	int		temp;

	if ((*head_b))
		return ;
	temp = (*head_b)->num;
	(*head_b) = (*head_b)->next;
	ft_lstadd_front(head_a, ft_lstnew(temp));
}
