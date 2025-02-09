CC:= cc
CFLAGS:= -Wall -Werror -Wextra
NAME:= push_swap

SRCS:= push_swap.c lst_utils.c libft_utils.c parse_utils.c

OBJS:= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

bonus: $(OBJSB)
	ar rcs $(NAME) $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean clean all
