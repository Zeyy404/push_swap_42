#include "push_swap.h"

static int	handle_overflow(long result, int sign)
{
	if (result > INT_MAX)
	{
		if (sign == -1)
		{
			if (result == 2147483648)
				return (-2147483648);
			return (0);
		}
		return (-1);
	}
	return (result * sign);
}

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
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
		result = result * 10 + ((*nptr) - '0');
		nptr++;
	}
	return (handle_overflow(result, sign));
}
