#include "../../Includes/pushswap.h"

char	*rra(t_all *all)
{
	t_stack	*last_temp_a;

	last_temp_a = all->last_stk_a;
	all->last_stk_a = last_temp_a->previous;
	all->last_stk_a->next = (void *) NULL;
	last_temp_a->previous = (void *) NULL;
	last_temp_a->next = all->stk_a;
	all->stk_a->previous = last_temp_a;
	all->stk_a = last_temp_a;
	all->total_operation++;
	return ("rra\n");
}

char	*rrb(t_all *all)
{
	t_stack	*last_temp_b;

	last_temp_b = all->last_stk_b;
	all->last_stk_b = all->last_stk_b->previous;
	all->last_stk_b->next = (void *) NULL;
	last_temp_b->previous = (void *) NULL;
	last_temp_b->next = all->stk_b;
	all->stk_b->previous = last_temp_b;
	all->stk_b = last_temp_b;
	all->total_operation++;
	return ("rrb\n");
}
