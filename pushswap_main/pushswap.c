
#include "../Includes/pushswap.h"

int	main(int argc, char **argv)
{
	argv[argc] = NULL;
	if (push_parse(argc, argv) == false)
	{
		perso_errno_msg();
		return (1);
	}
	init_all_in_struct(argc, argv);
	return (0);
}
