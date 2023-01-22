/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:52:48 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/22 10:43:17 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

void	sort_three(t_stack **head_a)
{
	if ((*head_a)->num > (*head_a)->next->num && (*head_a)->num < ft_lstlast((*head_a))->num)
		sa(&(*head_a));
	if ((*head_a)->num > (*head_a)->next->num && (*head_a)->num > ft_lstlast((*head_a))->num 
		&& ft_lstlast((*head_a))->num < (*head_a)->next->num)
	{
		sa(&(*head_a));
		rra(&(*head_a));
	}
	if (ft_lstlast((*head_a))->num > (*head_a)->next->num && (*head_a)->num > ft_lstlast((*head_a))->num)
		ra(&(*head_a));
	if (ft_lstlast((*head_a))->num < (*head_a)->next->num && ft_lstlast((*head_a))->num > (*head_a)->num)
	{
		sa(&(*head_a));
		ra(&(*head_a));
	}
	if ((*head_a)->num < (*head_a)->next->num && (*head_a)->num > ft_lstlast((*head_a))->num)
		rra(&(*head_a));
}

void	optimize_case_5(int pos, t_stack **head_a)
{
	if (pos - 5 == 0)
		rra(&(*head_a));
	else if(pos - 5 == -1)
	{
		rra(&(*head_a));
		rra(&(*head_a));
	}
	else if(pos - 5 == -2)
	{
		ra(&(*head_a));
		ra(&(*head_a));
	}
	else if (pos - 5 == -3)
		ra(&(*head_a));
	else if (pos - 5 == -4)
	{
	}
}

void	optimize_case_4(int pos, t_stack **head_a)
{
	if (pos - 4 == -3)
	{
	}
	else if (pos - 4 == -2)
		ra(&(*head_a));
	else if (pos - 4 == -1)
	{
		ra(&(*head_a));
		ra(&(*head_a));
	}
	else if (pos - 4 == 0)
		rra(&(*head_a));
}

void	sort_five(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;
	int		pos;
	int		min;

	temp = (*head_a);
	min = min_node(temp);
	pos = position(min, temp);
	optimize_case_5(pos, head_a);
	pb(&(*head_b), &(*head_a));
	temp = (*head_a);
	min = min_node(temp);
	pos = position(min, temp);
	optimize_case_4(pos, head_a);
	pb(&(*head_b), &(*head_a));
	sort_three(head_a);
	pa(&(*head_b), &(*head_a));
	pa(&(*head_b), &(*head_a));
}

int	*sorted_in_tab(t_stack	*head_a)
{
	int	*tab;
	int	i;
	int temp;
	int	len;
	int	j;

	tab = malloc(4 * ft_lstsize(head_a));
	i = 0;
	while (head_a)
	{
		tab[i] = head_a->num;
		head_a = head_a->next;
		i++;
	}
	len = i;
	j = 0;
	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[j];
				tab[j] = tab[i];
				tab[i] = temp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	number_in_range_top(int *table, t_stack *stack_a, int start, int end)
{
	int	i;

	i = start;
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

int	*reversed_stack(t_stack *head_a)
{
	int	i;
	int	*tab;

	tab = malloc(4 * ft_lstsize(head_a));
	i = ft_lstsize(head_a) - 1;
	while (head_a && i >= 0)
	{
		tab[i] = head_a->num;
		head_a = head_a->next;
		i--;
	}
	return (tab);
}

int	number_in_range_bottom(int *table, t_stack	*head_a, int *rev_tab, int end)
{
	int		i;
	t_stack	*temp;
	int		j;
	int		start;

	start = end - 20 + 1;
	j = 0;
	i = start;
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

int	main(int argc, char *argv[])
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*tempo;
	int		*tab;
	int		*r_tab;
	int		len;
	int		i;
	int		pos1;
	int		pos2;
	int		num1;
	int		num2;

	head_a = ft_lstnew(ft_atoi(argv[argc - 1]));
	argc -= 2;
	while (argc > 0)
	{
		ft_lstadd_front(&head_a, ft_lstnew(ft_atoi(argv[argc])));
		argc--;
	}
	tab = sorted_in_tab(head_a);
	r_tab = reversed_stack(head_a);
	i = 0;
	num1 = number_in_range_top(tab, tempo, 0, 19);
	num2 = number_in_range_bottom(tab, tempo, r_tab, 0, 19);
	
	number_in_range_top(tab, tempo, 20, 39);
	number_in_range_bottom(tab, tempo, r_tab, 20, 39);
	number_in_range_top(tab, tempo, 40, 59);
	number_in_range_bottom(tab, tempo, r_tab, 40, 59);
	number_in_range_top(tab, tempo, 60, 79);
	number_in_range_bottom(tab, tempo, r_tab, 60, 79);
	number_in_range_top(tab, tempo, 80, 99);
	number_in_range_bottom(tab, tempo, r_tab,80, 99);
	
}
