/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:21:10 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/17 10:15:31 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int			ft_atoi(const char *str);
typedef struct stack
{
	int				num;
	struct stack	*next;
}	t_stack_a;
t_stack_a	*ft_lstnew(int num);
void		ft_lstadd_front(t_stack_a **lst, t_stack_a *new);
t_stack_a	*ft_lstlast(t_stack_a *lst);
void		ft_lstadd_back(t_stack_a **lst, t_stack_a *new);

#endif