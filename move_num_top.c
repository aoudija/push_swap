/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_num_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 09:26:21 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/27 10:58:35 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_mnt(int i, int pos, t_stack ***head_a)
{
	if (pos > ft_lstsize(**head_a) / 2)
	{
		while (i > 0)
		{
			rra(*head_a);
			i--;
		}
	}
	else if (i != 0)
	{
		while (i > 0)
		{
			ra(*head_a);
			i--;
		}
	}
}

void	optimize_mxt(int i, int pos, t_stack ***head_b)
{
	if (pos > ft_lstsize(**head_b) / 2)
	{
		while (i > 0)
		{
			rrb(*head_b);
			i--;
		}
	}
	else if (i != 0)
	{
		while (i > 0)
		{
			rb(*head_b);
			i--;
		}
	}
}

void	move_min_top(int pos1, int pos2, t_stack **head_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (pos1 <= ft_lstsize(*head_a) / 2)
		i = pos1 - 1;
	else if (pos1 > ft_lstsize(*head_a) / 2)
		i = ft_lstsize(*head_a) - pos1 + 1;
	if (pos2 <= ft_lstsize(*head_a) / 2)
		j = pos2 - 1;
	else if (pos2 > ft_lstsize(*head_a) / 2)
		j = ft_lstsize(*head_a) - pos2 + 1;
	if (j <= i)
		optimize_mnt(j, pos2, &head_a);
	else if (j > i)
		optimize_mnt(i, pos1, &head_a);
}

void	move_max_top(int pos, t_stack **head_b)
{
	int	i;

	i = 0;
	if (pos <= ft_lstsize(*head_b) / 2)
		i = pos - 1;
	else if (pos > ft_lstsize(*head_b) / 2)
		i = ft_lstsize(*head_b) - pos + 1;
	optimize_mxt(i, pos, &head_b);
}
