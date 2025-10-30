# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jda-cruz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/27 07:30:34 by jda-cruz          #+#    #+#              #
#    Updated: 2025/10/07 14:04:59 by jda-cruz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

NAME        = so_long

# pastas
SRC_DIR     = src
LIBFT_DIR   = libft
PRINTF_DIR  = ft_printf
MLX_DIR     = minilibx-linux

# libs
LIBFT       = $(LIBFT_DIR)/libft.a
PRINTF      = $(PRINTF_DIR)/libftprintf.a
MLX         = $(MLX_DIR)/libmlx_Linux.a

# fontes do meu projeto
SRC         = so_long.c so_long_utils.c moviment.c validation_map.c \
              load_map.c handle_key.c handle_destroy.c flood_fill.c
SRCS        = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ         = $(SRCS:.c=.o)

# flags
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I. -I$(SRC_DIR) -I$(LIBFT_DIR) \
              -I$(PRINTF_DIR) -I$(MLX_DIR)
LFLAGS      = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf \
              -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm

# **************************************************************************** #
#                                  RULES                                       #
# **************************************************************************** #

all: $(LIBFT) $(PRINTF) $(MLX) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)
	
$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


