/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:46:46 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/29 11:15:53 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_stack_a(t_stack **head_b, t_stack **head_a,
			int *r_max_tab, int size)
{
	int	i;
	int	pos1;

	i = 0;
	while (i < size)
	{
		pos1 = position(r_max_tab[i], *head_b);
		if (pos1 == 1)
		{
		}
		else if (pos1 == ft_lstsize(*head_b) - 1)
		{
			rrb(head_b);
			rrb(head_b);
		}
		else
			move_max_top(pos1, head_b);
		pa(head_b, head_a);
		i++;
	}
	free(r_max_tab);
}
