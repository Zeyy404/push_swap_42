#include "push_swap.h"
#include <stdio.h>

int main(int ac, char **av)
{
	int		i;
	t_list	*lst;

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
		
	}
	return (0);
}
