# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfournio <sfournio@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 16:04:00 by sfournio          #+#    #+#              #
#    Updated: 2021/04/17 14:57:46 by sfournio         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LFLAGS	=	-I includes

NAME	=	checker

NAME2	=	push_swap

SRCS_NAME	=	checker.c checks.c utils.c opt_swap_push.c opt_rotate.c \
				lib_modif.c lst_utils.c

SRCS_NAME2	=	push_swap.c checks.c utils.c opt_swap_push.c opt_rotate.c \
				lib_modif.c little_sort.c lst_utils.c main_algo.c algo_utils.c

SRC_PATH	=	srcs/checker_srcs

SRC_PATH2	=	srcs/push_swap_srcs

LIBFT       =	srcs/libft/libft.a

SRCS 		= 	$(addprefix $(SRC_PATH)/,$(SRCS_NAME))

SRCS2		=	$(addprefix $(SRC_PATH2)/,$(SRCS_NAME2))

OBJ	=	$(SRCS:.c=.o)

OBJ2	=	$(SRCS2:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)	$(OBJ2) ${SRC_PATH}/checker.h ${SRC_PATH2}/push_swap.h
	@make -C srcs/libft
	@make -C srcs/libft bonus
	@echo "Making Libft..."
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME) $(LIBFT)
	@$(CC) $(OBJ2) $(CFLAGS) -o $(NAME2) $(LIBFT)
	@echo "Making checker..."
	@echo "Making push_swap..."

%.o : %.c	
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ2)
	@make -C srcs/libft clean
	@echo "Clean(libft)"
	@echo "Clean(checker)"
	@echo "Clean(push_swap)"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@make -C srcs/libft fclean
	@echo "Fclean(libft)"
	@echo "Fclean(checker)"
	@echo "Fclean(push_swap)"

re : fclean all

.PHONY: all fclean clean re $(EXEC)