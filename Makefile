# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drakan <drakan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 12:22:57 by drakan            #+#    #+#              #
#    Updated: 2022/01/19 21:30:31 by drakan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_CHECKER = checker

CFLAGS = -Wall -Wextra -Werror

INC =-I./includes

SRCS		=	./utils/list_sorted_a.c \
				./utils/list_sorted_b.c \
				./utils/get_next_line.c \
				./utils/utils.c \
				./utils/utils1.c \
				./utils/utils2.c \
				./utils/utils3.c \
				./utils/ft_split.c \
				./utils/ft_errors.c

PUSH		= 	./sorting/num_3sort.c \
				./sorting/num_5sort.c \
				./sorting/push_swap.c \
				./sorting/big_sort.c \
				./sorting/big_sort2.c 

CHECKER		=	./bonus_/checker.c

SRCS_PUSH		=	$(PUSH)
SRCs_push	=	$(CHECKER) 

OBJ=$(SRCS:.c=.o)
OBJ_PUSH=$(SRCS_PUSH:.c=.o)
OBJ_CHECKER=$(SRCs_push:.c=.o)

all:
	$(MAKE) $(NAME)

$(NAME): $(OBJ) $(OBJ_PUSH)
	gcc $(CFLAGS) $(INC) $(OBJ) $(OBJ_PUSH) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) $(INC) -o $@ -c $<

bonus:
	$(MAKE) $(NAME_CHECKER)

$(NAME_CHECKER): $(OBJ) $(OBJ_CHECKER) $(OBJ_PUSH)
	gcc $(CFLAGS) $(INC) $(OBJ) $(OBJ_CHECKER) -o $(NAME_CHECKER)

clean:
	rm -f $(OBJ) $(OBJ_PUSH) $(OBJ_CHECKER)

fclean: clean
	rm -f $(NAME) $(NAME_CHECKER)

re:
	make fclean
	make all