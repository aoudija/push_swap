/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:52:48 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/31 09:55:30 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **head_a, t_stack **head_b)
{
	int		*tab;
	int		*r_max_tab;
	int		size;

	if (ft_lstsize((*head_a)) == 3)
		sort_three(head_a);
	else if (ft_lstsize((*head_a)) == 2)
		sort_two(head_a);
	else if (ft_lstsize((*head_a)) == 5)
		sort_five(head_a, head_b);
	else
	{
		tab = sorted_in_tab((*head_a));
		push_to_stack_b(tab, head_a, head_b, ft_lstsize((*head_a)));
		size = ft_lstsize((*head_b));
		tab = sorted_in_tab((*head_b));
		r_max_tab = sorted_max_tab(tab, size);
		push_to_stack_a(head_b, head_a, r_max_tab, size);
	}
}

char	**check_error(int ac, char **av)
{
	char	**s;

	if (!chk_space_empty(ac, av))
	{
		ft_putstr("\x1B[31mERROR\n\033[0m");
		return (NULL);
	}
	s = input(ac, av);
	if (!check_joined(s))
	{
		ft_free(s);
		ft_putstr("\x1B[31mERROR\n\033[0m");
		return (NULL);
	}
	if (!check_min_max(s))
	{
		ft_free(s);
		return (NULL);
	}
	return (s);
}

int	is_sorted(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i + 1])
		{
			if (ft_atoi(s[i]) > ft_atoi(s[i + 1]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	optime(char **s)
{
	if (!s)
		return (0);
	if (s[0] && !s[1])
		return (0);
	if (!check_double(s))
		return (0);
	if (!is_sorted(s))
		return (0);
	return (1);
}

int	main(int ac, char *av[])
{
	t_stack	*head_a;
	t_stack	*head_b;
	char	**s;
	int		i;

	s = check_error(ac, av);
	if (!optime(s))
		return (0);
	head_a = ft_lstnew(ft_atoi(s[0]));
	i = 1;
	while (s[i])
	{
		ft_lstadd_back(&head_a, ft_lstnew(ft_atoi(s[i])));
		i++;
	}
	ft_free(s);
	sort(&head_a, &head_b);
	ft_lstclear(&head_a);
	return (0);
}
