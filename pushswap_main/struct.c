#include "../Includes/pushswap.h"

static t_stack_a	*new_stack_a(void)
{
	t_stack_a	next_stc_a;
	next_stc_a = malloc(sizeof(t_stack_a));
	return (next_stc_a);
}

static t_stack_b	*new_stack_b(void)
{
	t_stack_b	next_stc_b;
	next_stc_b = malloc(sizeof(t_stack_b));
	return (next_stc_b);
}

static void	put_in_stack(t_all_in *stc_all_in)
{
	int			i;
	t_stack_a	*stc_temp_a;
	t_stack_b	*stc_temp_b;
	t_stack_a	*stc_temp;

	stc_temp_a = stc_all_in->stk_a;
	stc_temp_b = stc_all_in->stk_b;
	i = 1;
	while (i < stc_all_in->argc)
	{
		stc_temp_a->arg_a = ft_atoi(av[i], ft_strlen(av[i]));
		stc_temp_a->index_a = i;
		stc_temp_b->index_b = i;
		stc_temp = new_stack_a();
		stc_temp_a->next = stc_temp;
		stc_temp_a = stc_temp_a->next;
		stc_temp = new_stack_b();
		stc_temp_b->next = stc_temp;
		stc_temp_b = stc_temp_b->next;
		i++;
	}
	stc_temp_a->next = (void *)NULL;
	stc_temp_b->next = (void *)NULL;
}

void	init_all_in_struct(int ac, char **av)
{
	t_all_in	stc_all_in;

	stc_all_in.argv = av:
	stc_all_in.argc = ac;
	stc_all_in.stk_a = malloc(sizeof(t_stack_a));
	stc_all_in.stk_b = malloc(sizeof(t_stack_b));
	put_in_stack(&stc_all_in);
}

void	free_list(t_all_in *stc_all_in)
{
	t_stack_a	temp_stc_a;
	t_stack_b	temp_stc_b;

	while (stc_all_in->stk_a != NULL && stc_all_in->stk_b != NULL)
	{
		temp_stc_a = stc_all_in->stk_a->next;
		temp_stc_b = stc_all_in->stk_b->next;
		free(stc_all_in->stk_a);
		free(stc_all_in->stk_b);
		stc_all_in->stk_a = temp_stc_a;
		stc_all_in->stk_b = temp_stc_b;
	}
}
