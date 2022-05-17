
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

# define MAX_ERRNO			4
# define MAX_CHAR_INT		11
# define ONL_INT_ARG		"error : only number are expected in arguments\n"
# define INV_ARG			"error : Invalid number of argument\n"
# define ARG_TOO_BIG_SMALL	"errror : arg must be between INT_MIN and INT_MAX\n"
# define ALREADY_SORT		"all arg already sort\n"
# define SAME_ARG			"error : two arg can not have the same value\n"


typedef char*	string;

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
	{2, ARG_TOO_BIG_SMALL},
	{3, ALREADY_SORT},
	{MAX_ERRNO, SAME_ARG},
};

/*
 *
 ******************************	structure		***
 */

typedef struct	s_stack
{
	int					final_index;
	int					arg;
	struct s_stack		*next;
	struct s_stack		*previous;
}	t_stack;

typedef struct	s_all
{
	t_stack		*stk_a;
	t_stack		*last_stk_a;
	t_stack		*stk_b;
	t_stack		*last_stk_b;
	int			argc;
	char		**argv;
	char		**num;
	u_int16_t	total_index;
	u_int16_t	first_index;
	u_int16_t	index_needed;
	int			total_operation;
	int			*f_index;
}	t_all;
/*
 *
 ******************************	pushswap_main	***
 */
void	num_take_arg(t_all *all);

/*
 *
 ******************************	struct			***
 */
void	init_struct(t_all *all);

/*
 *
 ******************************	error			***
 */
void	perso_errno_msg(void);

/*
 *
 ******************************	first_sort		***
 */

void	first_sort(t_all *all);

/*
 *
 ******************************	operations		***
 */

char	*sa(t_all *all);
char	*pa(t_all *all);
char	*pb(t_all *all);
char	*rra(t_all *all);
char	*rrb(t_all *all);
char	*ra(t_all *all);
char	*rb(t_all *all);
/*
 *
 ******************************	utils_functions	***
 */
u_int8_t	ft_strlen(const char *str);
int64_t		ft_atoi(const char *str);
bool		ft_strcmp(char *str, char *str1);
char		*ft_strjoin(const char *s1, const char *s2);
char		**ft_split(char *s, char set);
char		*ft_strdup(const char *s1);

/*
 *
 ******************************	utils_functions2***
 */
void		print(string str);

/*
 *
 ******************************	algo			***
 */
void	sort_3_num(t_all *all);
void	sort(t_all *all);

/*
 *
 ******************************	algo_utils		***
 */
bool		check_stk(t_stack *stk);
//u_int16_t	take_pos_first_arg(t_all *all);
u_int16_t	check_pos_first_arg(t_all *all);
u_int16_t	check_pos_elem_pos(t_all *all, int elem);


#endif
