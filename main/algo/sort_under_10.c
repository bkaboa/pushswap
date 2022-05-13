#include "../../Includes/pushswap.h"

void	sort_3_num(t_all *all)
{
	u_int8_t	i;
	int32_t		first_arg;
	int32_t		second_arg;
	int32_t		third_arg;

	first_arg = all->stk_a->arg;
	second_arg = all->stk_a->next->arg;
	third_arg = all->last_stk_a->arg;
	if (third_arg > first_arg && third_arg > second_arg)
		i = 3;
	else if (second_arg > first_arg && second_arg > third_arg)
		i = 2;
	else
		i = 1;
	if (i == 1)
		print(ra(all));
	else if(i == 2)
		print(rra(all));
	if (check_stk(all->stk_a) == false)
		print(sa(all));
}

void	sort_5_num(t_all *all)
{
	u_int8_t	pos;

	pos = check_pos_first_arg(all);
	if (pos > all->final_index / 2)
		dorra(all);
	else
		dora(all);

	
