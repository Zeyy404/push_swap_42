#include "push_swap.h"

void	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	int a; 
    int b;
    int c;

	a = stack_a->top->value;
	b = stack_a->top->next->value;
	c = stack_a->top->next->next->value;
	if (a > b && b < c && a < c)
		swap(stack_a, stack_a, stack_b);
	else if (a > b && b > c)
	{
		swap(stack_a, stack_a, stack_b);
		push(stack_a, stack_b, stack_a, stack_b);
		swap(stack_a, stack_a, stack_b);
		push(stack_b, stack_a, stack_a, stack_b);
		swap(stack_a, stack_a, stack_b);
	}
	else if (a > b && b < c && a > c)
	{
		swap(stack_a, stack_a, stack_b);
		push(stack_a, stack_b, stack_a, stack_b);
		swap(stack_a, stack_a, stack_b);
		push(stack_b, stack_a, stack_a, stack_b);
	}
	else if (a < b && b > c && a < c)
    {
		push(stack_a, stack_b, stack_a, stack_b);
		swap(stack_a, stack_a, stack_b);
		push(stack_b, stack_a, stack_a, stack_b);
	}
	else if (a < b && b > c && a > c)
	{
		push(stack_a, stack_b, stack_a, stack_b);
		swap(stack_a, stack_a, stack_b);
		push(stack_b, stack_a, stack_a, stack_b);
		swap(stack_a, stack_a, stack_b);
	}
}

void	insertion_sort(t_stack *stack, t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size <= 1)
		return ;
	if (size == 2 && stack->top->value > stack->top->next->value)
		swap(stack_a, stack_a, stack_b);
	if (size == 3)
		sort_three(stack_a, stack_b);
}
