/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:47:55 by zsalih            #+#    #+#             */
/*   Updated: 2025/04/20 20:10:45 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_silent(t_stack *stack)
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
}

void	push_silent(t_stack *src, t_stack *dest)
{
	t_list	*tmp;

	if (!src || !src->top)
		return ;
	tmp = src->top;
	src->top = tmp->next;
	tmp->next = dest->top;
	dest->top = tmp;
	src->size--;
	dest->size++;
}

void	rotate_silent(t_stack *stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
	first = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = first->next;
	first->next = NULL;
	last->next = first;
}

void	rrotate_silent(t_stack *stack)
{
	t_list	*prev;
	t_list	*last;

	if (!stack || !stack->top || !stack->top->next)
		return ;
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
}
