#include "push_swap.h"

int	find_median(t_list *top, int size)
{
	t_list	*mid;
	t_list	*last;
	int		i;

	i = 0;
	mid = top;
	while (i < (size / 2))
	{
		mid = mid->next;
		i++;
	}
	last = mid;
	while (last->next)
		last = last->next;
	if ((top->value > mid->value && top->value < last->value)
		|| (top->value < mid->value && top->value > last->value))
		return (top->value);
	else if ((mid->value > top->value && mid->value < last->value)
		|| (mid->value < top->value && mid->value > last->value))
		return (mid->value);
	else
		return (last->value);
}

static void	partition_rrotate(t_stack *stack_a, t_stack *stack_b,
		int rotated)
{
	while (rotated-- > 0)
		rrotate(stack_a, stack_a, stack_b);
}

int	partitions(t_stack *stack_a, t_stack *stack_b)
{
	int		pivot;
	int		pushed;
	int		rotated;
	int		size;

	pushed = 0;
	rotated = 0;
	size = stack_a->size;
	if (stack_a->size <= 5)
		return (0);
	pivot = find_median(stack_a->top, stack_a->size);
	while ((pushed + rotated) < size)
	{
		if (stack_a->top->value < pivot)
		{
			push(stack_a, stack_b, stack_a, stack_b);
			pushed++;
		}
		else
		{
			rotate(stack_a, stack_a, stack_b);
			rotated++;
		}
	}
	return (partition_rrotate(stack_a, stack_b, rotated), pushed);
}

void	quicksort(t_stack *stack_a, t_stack *stack_b)
{
	int	pushed;

	if (stack_a->size <= 5)
	{
		insertion_sort(stack_a, stack_a, stack_b);
		return ;
	}
	else if (stack_b ->size <= 5)
	{
		insertion_sort(stack_a, stack_a, stack_b);
		return ;
	}
	pushed = partitions(stack_a, stack_b);
	quicksort(stack_b, stack_a);
	quicksort(stack_a, stack_b);
	while (pushed--)
		push(stack_b, stack_a, stack_a, stack_b);
}
