#include "../../Includes/pushswap.h"

static t_stack	*add_stk(void)
{
	t_stack	*new;
	new = malloc(sizeof(t_stack));
	return (new);
}

static void	init_list(t_all *all)
{
	u_int16_t	i;

	t_stack	*temp_a;
	t_stack	*new;

	temp_a = all->stk_a;
	i = 1;
	while (all->num[i])
	{
		new = add_stk();
		new->previous = temp_a;
		temp_a->next = new;
		temp_a = temp_a->next;
		temp_a->arg = ft_atoi(all->num[i]);
		temp_a->final_index = all->f_index[i] + 1;
		i++;
	}
	temp_a->next = NULL;
	all->last_stk_a = temp_a;
	temp_a = all->stk_a;
}

void	init_struct(t_all *all)
{
	all->stk_a = malloc(sizeof(t_stack));
	all->stk_a->previous = (void *) NULL;
	all->stk_b = (void *) NULL;
	all->stk_a->arg = ft_atoi(all->num[0]);
	all->stk_a->final_index = all->f_index[0] + 1;
	init_list(all);
}
