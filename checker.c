#include "push_swap.h"
#include <stdio.h>

int	is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}

void	execute_instruction(char *instr, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(instr, "sa", 3))
		swap_silent(a);
	else if (!ft_strncmp(instr, "sb", 3))
		swap_silent(b);
	else if (!ft_strncmp(instr, "pa", 3))
		push_silent(b, a);
	else if (!ft_strncmp(instr, "pb", 3))
		push_silent(a, b);
	else if (!ft_strncmp(instr, "rra", 4))
		rrotate_silent(a);
	else if (!ft_strncmp(instr, "rrb", 4))
		rrotate_silent(b);
	else if (!ft_strncmp(instr, "ra", 3))
		rotate_silent(a);
	else if (!ft_strncmp(instr, "rb", 3))
		rotate_silent(b);
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	process_instructions(t_stack *stack_a, t_stack *stack_b)
{
	char	instr[MAX_INSTRUCTION_LEN];
	ssize_t	n;
	char	c;
	int		i;

	n = read(0, &c, 1);
	while (n > 0)
	{
		i = 0;
		while (c != '\n' && n > 0 && i < 4)
		{
			instr[i++] = c;
			n = read(0, &c, 1);
		}
		instr[i] = '\0';
		if (i > 0)
			execute_instruction(instr, stack_a, stack_b);
		n = read(0, &c, 1);
	}
	if (is_sorted_a(stack_a, stack_a->size) && is_empty(stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	ft_free(t_stack *stack_a, t_stack *stack_b)
{
	ft_lstclear(&stack_a->top);
	free(stack_a);
	free(stack_b);
}

int	main(int ac, char **av)
{
	int		i;
	t_list	*lst;
	t_stack	*stack_a;
	t_stack	*stack_b;

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
		process_instructions(stack_a, stack_b);
		ft_free(stack_a, stack_b);
	}
	return (0);
}
