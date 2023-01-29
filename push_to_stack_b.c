/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:46:02 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/29 11:13:29 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opt(t_stack ***head_a, t_stack ***head_b, int *tab, int j)
{
	int	*r_tab;
	int	pos1;
	int	pos2;
	int	n;

	r_tab = reversed_stack(**head_a);
	n = number_in_range_top(tab, **head_a, j);
	pos1 = position(n, **head_a);
	n = number_in_range_bottom(tab, **head_a, r_tab, j);
	pos2 = position(n, **head_a);
	if (pos1 == 1 || pos2 == 1)
	{
	}
	else if (pos1 == ft_lstsize(**head_a) - 1
		|| pos2 == ft_lstsize(**head_a) - 1)
	{
		rra(*head_a);
		rra(*head_a);
	}
	else
		move_min_top(pos1, pos2, *head_a);
	pb(*head_b, *head_a);
	free(r_tab);
}

int	dvs(t_stack *head_a, int size)
{
	int	dv;
	if (ft_lstsize(head_a) == 100)
		dv = size / 5;
	else if (ft_lstsize(head_a) == 500)
		dv = size / 25;
	else
		dv = size / 2;
	return (dv);
}

void	push_to_stack_b(int *tab, t_stack **head_a, t_stack **head_b, int size)
{
	int	j;
	int	i;
	int	dv;

	i = 0;
	dv = dvs(*head_a, size);
	if (dv == 1)
		j = dv;
	else
		j = dv - 1;
	while (j < size)
	{
		i = dv;
		while (i > 0)
		{
			opt(&head_a, &head_b, tab, j);
			i--;
		}
		j += dv;
	}
	free(tab);
}
