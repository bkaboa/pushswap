
#include "../Includes/pushswap.h"

u_int8_t	ft_strlen(const char *str)
{
	u_int16_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int64_t	ft_atoi(const char *str)
{
	u_int64_t	num;
	u_int16_t	i;

	num = 0;
	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		num = num * 10 + str[i++] - '0';
	if (str[0] == '-')
		num *= -1;
	return (num);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	u_int16_t	i;
	u_int16_t	j;
	char		*str;

	i = ft_strlen(str1) + ft_strlen(str2);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	i = 0;
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		str[i] = str2[j];
		i++;
		j++;
	}
	return (str);
}

bool	ft_strcmp(char *str1, char *str2)
{
	u_int16_t	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	if (!str1[i] && !str2[i])
		return (true);
	return (false);
}

char	*ft_strdup(const char *str1)
{
	u_int16_t	i;
	char		*str;

	i = ft_strlen(str1);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i = 0;
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	return (str);
}
