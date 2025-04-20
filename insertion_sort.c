/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:48:33 by zsalih            #+#    #+#             */
/*   Updated: 2025/04/20 14:32:58 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_1(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, stack_a, stack_b);
	push(stack_a, stack_b, stack_a, stack_b);
	swap(stack_a, stack_a, stack_b);
	push(stack_b, stack_a, stack_a, stack_b);
	swap(stack_a, stack_a, stack_b);
}

static void	case_2(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, stack_a, stack_b);
	push(stack_a, stack_b, stack_a, stack_b);
	swap(stack_a, stack_a, stack_b);
	push(stack_b, stack_a, stack_a, stack_b);
}

static void	case_3(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b, stack_a, stack_b);
	swap(stack_a, stack_a, stack_b);
	push(stack_b, stack_a, stack_a, stack_b);
	swap(stack_a, stack_a, stack_b);
}

static void	sort_three(t_stack *stack_a, t_stack *stack_b)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->top->value;
	b = stack_a->top->next->value;
	c = stack_a->top->next->next->value;
	if (a > b && b < c && a < c)
		swap(stack_a, stack_a, stack_b);
	else if (a > b && b > c)
		case_1(stack_a, stack_b);
	else if (a > b && b < c && a > c)
		case_2(stack_a, stack_b);
	else if (a < b && b > c && a < c)
	{
		push(stack_a, stack_b, stack_a, stack_b);
		swap(stack_a, stack_a, stack_b);
		push(stack_b, stack_a, stack_a, stack_b);
	}
	else if (a < b && b > c && a > c)
		case_3(stack_a, stack_b);
}

void	insertion_sort(t_stack *stack, t_stack *stack_a, t_stack *stack_b,
		int size)
{
	if (size <= 1)
		return ;
	if (size == 2 && stack->top->value > stack->top->next->value)
		swap(stack_a, stack_a, stack_b);
	else if (size == 3)
		sort_three(stack_a, stack_b);
}
