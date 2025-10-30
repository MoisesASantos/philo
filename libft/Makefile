# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jda-cruz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 21:35:43 by jda-cruz          #+#    #+#              #
#    Updated: 2025/07/05 10:01:14 by jda-cruz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_substr.c ft_strlen.c ft_strchr.c ft_memcpy.c ft_memmove.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memset.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_split.c ft_striteri.c ft_putstr_fd.c ft_putendl_fd.c ft_putchar_fd.c ft_strtrim.c ft_strmapi.c ft_strjoin.c ft_itoa.c ft_putnbr_fd.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar

# ---------------------------------------------------------------------------
# Objetivo principal
# ---------------------------------------------------------------------------
all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $(NAME) $(OBJ)
	@echo "Biblioteca criada com sucesso!"

# ---------------------------------------------------------------------------
# Limpeza
# ---------------------------------------------------------------------------
clean:
	rm -f $(OBJ)
	@echo "Arquivos objectos eliminados"

fclean: clean
	rm -f libft.a
	@echo "Repositório vazio!"

re: fclean all
	@echo "Recompilando!"

.PHONY: all clean fclean re

