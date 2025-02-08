#include "push_swap.h"

int	is_duplicate(t_list *lst, int value)
{
	while (lst)
	{
		if (lst->value == value)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	input_lst(t_list **lst, char *str)
{
	long	value;
	char	*endptr;

	errno = 0;
	value = ft_strtol(str, &endptr, 10);
	if (is_duplicate(*lst, (int)value) || str == endptr || *endptr != '\0'
		|| errno == ERANGE || value > LONG_MAX || value < LONG_MIN)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_lstadd_back(lst, ft_lstnew((int)value));
	return (1);
}
