/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:47:37 by zsalih            #+#    #+#             */
/*   Updated: 2025/04/19 22:10:26 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *stack_a, t_stack *stack_b)
{
	ft_lstclear(&stack_a->top);
	free(stack_a);
	free(stack_b);
}

int	main(int ac, char **av)
{
	int		i;
	t_list	*lst;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 1;
	lst = NULL;
	if (ac >= 2)
	{
		while (i < ac)
		{
			if (!input_lst(&lst, av[i]))
			{
				ft_lstclear(&lst);
				return (1);
			}
			i++;
		}
		stack_a = init_stack(lst);
		stack_b = init_stack(NULL);
		quicksort_a(stack_a, stack_b, stack_a->size);
		ft_free(stack_a, stack_b);
	}
	return (0);
}
