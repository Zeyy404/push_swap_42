#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_list	*first;
	t_list	*second;

	if (stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	push(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*tmp;

	if (!stack_a || !stack_a->top)
		return ;
	tmp = stack_a->top;
	stack_a->top = tmp->next;
	stack_a->size--;
	tmp->next = stack_b->top;
	stack_b->top = tmp;
	stack_b->size++;
}

void	rotate(t_stack *stack)
{
	t_list	*curr;
	t_list	*tmp;

	curr = stack->top;
	while(curr->next)
	{
		curr = curr->next;
	}
	tmp = stack->top;
	stack->top = stack->top->next;
	tmp->next = curr->next;
	curr->next = tmp;
}

void	rrotate(t_stack *stack)
{
	
}