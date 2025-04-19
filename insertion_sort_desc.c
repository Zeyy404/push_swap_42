#include "push_swap.h"

// static void	sort_three(t_stack *stack, t_stack *stack_a, t_stack *stack_b)
// {
// 	int a; 
//     int b;
//     int c;

// 	a = stack->top->value;
// 	b = stack->top->next->value;
// 	c = stack->top->next->next->value;
// 	if (a > b && b < c && a < c)
// 		rrotate(stack, stack_a, stack_b);
//     else if (a < b && b < c)
// 	{
// 		swap(stack, stack_a, stack_b);
// 		rrotate(stack, stack_a, stack_b);
// 	}
// 	else if (a > b && b < c && a > c)
//     {
// 		rrotate(stack, stack_a, stack_b);
//         swap(stack, stack_a, stack_b);
//     }
// 	else if (a < b && b > c && a < c)
// 		rotate(stack, stack_a, stack_b);
// 	else if (a < b && b > c && a > c)
// 		swap(stack, stack_a, stack_b);
// }

// static void	find_largest(t_stack *stack, int *largest, int *pos, int size)
// {
// 	t_list	*curr;
// 	int		idx;

// 	if (!stack || !stack->top)
// 		return;
// 	*largest = stack->top->value;
// 	*pos = 0;
// 	idx = 0;
// 	curr = stack->top;
// 	while (idx < size && curr)
// 	{
// 		if (curr->value < *largest)
// 		{
// 			*largest = curr->value;
// 			*pos = idx;
// 		}
// 		curr = curr->next;
// 		idx++;
// 	}
// }

// static void	push_largest(t_stack *stack, t_stack *stack_a, t_stack *stack_b, int size)
// {
// 	int	largest;
// 	int	pos;

// 	find_largest(stack, &largest, &pos, size);
// 	while (stack_a->top->value != largest)
// 		rotate(stack, stack_a, stack_b);
// 	push(stack_a, stack_b, stack_a, stack_b);
// }

// static void	sort_five(t_stack *stack, t_stack *stack_a, t_stack *stack_b, int size)
// {
// 	int to_push;
// 	int	pushed;

// 	to_push = size - 3;
// 	pushed = 0;
// 	while (to_push--)
// 	{
// 		push_largest(stack, stack_a, stack_b, size);
// 		pushed++;
// 	}
// 	sort_three(stack, stack_a, stack_b);
// 	while (pushed--)
// 		push(stack_b, stack_a, stack_a, stack_b);
// }

static void	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	int a; 
    int b;
    int c;

	a = stack_b->top->value;
	b = stack_b->top->next->value;
	c = stack_b->top->next->next->value;
	if (a > b && b < c && a < c)
	{
		push(stack_b, stack_a, stack_a, stack_b);
		swap(stack_b, stack_a, stack_b);
		push(stack_a, stack_b, stack_a, stack_b);
		swap(stack_b, stack_a, stack_b);
	}
	else if (a < b && b < c)
	{
		swap(stack_b, stack_a, stack_b);
		push(stack_b, stack_a, stack_a, stack_b);
		swap(stack_b, stack_a, stack_b);
		push(stack_a, stack_b, stack_a, stack_b);
		swap(stack_b, stack_a, stack_b);
	}
	else if (a > b && b < c && a > c)
    {
		push(stack_b, stack_a, stack_a, stack_b);
		swap(stack_b, stack_a, stack_b);
		push(stack_a, stack_b, stack_a, stack_b);
    }
	else if (a < b && b > c && a < c)
	{
		swap(stack_b, stack_a, stack_b);
		push(stack_b, stack_a, stack_a, stack_b);
		swap(stack_b, stack_a, stack_b);
		push(stack_a, stack_b, stack_a, stack_b);
	}
	else if (a < b && b > c && a > c)
		swap(stack_b, stack_a, stack_b);
}

void	insertion_sort_desc(t_stack *stack, t_stack *stack_a, t_stack *stack_b, int size)
{
	if (size <= 1)
		return ;
	if (size == 2 && stack->top->value < stack->top->next->value)
		swap(stack_b, stack_a, stack_b);
	if (size == 3)
		sort_three(stack_a, stack_b);
}