# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fpetras <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 08:40:30 by fpetras           #+#    #+#              #
#    Updated: 2017/11/20 19:56:51 by fpetras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME ?= fillit

CFLAGS ?= -Wall -Wextra -Werror

SRC := \
	checker.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_putstr.c \
	ft_strlen.c \
	main.c \
	reader.c \
	solver.c

OBJ := $(SRC:.c=.o)

CFLAGS += -MMD -MP

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

-include $(OBJ:.o=.d)

clean:
	$(RM) $(OBJ) $(OBJ:.o=.d)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
