
#include "../Includes/pushswap.h"

int	main(int argc, char **argv)
{
	t_all_in	stk_all_in;
	argv[argc] = NULL;
	if (push_parse(argc, argv) == false)
	{
		perso_errno_msg();
		return (1);
	}
	stk_all_in = init_all_in_struct(argc, argv);
	printf("%d\n", stk_all_in.stk_a->index_a);
	printf("%d\n", stk_all_in.stk_a->arg_a);
	free_list(stk_all_in);
	return (0);
}
