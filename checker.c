/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 17:04:33 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/31 09:43:31 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	optimez(char **s)
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

void	ot(t_stack **head_a, t_stack **head_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		rules_user(line, head_a, head_b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	while ((*head_a)->next)
	{
		if ((*head_a)->num > (*head_a)->next->num)
		{
			ft_putstr("KO\n");
			exit(1);
		}
		free((*head_a));
		(*head_a) = (*head_a)->next;
	}
	free((*head_a));
	ft_putstr("OK\n");
}

int	main(int ac, char *av[])
{
	t_stack	*head_a;
	t_stack	*head_b;
	char	**s;
	int		i;

	if (ac > 1)
	{
		s = check_error(ac, av);
		if (!optimez(s))
			return (0);
		head_a = ft_lstnew(ft_atoi(s[0]));
		i = 1;
		while (s[i])
		{
			ft_lstadd_back(&head_a, ft_lstnew(ft_atoi(s[i])));
			i++;
		}
		ft_free(s);
		ot(&head_a, &head_b);
	}
	return (0);
}
