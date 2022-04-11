
#include "../Includes/pushswap.h"

bool	push_parse(int ac, char **av)
{
	int		i;
	int		y;

	y = 0;
	i = 1;
	errno = 1;
	if (ac == 1)
		return (false);
	while (av[i])
	{
		while (av[i][y])
		{
			if ((av[i][y] < '0' || av[i][y] > '9') && av[i][y] != '-')
			{
				errno = 0;
				return (false);
			}
			y++;
		}
		i++;
		y = 0;
	}
	return (true);
}
