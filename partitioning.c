/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitioning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:48:09 by zsalih            #+#    #+#             */
/*   Updated: 2025/04/20 19:52:19 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_pushable(t_list *top, int pivot, int size, int is_stack_a)
{
	int	count;

	count = 0;
	while (top && count < size)
	{
		if ((is_stack_a && top->value < pivot) || (!is_stack_a
				&& top->value >= pivot))
			return (1);
		top = top->next;
		count++;
	}
	return (0);
}

static void	partition_rrotate(t_stack *stack, t_stack *stack_a,
		t_stack *stack_b, int rotated)
{
	if (rotated <= (stack->size / 2))
		while (rotated--)
			rrotate(stack, stack_a, stack_b);
}

int	partition_a(t_stack *stack, t_stack *stack_a, t_stack *stack_b, int size)
{
	t_partition_vars	vars;
	int					i;

	vars.pushed = 0;
	vars.rotated = 0;
	i = 0;
	vars.pivot = find_median(stack->top, size);
	while (vars.pushed <= (size / 2) && i < size)
	{
		if (!has_pushable(stack->top, vars.pivot, size - i, 1))
			break ;
		if (stack->top->value < vars.pivot)
		{
			push(stack, stack_b, stack_a, stack_b);
			vars.pushed++;
		}
		else
		{
			rotate(stack, stack_a, stack_b);
			vars.rotated++;
		}
		i++;
	}
	partition_rrotate(stack, stack_a, stack_b, vars.rotated);
	return (vars.pushed);
}

int	partition_b(t_stack *stack, t_stack *stack_a, t_stack *stack_b, int size)
{
	t_partition_vars	vars;
	int					i;

	vars.pushed = 0;
	vars.rotated = 0;
	i = 0;
	vars.pivot = find_median(stack->top, size);
	while (vars.pushed <= (size / 2) && i < size)
	{
		if (!has_pushable(stack->top, vars.pivot, size - i, 0))
			break ;
		if (stack->top->value >= vars.pivot)
		{
			push(stack, stack_a, stack_a, stack_b);
			vars.pushed++;
		}
		else
		{
			rotate(stack, stack_a, stack_b);
			vars.rotated++;
		}
		i++;
	}
	partition_rrotate(stack, stack_a, stack_b, vars.rotated);
	return (vars.pushed);
}
