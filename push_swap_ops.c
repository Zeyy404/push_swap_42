#include "push_swap.h"

void	swap(t_stack *stack, t_stack *stack_a, t_stack *stack_b)
{
	t_list	*first;
	t_list	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	if (stack == stack_a)
		write(1, "sa\n", 3);
	else if (stack == stack_b)
		write(1, "sb\n", 3);
}

void	push(t_stack *src, t_stack *dest, t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp;

	if (!src || !src->top)
		return;
	tmp = src->top;
	src->top = tmp->next;
	tmp->next = dest->top;
	dest->top = tmp;
	src->size--;
	dest->size++;
	if (dest == stack_a)
		write(1, "pa\n", 3);
	else if (dest == stack_b)
		write(1, "pb\n", 3);
}

void	rotate(t_stack *stack, t_stack *stack_a, t_stack *stack_b)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !stack->top || !stack->top->next)
		return;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
	if (stack == stack_a)
		write(1, "ra\n", 3);
	else if (stack == stack_b)
		write(1, "rb\n", 3);
}

void	rrotate(t_stack *stack, t_stack *stack_a, t_stack *stack_b)
{
	t_list	*prev;
	t_list	*last;

	if (!stack || !stack->top || !stack->top->next)
		return;
	prev = NULL;
	last = stack->top;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->top;
	stack->top = last;
	if (stack == stack_a)
		write(1, "rra\n", 4);
	else if (stack == stack_b)
		write(1, "rrb\n", 4);
}

void	double_ops(t_stack *stack_a, t_stack *stack_b, char op)
{
	if (op == 's')
	{
		swap(stack_a, stack_a, stack_b);
		swap(stack_b, stack_a, stack_b);
		write(1, "ss\n", 3);
	}
	else if (op == 'r')
	{
		rotate(stack_a, stack_a, stack_b);
		rotate(stack_b, stack_a, stack_b);
		write(1, "rr\n", 3);
	}
	else if (op == 'R')
	{
		rrotate(stack_a, stack_a, stack_b);
		rrotate(stack_b, stack_a, stack_b);
		write(1, "rrr\n", 4);
	}
}