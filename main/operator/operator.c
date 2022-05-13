#include "../../Includes/pushswap.h"

char	*sa(t_all *all)
{
	t_stack	*temp_a;
	
	temp_a = all->stk_a->next;
	all->stk_a->next = temp_a->next;
	all->stk_a->previous = temp_a;
	temp_a->next = all->stk_a;
	temp_a->previous = (void *) NULL;
	all->stk_a = temp_a;
	all->total_operation++;
	return ("sa\n");
}

char	*pa(t_all *all)
{
	t_stack	*temp_b;
	
	if (!all->stk_b)
		return (NULL);
	temp_b = all->stk_b;
	all->total_index++;
	if (temp_b->next)
	{
		all->stk_b = temp_b->next;
	}
	all->stk_a->previous = temp_b;
	temp_b->next = all->stk_a;
	all->stk_a = temp_b;
	return ("pa\n");
}

char	*pb(t_all *all)
{
	t_stack	*temp_a;
	
	temp_a = all->stk_a;
	all->stk_a = all->stk_a->next;
	all->total_index--;
	if (!all->stk_b)
	{
		temp_a->next = NULL;
		all->stk_b = temp_a;
		return ("pb\n");
	}
	temp_a->next = all->stk_b;
	all->stk_b->previous = temp_a;
	all->stk_b = temp_a;
	return ("pb\n");
}
