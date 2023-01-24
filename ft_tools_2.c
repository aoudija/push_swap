/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:35:05 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/24 12:20:12 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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
