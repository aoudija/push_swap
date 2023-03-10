/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:35:05 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/29 19:27:32 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	position(int num, t_stack *temp)
{
	int	pos;

	pos = 1;
	while (temp)
	{
		if (temp->num == num)
			break ;
		pos++;
		temp = temp->next;
	}
	return (pos);
}

int	ft_isdigit(int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	return (0);
}

void	sort_two(t_stack **head_a)
{
	if ((*head_a)->num > (*head_a)->next->num)
		sa(head_a, 1);
}
