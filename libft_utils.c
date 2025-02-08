#include "push_swap.h"

long	ft_strtol(char *nptr, char **endptr, int base)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (sign == 1 && result > LONG_MAX / base)
			return ((errno = ERANGE), (*endptr = nptr), LONG_MAX);
		else if (result > LONG_MAX / base)
			return ((errno = ERANGE), (*endptr = nptr), LONG_MIN);
		result = result * base + (*nptr - '0');
		nptr++;
	}
	*endptr = nptr;
	return (result * sign);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}

t_list	*ft_lstnew(int value)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*next_node;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next_node = tmp->next;
		free(tmp);
		tmp = next_node;
	}
	*lst = NULL;
}
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
