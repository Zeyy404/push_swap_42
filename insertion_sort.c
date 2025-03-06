#include "push_swap.h"

void	sort_three(t_stack *stack, t_stack *stack_a, t_stack *stack_b)
{
	int a; 
    int b;
    int c;

	a = stack_a->top->value;
	b = stack_a->top->next->value;
	c = stack_a->top->next->next->value;
	if (a > b && b < c && a < c)
		swap(stack, stack_a, stack_b);
	else if (a > b && b > c)
	{
		swap(stack, stack_a, stack_b);
		rrotate(stack, stack_a, stack_b);
	}
	else if (a > b && b < c && a > c)
		rotate(stack, stack_a, stack_b);
	else if (a < b && b > c && a < c)
    {
		swap(stack, stack_a, stack_b);
		rotate(stack, stack_a, stack_b);
	}
	else if (a < b && b > c && a > c)
		rrotate(stack, stack_a, stack_b);
}

void	find_smallest(t_stack *stack, int *smallest, int *pos)
{
	t_list	*curr;
	int		index;

	*smallest = stack->top->value;
	*pos = 0;
	index = 0;
	curr = stack->top;
	while (curr)
	{
		if (curr->value < *smallest)
		{
			*smallest = curr->value;
			*pos = index;
		}
		curr = curr->next;
		index++;
	}
}

void	push_smallest(t_stack *stack, t_stack *stack_a, t_stack *stack_b)
{
	int	smallest;
	int	pos;

	find_smallest(stack_a, &smallest, &pos);
	if (pos <= stack_a->size / 2)
		while (stack_a->top->value != smallest)
			rotate(stack, stack_a, stack_b);
	else
		while (stack_a->top->value != smallest)
			rrotate(stack, stack_a, stack_b);
	push(stack_a, stack_b, stack_a, stack_b);
}

void	sort_five(t_stack *stack, t_stack *stack_a, t_stack *stack_b)
{
	push_smallest(stack, stack_a, stack_b);
	push_smallest(stack, stack_a, stack_b);
	sort_three(stack, stack_a, stack_b);
	push(stack_b, stack_a, stack_a, stack_b);
	push(stack_b, stack_a, stack_a, stack_b);
}

void	insertion_sort(t_stack *stack, t_stack *stack_a, t_stack *stack_b)
{
	if (stack->size <= 1)
		return ;
	if (stack->size == 2 && stack->top->value > stack->top->next->value)
        swap(stack, stack_a, stack_b);
	if (stack->size == 3)
		sort_three(stack, stack_a, stack_b);
	else if (stack->size > 3)
		sort_five(stack, stack_a, stack_b);
}