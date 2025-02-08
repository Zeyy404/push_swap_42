/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 13:38:43 by zsalih            #+#    #+#             */
/*   Updated: 2025/02/08 20:01:40 by zsalih           ###   ########.fr       */
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

	errno = 0;
	value = ft_atoi(str);
	if (is_duplicate(*lst, (int)value) || (value == 0 && str[0] != '0') || (value == -1 && str[0] != '-'))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	ft_lstadd_back(lst, ft_lstnew((int)value));
	return (1);
}
