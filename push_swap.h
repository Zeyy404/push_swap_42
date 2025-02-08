#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_list 
{
    int value;
    struct s_list *next;
} t_list;

typedef struct s_stack
{
    t_list *top;
    int size;
} t_stack;

int		ft_atoi(const char *nptr);
t_list	*ft_lstnew(int value);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		input_lst(t_list **lst, char *str);
int		is_duplicate(t_list *lst, int value);

#endif