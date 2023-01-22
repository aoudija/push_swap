/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_min_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 09:26:21 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/22 10:26:07 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	optimize_mnt(int i, t_stack ***head_a)
{
	if (i - 100 > 0)
	{
		while (i > 0)
		{
			rra(&(**head));
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			ra(&(**head));
			i--;
		}
	}
}

void	move_min_top(int pos1, int pos2, t_stack **head_a)
{
	int	i;
	int	j;
	int	r;

	if (pos1 <= 50)
		i = pos1 - 1;
	else if (pos1 > 50)
		i = 100 - pos1 + 1;
	if (pos2 <= 50)
		j = pos1 - 1;
	else if (pos2 > 50)
		j = 100 - pos2 + 1;
	if (i > j)
		optimize_mnt(i, head_a);
	if (i < j)
		optimize_mnt(j, head_a);
}