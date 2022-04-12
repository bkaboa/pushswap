
#include "../Includes/pushswap.h"

static void	max_min_arg(char *str)
{
	int		i;

	i = ft_strlen(str);
	if (ft_atoi(str, i) > INT_MAX)
		errno = 2;
	else if (ft_atoi(str, i) < INT_MIN)
		errno = 3;
}


bool	push_parse(int ac, char **av)
{
	int		i;
	int		y;

	y = 0;
	i = 1;
	errno = -1;
	if (ac == 1)
		errno = 1;
	while (av[i])
	{
		while (av[i][y])
		{
			if ((av[i][y] < '0' || av[i][y] > '9') && av[i][y] != '-')
				errno = 0;
			y++;
		}
		max_min_arg(av[i]);
		i++;
		y = 0;
		if (errno >= 0)
			return (false);
	}
	return (true);
}

void	perso_errno_msg(void)
{
	int		i;

	i = 0;
	while (i <= MAX_ERRNO && i != errno)
		i++;
	if (errno == s_tsa[i].code)
		write(2, s_tsa[i].msg, ft_strlen(s_tsa[i].msg));
}
