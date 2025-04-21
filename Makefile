CC:= cc
CFLAGS:= -Wall -Werror -Wextra
NAME:= push_swap
BONUS_NAME := checker

SRCS:= push_swap.c lst_utils.c libft_utils.c parse_utils.c push_swap_ops.c ft_split.c \
		insertion_sort.c quicksort.c insertion_sort_desc.c pivot_selection.c \
		partitioning.c direct_sort.c

OBJS:= $(SRCS:.c=.o)

BONUS:= checker.c checker_ops.c

OBJSB:= $(BONUS:.c=.o)

SHARED_OBJS := $(filter-out push_swap.o, $(OBJS))

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJSB) $(SHARED_OBJS)
	$(CC) $(CFLAGS) $(OBJSB) $(SHARED_OBJS) -o $(BONUS_NAME)

debug: CFLAGS += -fsanitize=address -ggdb3
debug: all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(OBJSB)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: re fclean clean all debug bonus
