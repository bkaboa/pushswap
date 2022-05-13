#include "../../Includes/pushswap.h"

char	*ra(t_all *all)
{
	t_stack	*temp_a;

	temp_a = all->stk_a;
	all->stk_a = temp_a->next;
	all->stk_a->previous = (void *) NULL;
	temp_a->next = (void *) NULL;
	temp_a->previous = all->last_stk_a;
	all->last_stk_a->next = temp_a;
	all->last_stk_a = temp_a;
	all->total_operation++;
	return ("ra\n");
}

char	*rb(t_all *all)
{
	t_stack	*temp_b;

	temp_b = all->stk_b;
	all->stk_b = temp_b->next;
	temp_b->previous = all->last_stk_b;
	all->last_stk_b->next = temp_b;
	all->last_stk_b = temp_b;
	all->last_stk_b->next = (void *) NULL;
	all->stk_b->previous = (void *) NULL;
	all->total_operation++;
	return ("rb\n");
}
