/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:38:43 by zsalih            #+#    #+#             */
/*   Updated: 2025/02/10 13:04:59 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_list *lst, int value)
{
	while (lst)
	{
		if (lst->value == value)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	input_lst(t_list **lst, char *str)
{
	int	value;
	int	i;
	int error;
	char	**strs;

	i = 0;
	error = 0;
	strs = ft_split(str, ' ');
	while (strs[i])
	{
		value = ft_atoi(strs[i], &error);
		if (is_duplicate(*lst, (int)value) || (value == 0 && str[0] != '0') || (value == -1 && str[0] != '-') || error == 1)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		ft_lstadd_back(lst, ft_lstnew((int)value));
		i++;
	}
	return (1);
}

t_stack	*init_stack(t_list *lst)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = lst;
	stack->size = ft_lstsize(lst);
	return (stack);
}