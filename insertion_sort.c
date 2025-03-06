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
        reverse_rotate(stack, stack_a, stack_b);
    }
    else if (a > b && b < c && a > c)
        rotate(stack, stack_a, stack_b);
    else if (a < b && b > c && a < c)
    {
        swap(stack, stack_a, stack_b);
        rotate(stack, stack_a, stack_b);
    }
    else if (a < b && b > c && a > c)
        reverse_rotate(stack, stack_a, stack_b);
}

void	sort_five(t_stack *stack, t_stack *stack_a, t_stack *stack_b)
{

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