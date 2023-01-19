/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:52:48 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/19 19:08:24 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

void	sort_five(t_stack **head_a, t_stack **head_b)
{
	t_stack	*temp;
	int		min;

	min = INT_MAX;
	temp = (*head_a);
	while (temp)
	{
		if (min > temp->num)
			min = temp->num;
		temp = temp->next;
	}
	temp = (*head_a);
	
	rra(&(*head_a));
	sa(&(*head_a));
	pb(&(*head_b), &(*head_a));
	pb(&(*head_b), &(*head_a));	
	sort_three(head_a);
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
	// sort_five(&head_a, &head_b);
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
	printf("%d\n", INT_MAX);
}
