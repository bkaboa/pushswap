#include "../Includes/pushswap.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str, int n)
{
	if (n == 1)
		return (*str - '0');
	return (10 * ft_atoi(str, n - 1) + str[n - 1] - '0');
}
