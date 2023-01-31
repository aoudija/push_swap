/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:51:42 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/31 10:21:03 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chk_space_empty(int ac, char **av)
{
	int		space;
	int		i;

	i = 0;
	ac -= 1;
	while (ac > 1)
	{
		if (!av[ac])
			return (0);
		i = 0;
		space = 0;
		while (av[ac][i])
		{
			if (av[ac][i] == ' ')
				space++;
			i++;
		}
		if (space == i)
			return (0);
		ac--;
	}
	return (1);
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

int	check_joined(char **input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (input[i][0] == '\0')
				return (0);
			if (((input[i][j] == '+' && input[i][j + 1] == '+')
				|| (input[i][j] == '+' && input[i][j + 1] == '-'))
				|| ((input[i][j] == '-' && input[i][j + 1] == '-')
				|| (input[i][j] == '-' && input[i][j + 1] == '+')))
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

int	check_min_max(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_atoi(s[i]) > 2147483647 || ft_atoi(s[i]) < -2147483648)
		{
			ft_putstr("\x1B[31mERROR\n\033[0m");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_double(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		j = i + 1;
		while (s[j])
		{
			if (ft_atoi(s[j]) == ft_atoi(s[i]))
			{
				ft_free(s);
				ft_putstr("\x1B[31mERROR\n\033[0m");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
