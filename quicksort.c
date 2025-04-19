#include "push_swap.h"

int	is_sorted_a(t_stack *stack, int size)
{
	t_list	*curr;
	int		i;

	curr = stack->top;
	i = 0;
	if (!stack || size <= 1)
		return (1);
	while (i < size && curr->next && curr)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
		i++;
	}
	return (1);
}

int	is_sorted_b(t_stack *stack, int size)
{
	t_list	*curr;
	int		i;

	curr = stack->top;
	i = 0;
	if (!stack || size <= 1)
		return (1);
	while (i < size && curr->next && curr)
	{
		if (curr->value < curr->next->value)
			return (0);
		curr = curr->next;
		i++;
	}
	return (1);
}

void	quicksort_b(t_stack *stack_b, t_stack *stack_a, int size)
{
	int	pushed;

	if (!stack_b || !stack_b->top || size <= 1)
		return ;
	if (is_sorted_b(stack_b, size))
		return ;
	if (size <= 3)
	{
		insertion_sort_desc(stack_b, stack_a, stack_b, size);
		return ;
	}
	pushed = partition_b(stack_b, stack_a, stack_b, size);
	quicksort_a(stack_a, stack_b, pushed);
	quicksort_b(stack_b, stack_a, (size - pushed));
	if (is_sorted_a(stack_a, pushed) && stack_b->size <= size)
		return ;
	while (pushed--)
		push(stack_a, stack_b, stack_a, stack_b);
	return ;
}

void	quicksort_a(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	pushed;

	if (!stack_a || !stack_a->top || size <= 1)
		return ;
	if (is_sorted_a(stack_a, size))
		return ;
	if (size <= 3)
	{
		insertion_sort(stack_a, stack_a, stack_b, size);
		return ;
	}
	pushed = partition_a(stack_a, stack_a, stack_b, size);
	quicksort_a(stack_a, stack_b, (size - pushed));
	quicksort_b(stack_b, stack_a, pushed);
	while (pushed--)
		push(stack_b, stack_a, stack_a, stack_b);
	return ;
}
