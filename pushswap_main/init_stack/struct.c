#include "../Includes/pushswap.h"

static t_stack_a	*new_stack_a(void)
{
	t_stack_a	*next_stk_a;
	next_stk_a = malloc(sizeof(t_stack_a));
	return (next_stk_a);
}

static t_stack_b	*new_stack_b(void)
{
	t_stack_b	*next_stk_b;
	next_stk_b = malloc(sizeof(t_stack_b));
	return (next_stk_b);
}

static void	put_in_stack(t_all_in *stk_all_in)
{
	int			i;
	t_stack_a	*stk_temp_a;
	t_stack_b	*stk_temp_b;
	t_stack_a	*stk_temp;
	t_stack_b	*stk_temp2;
	char		*str_av;

	stk_temp_a = stk_all_in->stk_a;
	stk_temp_b = stk_all_in->stk_b;
	i = 1;
	while (i < stk_all_in->argc)
	{
		str_av = stk_all_in->argv[i];
		stk_temp_a->arg_a = ft_atoi(str_av, ft_strlen(str_av));
		stk_temp_a->index_a = i;
		stk_temp_b->index_b = i;
		stk_temp = new_stack_a();
		stk_temp_a->next = stk_temp;
		stk_temp_a = stk_temp_a->next;
		stk_temp2 = new_stack_b();
		stk_temp_b->next = stk_temp2;
		stk_temp_b = stk_temp_b->next;
		i++;
	}
	stk_temp_a->next = (void *)NULL;
	stk_temp_b->next = (void *)NULL;
}

t_all_in	init_all_in_struct(int ac, char **av)
{
	t_all_in	stk_all_in;

	stk_all_in.argv = av;
	stk_all_in.argc = ac;
	stk_all_in.stk_a = malloc(sizeof(t_stack_a));
	stk_all_in.stk_b = malloc(sizeof(t_stack_b));
	put_in_stack(&stk_all_in);
	//tri(&stk_all_in);
	return (stk_all_in);
}

void	free_list(t_all_in stk_all_in)
{
	t_stack_a	*temp_stk_a;
	t_stack_b	*temp_stk_b;

	while (stk_all_in.stk_a->next != NULL && stk_all_in.stk_b->next != NULL)
	{
		temp_stk_a = stk_all_in.stk_a->next;
		temp_stk_b = stk_all_in.stk_b->next;
		free(stk_all_in.stk_a);
		free(stk_all_in.stk_b);
		stk_all_in.stk_a = temp_stk_a;
		stk_all_in.stk_b = temp_stk_b;
	}
	free(stk_all_in.stk_a);
	free(stk_all_in.stk_b);
}
