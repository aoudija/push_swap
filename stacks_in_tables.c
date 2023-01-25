/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_in_tables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:03:33 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/24 16:24:57 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*put_stack_in_table(t_stack *head_a)
{
	int	*tab;
	int	i;

	tab = malloc(4 * ft_lstsize(head_a));
	i = 0;
	while (head_a)
	{
		tab[i] = head_a->num;
		head_a = head_a->next;
		i++;
	}
	return (tab);
}

int	*sorted_in_tab(t_stack	*head_a)
{
	int	*tab;
	int	i;
	int	temp;
	int	j;

	j = 0;
	i = 0;
	tab = put_stack_in_table(head_a);
	while (i < ft_lstsize(head_a))
	{
		j = i + 1;
		while (j < ft_lstsize(head_a))
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

int	*sorted_max_tab(int	*tab, int len)
{
	int	i;
	int	*rev_tab;

	i = 0;
	rev_tab = malloc (4 * len);
	len -= 1;
	while (len >= 0)
	{
		rev_tab[i] = tab[len];
		i++;
		len--;
	}
	return (rev_tab);
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
