# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mosantos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 14:48:39 by mosantos          #+#    #+#              #
#    Updated: 2025/10/15 14:48:43 by mosantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
NAME = philo
SRC_DIR = ./src
SRCS = $(SRC_DIR)/ft_init_data.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/ft_create_threads.c \
		$(SRC_DIR)/ft_actions.c \
		$(SRC_DIR)/ft_actions2.c \
		$(SRC_DIR)/ft_free.c \
		 main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re