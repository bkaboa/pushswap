
#include "../../Includes/pushswap.h"

void	perso_errno_msg(void)
{
	u_int8_t	i;

	i = 0;
	while (i <= MAX_ERRNO && i != errno)
		i++;
	if (errno == s_tsa[i].code)
		write(2, s_tsa[i].msg, ft_strlen(s_tsa[i].msg));
}
