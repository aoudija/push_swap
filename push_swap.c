/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:52:48 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/20 11:54:53 by aoudija          ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	t_stack	*head_a;
	t_stack	*head_b;
	t_stack	*tempo;

	head_a = ft_lstnew(ft_atoi(argv[argc - 1]));
	argc -= 2;
	while (argc > 0)
	{
		ft_lstadd_front(&head_a, ft_lstnew(ft_atoi(argv[argc])));
		argc--;
	}
	sort_five(&head_a, &head_b);
	tempo = head_b;
	while (tempo)
	{
		printf("%d\n",tempo->num);
		tempo = tempo->next;
	}
	printf("-b-\n");
	// sort_three(&head_a);
	tempo = head_a;
	while (tempo)
	{
		printf("%d\n",tempo->num);
		tempo = tempo->next;
	}
	printf("-a-\n");
}
