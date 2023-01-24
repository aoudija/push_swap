/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:01:23 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/24 16:08:52 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_in_range_top(int *table, t_stack *stack_a, int end)
{
	int	i;
	int	start;

	start = end - 20 + 1;
	while (stack_a)
	{
		i = start;
		while (i <= end)
		{
			if (table[i] == stack_a->num)
				return (stack_a->num);
			i++;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

int	number_in_range_bottom(int *table, t_stack	*head_a, int *rev_tab, int end)
{
	int		i;
	int		j;
	int		start;

	start = end - 20 + 1;
	j = 0;
	while (j < ft_lstsize(head_a))
	{
		i = start;
		while (i <= end)
		{
			if (table[i] == rev_tab[j])
				return (rev_tab[j]);
			i++;
		}
		j++;
	}
	return (0);
}

