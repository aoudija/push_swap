/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:21:10 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/19 13:55:50 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
typedef struct stack
{
	int				num;
	struct stack	*next;
}	t_stack;
t_stack	*ft_lstnew(int num);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
int		ft_lstsize(t_stack *lst);
void	sa(t_stack **head_a);
void	sb(t_stack **head_b);
void	ra(t_stack **head_a);
void	rb(t_stack **head_b);
void	rra(t_stack **head_a);
void	rrb(t_stack **head_b);
void	rr(t_stack **head_b, t_stack **head_a);
void	ss(t_stack **head_b, t_stack **head_a);
void	rrr(t_stack **head_b, t_stack **head_a);
void	pb(t_stack **head_b, t_stack **head_a);
void	pa(t_stack **head_b, t_stack **head_a);

#endif