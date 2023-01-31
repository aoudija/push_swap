# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 15:21:39 by aoudija           #+#    #+#              #
#    Updated: 2023/01/31 10:31:20 by aoudija          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

B_NAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

DEPS = push_swap.h

FILES = ft_tools_1.c ft_tools_2.c move_num_top.c push_swap.c rules_1.c\
		rules_2.c search_in_range.c stacks_in_tables.c push_to_stack_b.c push_to_stack_a.c\
		sort_five_three.c rules_3.c ft_putsr.c libft_tools.c libft_tools2.c ft_split.c ft_strtrim.c\
		check_errors.c ft_lstclear.c

FILES_B = checker.c checker_fts.c rules_1.c rules_2.c rules_3.c ft_putsr.c libft_tools.c libft_tools2.c\
		  ft_split.c ft_strtrim.c check_errors.c get_next_line.c ft_tools_1.c ft_tools_2.c \
			ft_lstclear.c
OBG = $(FILES:.c=.o)

OBGB = $(FILES_B:.c=.o)

all : $(NAME)

$(NAME) : $(OBG)
	$(CC) $(CFLAGS) $(OBG) -o $(NAME) 

bonus : $(OBGB)
	$(CC) $(CFLAGS) $(OBGB) -o $(B_NAME)

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBG) $(OBGB)

fclean: clean
	rm -f $(NAME) $(B_NAME)

re:fclean all

.PHONY:all clean fclean re bonus