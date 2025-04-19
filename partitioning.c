/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitioning.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:48:09 by zsalih            #+#    #+#             */
/*   Updated: 2025/04/19 22:26:31 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	partition_rrotate(t_stack *stack, t_stack *stack_a,
		t_stack *stack_b, int rotated)
{
	if (rotated < stack->size)
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
	while (i < size)
	{
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
		if (vars.pushed >= size / 2)
			break ;
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
	while (i < size)
	{
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
		if (vars.pushed >= size)
			break ;
		i++;
	}
	partition_rrotate(stack, stack_a, stack_b, vars.rotated);
	return (vars.pushed);
}
