#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
	int		i;
	t_list	*lst;
	t_stack	*stack_a;
	t_stack *stack_b;

	i = 1;
	lst = NULL;
	if (ac >= 2)
	{
		while (i < ac)
		{
			if (!input_lst(&lst, av[i]))
			{
				ft_lstclear(&lst);
				return (1);
			}
			i++;
		}
		stack_a = init_stack(lst);
		stack_b = init_stack(NULL);
		rrotate(stack_a, stack_a, stack_b);
		for (t_list *tmp = stack_a->top; tmp; tmp = tmp->next)
		{
			printf("%d, ", tmp->value);
		}
	}
	return (0);
}
