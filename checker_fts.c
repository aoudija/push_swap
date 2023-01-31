/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:14:00 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/31 09:53:27 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_opt(char *line, t_stack ***head_a, t_stack ***head_b)
{
	if (!ft_strcmp(line, "rrb\n"))
		rrb(*head_b, 0);
	else if (!ft_strcmp(line, "rr\n"))
		rr(*head_b, *head_a, 0);
	else if (!ft_strcmp(line, "rrr\n"))
		rrr(*head_b, *head_a, 0);
	else if (!ft_strcmp(line, "pa\n"))
		pa(*head_b, *head_a, 0);
	else if (!ft_strcmp(line, "pb\n"))
		pb(*head_b, *head_a, 0);
	else if (!ft_strcmp(line, "rra\n"))
		rra(*head_a, 0);
}

void	rules_user(char	*line, t_stack **head_a, t_stack **head_b)
{
	if (!ft_strcmp(line, "pb\n") || !ft_strcmp(line, "rra\n")
		|| !ft_strcmp(line, "pa\n") || !ft_strcmp(line, "rrr\n")
		|| !ft_strcmp(line, "rr\n"))
		min_opt(line, &head_a, &head_b);
	else
	{
		if (!ft_strcmp(line, "ra\n"))
			ra(head_a, 0);
		else if (!ft_strcmp(line, "sa\n"))
			sa(head_a, 0);
		else if (!ft_strcmp(line, "rb\n"))
			rb(head_b, 0);
		else if (!ft_strcmp(line, "sb\n"))
			sb(head_b, 0);
		else if (!ft_strcmp(line, "ss\n"))
			ss(head_b, head_a, 0);
		else
		{
			ft_putstr("ERROR\n");
			exit(1);
		}
	}
}
