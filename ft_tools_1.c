/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 08:36:57 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/17 18:24:16 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_atoi(const char *str)
{
	int	s;
	int	i;
	int	nb;

	s = 1;
	i = 0;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' )
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * s);
}

t_stack_a	*ft_lstnew(int num)
{
	t_stack_a	*x;

	x = malloc(sizeof(t_stack_a));
	if (!x)
		return (NULL);
	x->num = num;
	x->next = NULL;
	return (x);
}

void	ft_lstadd_front(t_stack_a **lst, t_stack_a *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_stack_a	*ft_lstlast(t_stack_a *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_stack_a **lst, t_stack_a *new)
{
	t_stack_a	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast (*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
