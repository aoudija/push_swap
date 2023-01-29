/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:52:48 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/29 11:18:10 by aoudija          ###   ########.fr       */
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

char	**input(int ac, char **av)
{
	int		i;
	char	*input_tab;
	char	**s;

	i = 1;
	input_tab = ft_strdup("");
	while (i < ac)
	{
		input_tab = ft_strjoin(input_tab, av[i]);
		input_tab = ft_strjoin(input_tab, " ");
		i++;
	}
	s = ft_split(input_tab, ' ');
	free(input_tab);
	return (s);
}

int	check_error(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if ((input[i][j] == '+' && input[i][j + 1] == '+')
				|| (input[i][j] == '+' && input[i][j + 1] == '-'))
				return (0);
			if ((input[i][j] == '-' && input[i][j + 1] == '-')
				|| (input[i][j] == '-' && input[i][j + 1] == '+'))
				return (0);
			if (input[i][j] == '+' || input[i][j] == '-')
				j++;
			if (!ft_isdigit(input[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_max(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_atoi(s[i]) > 2147483647)
		{
			ft_free(s);
			ft_putstr("\x1B[31mERROR\n\033[0m");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*head_a;
	t_stack	*head_b;
	// char	**s;
	// int		i;



	head_a = ft_lstnew(ft_atoi(argv[argc - 1]));
	argc -= 2;
	while (argc > 0)
	{
		ft_lstadd_front(&head_a, ft_lstnew(ft_atoi(argv[argc])));
		argc--;
	}
	// i = 0;
	// s = input(argc, argv);
	// if (!check_error(s))
	// {
	// 	ft_free(s);
	// 	ft_putstr("\x1B[31mERROR\n\033[0m");
	// 	return (0);
	// }
	// if (!check_max(s))
	// {
	// 	ft_free(s);
	// 	return (0);
	// }
	// head_a = ft_lstnew(ft_atoi(s[0]));
	// i = 1;
	// while (s[i])
	// {
	// 	ft_lstadd_back(&head_a, ft_lstnew(ft_atoi(s[i])));
	// 	i++;
	// }
	// ft_free(s);
	sort(&head_a, &head_b);
	while (1)
		;
	return (0);
}
