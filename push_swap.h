/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsalih <zsalih@student.42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:49:37 by zsalih            #+#    #+#             */
/*   Updated: 2025/04/20 20:09:39 by zsalih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	t_list			*top;
	int				size;
}					t_stack;

typedef struct s_partition_vars
{
	int				pushed;
	int				rotated;
	int				pivot;
}					t_partition_vars;

# define MAX_INSTRUCTION_LEN 5

int					ft_atoi(const char *nptr, int *error);
char				**ft_split(char const *s, char c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
t_list				*ft_lstnew(int value);
void				ft_lstclear(t_list **lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
int					input_lst(t_list **lst, char *str);
int					is_duplicate(t_list *lst, int value);
t_stack				*init_stack(t_list *lst);
void				swap(t_stack *stack, t_stack *stack_a, t_stack *stack_b);
void				push(t_stack *src, t_stack *dest, t_stack *stack_a,
						t_stack *stack_b);
void				rotate(t_stack *stack, t_stack *stack_a, t_stack *stack_b);
void				rrotate(t_stack *stack, t_stack *stack_a, t_stack *stack_b);
void				insertion_sort(t_stack *stack, t_stack *stack_a,
						t_stack *stack_b, int size);
void				insertion_sort_base(t_stack *stack, t_stack *stack_a,
						t_stack *stack_b);
void				insertion_sort_desc(t_stack *stack, t_stack *stack_a,
						t_stack *stack_b, int size);
void				quicksort_a(t_stack *stack_a, t_stack *stack_b, int size);
int					is_sorted_a(t_stack *stack, int size);
int					partition_a(t_stack *stack, t_stack *stack_a,
						t_stack *stack_b, int size);
int					partition_b(t_stack *stack, t_stack *stack_a,
						t_stack *stack_b, int size);
int					find_median(t_list *top, int size);

void				swap_silent(t_stack *stack);
void				push_silent(t_stack *src, t_stack *dest);
void				rotate_silent(t_stack *stack);
void				rrotate_silent(t_stack *stack);

#endif