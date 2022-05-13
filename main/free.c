#include "../Includes/pushswap.h"

void	free_stk_a(t_stack_a *stk_a)
{
	u_int16_t	i;
	t_stack_a	*temp_a;

	temp_a = stk_a->next;
	i = 0;
	while (stk_a->next != NULL)
	{
		free(stk_a->arg_a);
		free(stk_a);
		stk_a = temp_a;
		temp_a = stk_a->next;
	}
}

void	free_stk_b(t_stack_b *stk_b)
{
	u_int16_t	i;
	t_stack_a	temp_b;

	temp_b = stk_b->next;
	while (stk_b->next != NULL)
	{
		free(stk_b->arg_b);
		free(stk_b);
		stk_b = temp_b;
		temp_b = stk_b->next;
	}
}

void	free_all(t_all all)
{
	free_stk_a(all.stk_a);
	free_stk_b(all.stk_b);
	free_db_pointer(num);
	free(f_index);
}

void	free_db_pointer(char **str)
{
	u_int16_t	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
