/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_selection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih < zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:48:03 by zsalih            #+#    #+#             */
/*   Updated: 2025/04/20 12:08:45 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	quicksort_lst(int *arr, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	if (left >= right)
		return ;
	pivot = arr[right];
	i = left - 1;
	j = left;
	while (j < right)
	{
		if (arr[j] < pivot)
			ft_swap(&arr[++i], &arr[j]);
		j++;
	}
	ft_swap(&arr[++i], &arr[right]);
	quicksort_lst(arr, left, i - 1);
	quicksort_lst(arr, i + 1, right);
}

int	find_median(t_list *top, int size)
{
	int		*values;
	t_list	*temp;
	int		median;
	int		i;

	values = malloc(size * sizeof(int));
	if (!values)
		return (0);
	temp = top;
	i = 0;
	while (i < size)
	{
		values[i] = temp->value;
		temp = temp->next;
		i++;
	}
	quicksort_lst(values, 0, size - 1);
	median = values[size / 2];
	free(values);
	return (median);
}
