#include "push_swap.h"

// int find_median(t_list *top, int size) 
// {
//     if (size <= 1) {
//         return top->value;
//     }
//     t_list *mid = top;
//     t_list *last = top;
//     int i = 0;
//     while (last->next) {
//         if (i < size / 2) {
//             mid = mid->next;
//         }
//         last = last->next;
//         i++;
//     }
//     int first = top->value;
//     int middle = mid->value;
//     int last_value = last->value;
//     if ((first >= middle && first <= last_value) || (first <= middle && first >= last_value)) {
//         return first;
//     } else if ((middle >= first && middle <= last_value) || (middle <= first && middle >= last_value)) {
//         return middle;
//     } else {
//         return last_value;
//     }
// }

// int is_sorted(t_stack *stack, int size)
// {
//     t_list *curr = stack->top;
//     int i = 0;

//     if (!stack || size <= 1)
//         return (1);
//     while (i < size - 1 && curr->next && curr)
//     {
//         if (curr->value < curr->next->value)
//             return (0); // Not sorted
//         curr = curr->next;
//         i++;
//     }
//     return (1); // Already sorted
// }

static void ft_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void quicksort_lst(int *arr, int left, int right)
{
    if (left >= right)
        return;
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (arr[j] < pivot)
            ft_swap(&arr[++i], &arr[j]);
    }
    ft_swap(&arr[++i], &arr[right]);
    quicksort_lst(arr, left, i - 1);
    quicksort_lst(arr, i + 1, right);
}

int find_median(t_list *top, int size)
{
    if (size <= 0 || !top)
        return 0;
    
    int *values = malloc(size * sizeof(int));
    if (!values)
        return 0;
    
    t_list *temp = top;
    for (int i = 0; i < size; i++)
    {
		if (!temp)
		{
    		free(values);
			return 0;
		}
        values[i] = temp->value;
        temp = temp->next;
    }
    quicksort_lst(values, 0, size - 1);
    int median = values[size / 2];
    free(values);
    
    return median;
}

static void	partition_rrotate(t_stack *stack, t_stack *stack_a, t_stack *stack_b,
		int rotated)
{
	while (rotated--)
		rrotate(stack, stack_a, stack_b);
}

// int	partitions(t_stack *stack_a, t_stack *stack_b, int size)
// {
// 	int		pivot;
// 	int		pushed;
// 	int		rotated;

// 	pushed = 0;
// 	rotated = 0;
// 	if (stack_a->size <= 5)
// 		return (0);
// 	pivot = find_median(stack_a->top, stack_a->size);
// 	while ((pushed + rotated) < size)
// 	{
// 		if (stack_a->top->value < pivot)
// 		{
// 			push(stack_a, stack_b, stack_a, stack_b);
// 			pushed++;
// 		}
// 		else
// 		{
// 			rotate(stack_a, stack_a, stack_b);
// 			rotated++;
// 		}
// 	}
// 	return (partition_rrotate(stack_a, stack_b, rotated), pushed);
// }

int partitions(t_stack *stack, t_stack *stack_a, t_stack *stack_b, int size)
{
    int pivot;
    int pushed = 0;
    int rotated = 0;
    int i = 0;

    pivot = find_median(stack->top, size);
	// printf("stack_a pivot = [%d]\n", pivot);
    while (i < size)
    {
        if (stack->top->value < pivot) 
        {
            push(stack, stack_b, stack_a, stack_b);
            pushed++;
        }
        else
        {
            rotate(stack, stack_a, stack_b);
            rotated++;
        }
        i++;
    }
    partition_rrotate(stack, stack_a, stack_b, rotated);
    return (pushed);
}

int partitions_rev(t_stack *stack, t_stack *stack_a, t_stack *stack_b, int size)
{
    int pivot;
    int pushed = 0;
    int rotated = 0;
    int i = 0;

    pivot = find_median(stack->top, size);
	// printf("stack_b pivot = [%d]\n", pivot);
    while (i < size)
    {
		if (stack->top == NULL)
			break ;
        if (stack->top->value >= pivot) 
        {
            push(stack, stack_a, stack_a, stack_b);
            pushed++;
        }
        else
        {
            rotate(stack, stack_a, stack_b);
            rotated++;
        }
        i++;
    }
    partition_rrotate(stack, stack_a, stack_b, rotated);
    return ((size - pushed));
}

void quicksort(t_stack *stack, t_stack *stack_a, t_stack *stack_b, int size)
{
    int pushed;

    if (!stack || !stack->top || size <= 1) 
        return;
    if (size <= 3) 
    {
		if (stack == stack_a)
		{
			// printf("stack_a\n");
        	insertion_sort(stack, stack_a, stack_b, size);
		}
		if (stack == stack_b)
		{
			// printf("stack_b\n");
        	insertion_sort_desc(stack, stack_a, stack_b, size);
		}
		// t_list *tmp1 = stack->top;
        // for (int i = 0; i < size; i++)
        // {
        //     printf("%d, ", tmp1->value);
        //     tmp1 = tmp1->next;
        // }
        // printf("\nGoing back\n");
        return ;
    }
    if (stack == stack_a)
        pushed = partitions(stack, stack_a, stack_b, size);  // Partition only 'size' elements
    else
		pushed = partitions_rev(stack, stack_a, stack_b, size);

	// printf("pushed = [%d]\n", pushed);
	// printf("size = [%d]\n", size);
	// if (pushed == 0)  // Prevent infinite recursion if no elements were moved
    // {
    //     if (stack == stack_a)
    //         insertion_sort(stack, stack_a, stack_b, size);
    //     else
    //         insertion_sort_desc(stack, stack_a, stack_b, size);
    //     return;
    // }
    // printf("Recursing on stack_a (size = %d)\n", size - pushed);
    // printf("Recursing on stack_b (size = %d)\n", pushed);
    // t_list *tmp2 = stack_a->top;
    // for (int i = 0; i < size - pushed; i++)
	// {
	// 	printf("%d, ", tmp2->value);
    //     tmp2 = tmp2->next;
	// }
    // t_list *tmp3 = stack_b->top;
    // for (int i = 0; i < pushed; i++)
	// {
	// 	printf("%d, ", tmp3->value);
    //     tmp3 = tmp3->next;
	// }
	if (stack == stack_a)
	{
		quicksort(stack_a, stack_a, stack_b, (size - pushed));
		quicksort(stack_b, stack_a, stack_b, pushed);
		while (pushed--)
			push(stack_b, stack_a, stack_a, stack_b);
		return ;
	}
	if (stack == stack_b)
	{
		quicksort(stack_b, stack_a, stack_b, pushed);
		quicksort(stack_a, stack_a, stack_b, (size - pushed));
		while (pushed--)
			push(stack_a, stack_b, stack_a, stack_b);
		return ;
	}
}
