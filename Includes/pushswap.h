
#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <limits.h>


/*
 *
 ******************************	define			***
 */
# define MAX_ERRNO			3
# define N_CHAR_INT_MAX		10
# define N_CHAR_INT_MIN		11
# define ONL_INT_ARG		"error : only number are expected in arguments\n"
# define INV_ARG			"error : Invalid number of argument\n"
# define ARG_SUP_INT_MAX	"error : arg can not be superior to INT_MAX\n"
# define ARG_INF_INT_MIN	"errror : arg can not be inferior to INT_MIN\n"

/*
 *
 ******************************	new_error		***
 */
static const struct {
	int	code;
	char *msg; 
} s_tsa[] = {
	{0, ONL_INT_ARG},
	{1, INV_ARG},
	{2, ARG_SUP_INT_MAX},
	{MAX_ERRNO, ARG_INF_INT_MIN},
};

/*
 *
 ******************************	structure		***
 */

typedef struct s_stack_a
{
	int					index_a;
	int					arg_a;
	struct s_stack_a	*next;
}	t_stack_a;

typedef struct s_stack_b
{
	int					index_b;
	int					arg_b;
	struct s_stack_b	*next;
}	t_stack_b;

typedef struct s_all_in
{
	t_stack_a		*stk_a;
	t_stack_b		*stk_b;
	int				argc;
	char			**argv;
}	t_all_in;
/*
 *
 ******************************	pushswap_main	***
 */
bool	push_parse(int ac, char **av);


/*
 *
 ******************************	error			***
 */
void	perso_errno_msg(void);

/*
 *
 ******************************	struct			***
 */
t_all_in	init_all_in_struct(int ac, char **av);
void		free_list(t_all_in str_all_in);

/*
 *
 ******************************	utils_functions	***
 */
size_t		ft_strlen(char *str);
long long	ft_atoi(char *str, int n);
#endif
