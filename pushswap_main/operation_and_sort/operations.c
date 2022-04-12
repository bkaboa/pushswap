#include "../Includes/pushswap.h"

void	sa(t_all_in *stk_all_in)
{
	t_stack_a	*temp_a;

	temp_a = stk_all_in->stk_a->next;
	if (temp_a->next)
		stk_all_in->stk_a->next = temp_a->next;
	temp_a->next = stk_all_in->stk_a;
	stk_all_in->stk_a->index_a = 2;
	temp_a->index_a = 1;
	stk_all_in->stk_a = temp_a;
}

void	sb(t_all_in *stk_all_in)
{
	t_stack_a	*temp_b;

	temp_b = stk_all_in->stk_b->next;
	if (temp_b->next)
		stk_all_in->stk_b->next = temp_b->next;
	temp_b->next = stk_all_in->stk_b;
	stk_all_in->stk_b->index_b = 2;
	temp_b->index_b = 1;
	stk_all_in->stk_b = temp_b;
}

void	pa(t_all_in *stk_all_in)
{
	t_stack_a	temp_a;
	t_stack_b	temp_b;

	temp_b = stk_all_in->stk_b;
	temp_a = stk_all_in->stk_a;
	if (stk_all_in->stk_b)
	{
		stk_all_in->stk_b->next = stk_all_in->stk_a;
		stk_all_in->stk_a = stk_all_in->stk_b;
		stk_all_in->stk_b = temp_b;
		while (



