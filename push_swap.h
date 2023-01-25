/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:21:10 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/24 20:18:36 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

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
void	pb(t_stack **head_b, t_stack **head_a);
void	rrb(t_stack **head_b);
void	pa(t_stack **head_b, t_stack **head_a);
void	move_min_top(int pos1, int pos2, t_stack **head_a);
int		number_in_range_top(int *table, t_stack *stack_a, int end);
int		number_in_range_bottom(int *table, t_stack	*head_a,
			int *rev_tab, int end);
int		*sorted_in_tab(t_stack	*head_a);
int		*reversed_stack(t_stack *head_a);
int		position(int num, t_stack *temp);
int		*sorted_max_tab(int	*tab, int len);
void	move_max_top(int pos, t_stack **head_b);
void	push_to_stack_b(int *tab, t_stack **head_a, t_stack **head_b, int size);
void	push_to_stack_a(t_stack **head_b, t_stack **head_a, int *r_max_tab, int size);
void	sort_five(t_stack **head_a, t_stack **head_b);
void	sort_three(t_stack **head_a);

#endif