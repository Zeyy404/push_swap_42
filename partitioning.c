#include "push_swap.h"

static void	partition_rrotate(t_stack *stack, t_stack *stack_a,
		t_stack *stack_b, int rotated)
{
	while (rotated--)
		rrotate(stack, stack_a, stack_b);
}

int	partition_a(t_stack *stack, t_stack *stack_a, t_stack *stack_b, int size)
{
	int	pivot;
	int	pushed;
	int	rotated;
	int	i;

	pushed = 0;
	rotated = 0;
	i = 0;
	pivot = find_median(stack->top, size);
	while (i < size)
	{
		if (stack->top->value < pivot)
		{
			push(stack, stack_b, stack_a, stack_b);
			pushed++;
		}
		else
		{
			rotate(stack, stack_a, stack_b);
			rotated++;
		}
		if (pushed >= size / 2)
			break ;
		i++;
	}
    if (rotated < stack->size)
		partition_rrotate(stack, stack_a, stack_b, rotated);
	return (pushed);
}

int	partition_b(t_stack *stack, t_stack *stack_a, t_stack *stack_b, int size)
{
	int	pivot;
	int	pushed;
	int	rotated;
	int	i;

	pushed = 0;
	rotated = 0;
	i = 0;
	pivot = find_median(stack->top, size);
	while (i < size)
	{
		if (stack->top->value >= pivot)
		{
			push(stack, stack_a, stack_a, stack_b);
			pushed++;
		}
		else
		{
			rotate(stack, stack_a, stack_b);
			rotated++;
		}
        if (pushed >= size)
            break ;
		i++;
	}
    if (rotated < stack->size)
		partition_rrotate(stack, stack_a, stack_b, rotated);
	return (pushed);
}
