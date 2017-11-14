CFLAGS ?= -Wall -Wextra -Werror
NAME ?= fillit

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
