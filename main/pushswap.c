#include "../Includes/pushswap.h"

int main(int argc, char **argv)
{
	t_all all;

	errno = -1;
	all.total_index = argc - 1;
	all.total_operation = 0;
	all.first_index = 1;
	argv[argc] = NULL;
	all.argv = argv;
	all.argc = argc;
	num_take_arg(&all);
	if (errno > -1)
	{
		perso_errno_msg();
		return (-1);
	}
	first_sort(&all);
	init_struct(&all);
	if (all.total_index <= 3)
		sort_3_num(&all);
	if (all.total_index > 3)
		sort(&all);
	return (0);
}
