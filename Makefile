# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 15:21:39 by aoudija           #+#    #+#              #
#    Updated: 2023/01/28 14:18:50 by aoudija          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPS = push_swap.h
FILES = ft_tools_1.c ft_tools_2.c move_num_top.c push_swap.c rules_1.c\
		rules_2.c search_in_range.c stacks_in_tables.c push_to_stack_b.c push_to_stack_a.c\
		sort_five_three.c rules_3.c ft_putsr.c libft_tools.c libft_tools2.c ft_split.c ft_strtrim.c\

OBG = $(FILES:.c=.o)

%.o:%.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

all:$(NAME)
	cc push_swap.c push_swap.a -o push_swap

$(NAME):$(OBG)
	ar rc $(NAME) $(OBG)

clean:
	rm -f $(OBG)

fclean: clean
	rm -f $(NAME) client server
	rm -f push_swap

re: fclean all

.PHONY: all clean fclean re