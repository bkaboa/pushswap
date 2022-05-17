#include "../../Includes/pushswap.h"

void	dora(t_all *all, u_int16_t	pos)
{
	while (pos)
	{
		pos--;
		print(ra(all));
	}
}

void	dorra(t_all *all, u_int16_t	pos)
{
	while (pos < all->total_index)
	{
		pos++;
		print(rra(all));
	}
}

void	sort(t_all *all)
{
	u_int16_t	pos;
	t_stack		*temp_b;

	while (all->total_index > 3)
	{
		pos = check_pos_first_arg(all);
		if (pos == 1)
			print(sa(all));
		else if (((double) all->total_index / pos) <= 2)
			dorra(all, pos);
		else
			dora(all, pos);
		print(pb(all));
	}
	sort_3_num(all);
	temp_b = all->stk_b;
	while (temp_b)
	{
		temp_b = temp_b->next;
		print(pa(all));
	}
}
