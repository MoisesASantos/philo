# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosantos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 13:19:06 by mosantos          #+#    #+#              #
#    Updated: 2025/10/29 13:19:10 by mosantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
SRC_DIR		= src
LIBFT_DIR	= lib/libft
READLINE	= -lreadline

SRC			= $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/read/*.c $(SRC_DIR)/error_input/*.c)
OBJ			= $(SRC:.c=.o)
HEADER		= $(wildcard $(SRC_DIR)/include/*.h)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	@make  -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT_DIR)/libft.a $(READLINE)
	@echo "✅ [TENHO WILDCARD, DON'T FORGET]"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re refaz
