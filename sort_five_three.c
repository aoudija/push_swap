/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:07:10 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/29 19:23:39 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **head_a)
{
	if ((*head_a)->num > (*head_a)->next->num
		&& (*head_a)->num < ft_lstlast((*head_a))->num)
		sa(head_a, 1);
	if ((*head_a)->num > (*head_a)->next->num
		&& (*head_a)->num > ft_lstlast((*head_a))->num
		&& ft_lstlast((*head_a))->num < (*head_a)->next->num)
	{
		sa(head_a, 1);
		rra(head_a, 1);
	}
	if (ft_lstlast((*head_a))->num > (*head_a)->next->num
		&& (*head_a)->num > ft_lstlast((*head_a))->num)
		ra(head_a, 1);
	if (ft_lstlast((*head_a))->num < (*head_a)->next->num
		&& ft_lstlast((*head_a))->num > (*head_a)->num)
	{
		sa(head_a, 1);
		ra(head_a, 1);
	}
	if ((*head_a)->num < (*head_a)->next->num
		&& (*head_a)->num > ft_lstlast((*head_a))->num)
		rra(head_a, 1);
}

int	min_node(t_stack *temp)
{
	int		min;

	min = INT_MAX;
	while (temp)
	{
		if (min > temp->num)
			min = temp->num;
		temp = temp->next;
	}
	return (min);
}

void	optimize_case_5(int pos, t_stack ***head_a)
{
	if (pos - 5 == 0)
		rra(*head_a, 1);
	else if (pos - 5 == -1)
	{
		rra(*head_a, 1);
		rra(*head_a, 1);
	}
	else if (pos - 5 == -2)
	{
		ra(*head_a, 1);
		ra(*head_a, 1);
	}
	else if (pos - 5 == -3)
		ra(*head_a, 1);
	else if (pos - 5 == -4)
	{
	}
}

void	optimize_case_4(int pos, t_stack ***head_a)
{
	if (pos - 4 == -3)
	{
	}
	else if (pos - 4 == -2)
		ra(*head_a, 1);
	else if (pos - 4 == -1)
	{
		ra(*head_a, 1);
		ra(*head_a, 1);
	}
	else if (pos - 4 == 0)
		rra(*head_a, 1);
}

void	sort_five(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;
	int		pos;
	int		min;

	temp = *head_a;
	min = min_node(temp);
	pos = position(min, temp);
	optimize_case_5(pos, &head_a);
	pb(head_b, head_a, 1);
	temp = (*head_a);
	min = min_node(temp);
	pos = position(min, temp);
	optimize_case_4(pos, &head_a);
	pb(head_b, head_a, 1);
	sort_three(head_a);
	pa(head_b, head_a, 1);
	pa(head_b, head_a, 1);
}
