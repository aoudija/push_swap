/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:52:48 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/24 16:06:41 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_three(t_stack **head_a)
{
	if ((*head_a)->num > (*head_a)->next->num
		&& (*head_a)->num < ft_lstlast((*head_a))->num)
		sa(&(*head_a));
	if ((*head_a)->num > (*head_a)->next->num
		&& (*head_a)->num > ft_lstlast((*head_a))->num
		&& ft_lstlast((*head_a))->num < (*head_a)->next->num)
	{
		sa(&(*head_a));
		rra(&(*head_a));
	}
	if (ft_lstlast((*head_a))->num > (*head_a)->next->num
		&& (*head_a)->num > ft_lstlast((*head_a))->num)
		ra(&(*head_a));
	if (ft_lstlast((*head_a))->num < (*head_a)->next->num
		&& ft_lstlast((*head_a))->num > (*head_a)->num)
	{
		sa(&(*head_a));
		ra(&(*head_a));
	}
	if ((*head_a)->num < (*head_a)->next->num
		&& (*head_a)->num > ft_lstlast((*head_a))->num)
		rra(&(*head_a));
}

void	optimize_case_5(int pos, t_stack **head_a)
{
	if (pos - 5 == 0)
		rra(&(*head_a));
	else if (pos - 5 == -1)
	{
		rra(&(*head_a));
		rra(&(*head_a));
	}
	else if (pos - 5 == -2)
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

int	main(int argc, char *argv[])
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*tempo;
	int		*tab;
	int		*r_tab;
	int		j;
	int		i;
	int		pos1;
	int		pos2;
	int		size;

	head_a = ft_lstnew(ft_atoi(argv[argc - 1]));
	argc -= 2;
	while (argc > 0)
	{
		ft_lstadd_front(&head_a, ft_lstnew(ft_atoi(argv[argc])));
		argc--;
	}
	tab = sorted_in_tab(head_a);
	j = 19;
	tempo = head_a;
	size = ft_lstsize(head_a);
	while (j < size)
	{
		i = size / 5;
		while (i > 0)
		{
			r_tab = reversed_stack(head_a);
			pos1 = position(number_in_range_top(tab, head_a, j), head_a);
			pos2 = position(number_in_range_bottom(tab, head_a, r_tab,j), head_a);
			if (pos1 == 1 || pos2 == 1)
			{
			}
			else if (pos1 == ft_lstsize(head_a) - 1 || pos2 == ft_lstsize(head_a) - 1)
			{
				rra(&head_a);
				rra(&head_a);
			}
			else
				move_min_top(pos1, pos2, &head_a);
			pb(&head_b, &head_a);
			i--;
		}
		j += size / 5;
	}
	size = ft_lstsize(head_b);
	tab = sorted_in_tab(head_b);
	r_tab = sorted_MAX_tab(tab, size);
	i = 0;
	while (i < size)
	{
		pos1 = position(r_tab[i], head_b);
		if (pos1 == 1)
		{
		}
		else if (pos1 == ft_lstsize(head_a) - 1)
		{
			rra(&head_b);
			rra(&head_b);
		}
		else
			move_max_top(pos1, &head_b);
		pa(&head_b, &head_a);
		i++;
	}
	
	// j = 0;
	// r_tab = sorted_MAX_tab(tab, ft_lstsize(head_a));
	// printf("%d\n", ft_lstsize(head_a));
	// i = 0;
	// while (i < ft_lstsize(head_a))
	// {
	// 	printf("%d\n", r_tab[i]);
	// 	i++;
	// }
	
	// while (head_b)
	// {
	// 	printf(">>%d \n", head_b->num);
	// 	head_b = head_b->next;
	// }
	// printf("\n-stack A\n");
	// while (head_a)
	// {
	// 	printf("%d\n", head_a->num);
	// 	head_a = head_a->next;
	// }
}
