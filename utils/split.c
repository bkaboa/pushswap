/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:40:02 by czang             #+#    #+#             */
/*   Updated: 2022/03/31 21:40:04 by czang            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pushswap.h"

static size_t	sentences_size(char *str, char set)
{
	size_t	i;
	size_t	y;

	y = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == set)
		{
			y++;
			while (str[i] == set && str[i])
				i++;
		}
		i++;
	}
	return (y);
}

static char	*word(const char *str, char set)
{
	char		*tmp;
	u_int16_t	i;

	i = 0;
	tmp = ft_strdup(str);
	while (tmp[i] && tmp[i] != set)
		i++;
	tmp[i] = '\0';
	return (tmp);
}

static char	*free_split(char ***split, char **str)
{
	u_int16_t	i;

	i = 0;
	while (*split[i])
		free(*split[i++]);
	free(*split);
	free(*str);
	return (NULL);
}

static char	**work(char **split, char *str, char set, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		if (*str != set)
		{
			split[i] = word(str, set);
			if (!split[i])
				return ((char **)(free_split(&split, &str)));
			str = str + ft_strlen(split[i]);
			i++;
		}
		str++;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char *str, char set)
{
	char	**split;
	size_t	i;

	i = sentences_size(str, set);
	split = malloc(sizeof(char *) * (i + 1));
	if (!split)
		return (NULL);
	split[i] = NULL;
	return (work(split, str, set, i));
}
