/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 07:21:10 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/30 21:21:39 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <fcntl.h>

long long	ft_atoi(const char *str);
typedef struct stack
{
	int				num;
	struct stack	*next;
}	t_stack;
t_stack		*ft_lstnew(int num);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
int			ft_lstsize(t_stack *lst);
void		rr(t_stack **head_b, t_stack **head_a, int i);
void		rrr(t_stack **head_b, t_stack **head_a, int i);
void		sa(t_stack **head_a, int i);
void		sb(t_stack **head_b, int i);
void		ss(t_stack **head_b, t_stack **head_a, int i);
void		ra(t_stack **head_a, int i);
void		rb(t_stack **head_b, int i);
void		rra(t_stack **head_a, int i);
void		pb(t_stack **head_b, t_stack **head_a, int i);
void		rrb(t_stack **head_b, int i);
void		pa(t_stack **head_b, t_stack **head_a, int i);
void		move_min_top(int pos1, int pos2, t_stack **head_a);
int			number_in_range_top(int *table, t_stack *stack_a, int end);
int			number_in_range_bottom(int *table, t_stack	*head_a,
				int *rev_tab, int end);
int			*sorted_in_tab(t_stack	*head_a);
int			*reversed_stack(t_stack *head_a);
int			position(int num, t_stack *temp);
int			*sorted_max_tab(int	*tab, int len);
void		move_max_top(int pos, t_stack **head_b);
void		push_to_stack_b(int *tab, t_stack **head_a,
				t_stack **head_b, int size);
void		push_to_stack_a(t_stack **head_b, t_stack **head_a,
				int *r_max_tab, int size);
void		sort_five(t_stack **head_a, t_stack **head_b);
void		sort_three(t_stack **head_a);
void		ft_putstr(char *s);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
void		ft_lstclear(t_stack **lst);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		*ft_free(char **table);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t n);
char		*ft_strjoin(char *s1, char const *s2);
int			chk_space_empty(int ac, char **av);
char		**input(int ac, char **av);
int			check_joined(char **input);
int			check_min_max(char **s);
int			check_double(char **s);
void		sort_two(t_stack **head_a);
char		*get_next_line(int fd);
void		rules_user(char	*line, t_stack **head_a, t_stack **head_b);

#endif