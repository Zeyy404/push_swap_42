CC:= cc
CFLAGS:= -Wall -Werror -Wextra
NAME:= push_swap

SRCS:= push_swap.c lst_utils.c libft_utils.c parse_utils.c push_swap_ops.c ft_split.c \
		insertion_sort.c quicksort.c

OBJS:= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

debug: CFLAGS += -fsanitize=address -ggdb3
debug: all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all
