/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_min_top.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 09:26:21 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/23 23:02:57 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	optimize_mnt(int i, int pos,t_stack ***head_a)
{
	if (pos > ft_lstsize(**head_a) / 2)
	{
		while (i > 0)
		{
			rra(*head_a);
			i--;
		}
	}
	else if (i == 0)
	{
	}
	else
	{
		while (i > 0)
		{
			ra(*head_a);
			i--;
		}
	}
}

void	move_min_top(int pos1, int pos2, t_stack **head_a)
{
	int	i;
	int	j;

	if (pos1 <= 50)
		i = pos1 - 1;
	else if (pos1 > 50)
		i = ft_lstsize(*head_a) - pos1 + 1;
	if (pos2 <= 50)
		j = pos2 - 1;
	else if (pos2 > 50)
		j = ft_lstsize(*head_a) - pos2 + 1;
	if (j <= i)
		optimize_mnt(j , pos2, &head_a);
	else if (j > i)
		optimize_mnt(i, pos1, &head_a);
	
}
