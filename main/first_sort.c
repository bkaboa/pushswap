#include "../Includes/pushswap.h"

void	first_sort(t_all *all)
{
	u_int16_t	i;
	u_int16_t	y;

	i = 0;
	y = 0;
	while (all->num[i])
		i++;
	all->f_index = malloc(sizeof(int) * i);
	i = 0;
	while (all->num[i])
	{
		all->f_index[i] = 0;
		while (all->num[y])
		{
			if (ft_atoi(all->num[i]) > ft_atoi(all->num[y]))
				all->f_index[i]++;
			y++;
		}
		i++;
		y = 0;
	}
}
