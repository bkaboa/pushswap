
#include "../../Includes/pushswap.h"

static void	already_sort(t_all all)
{
	u_int16_t	i;

	i = 0;
	while (all.num[i + 1] && ft_atoi(all.num[i]) < ft_atoi(all.num[i + 1]))
		i++;
	if (all.num[i + 1] == NULL)
		errno = 3;
}

static void	same_av(t_all all)
{
	u_int16_t	i;
	u_int16_t	y;

	i = 0;
	y = i + 1;
	if (errno != -1)
		return ;
	while (all.num[i])
	{
		while (all.num[y])
		{
			if (ft_strcmp(all.num[i], all.num[y]))
				errno = 4;
			y++;
		}
		i++;
		y = i + 1;
	}
	already_sort(all);
}

static void	more_than_int(t_all all)
{
	u_int16_t	i;

	i = 0;
	while (all.num[i])
	{
		if (ft_strlen(all.num[i]) > 11 || ft_atoi(all.num[i]) > INT32_MAX || \
			ft_atoi(all.num[i]) < INT32_MIN)
			errno = 2;
		i++;
	}
	same_av(all);
}

static void	push_parse(t_all all)
{
	u_int16_t	i;
	u_int16_t	y;

	y = 0;
	i = 0;
	if (errno != -1)
		return ;
	while (all.num[i])
	{
		while (all.num[i][y])
		{
			if (all.num[i][0] != '-')
			{
			if (all.num[i][y] < '0' || all.num[i][y] > '9')
				errno = 0;
			if (errno == 0)
				return ;
			}
			y++;
		}
		i++;
		y = 0;
	}
	more_than_int(all);
}

void	num_take_arg(t_all *all)
{
	char		*join;
	u_int16_t	i;

	i = 1;
	if (all->argc == 1)
	{
		errno = 1;
		return ;
	}
	join = ft_strjoin(all->argv[i++], " ");
	while (all->argv[i])
		join = ft_strjoin(join, ft_strjoin(all->argv[i++], " "));
	all->num = ft_split(join, ' ');
	i = 0;
	i = 0;
	free(join);
	i = 0;
	push_parse(*all);
}
