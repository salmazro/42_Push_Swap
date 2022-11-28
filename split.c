/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:55:59 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/23 22:21:30 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_words(char const *str, char set)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if ((*str != set) && !x)
		{
			x = 1;
			i++;
		}
		else if (*str == set)
			x = 0;
		str++;
	}
	return (i);
}

static char	**write_split(char **split, char const *str, char set)
{
	ssize_t	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = -1;
	while (i[0] <= (ssize_t)ft_strlen(str))
	{
		if (str[i[0]] != set && i[2] < 0)
			i[2] = i[0];
		else if ((str[i[0]] == set || i[0] == (ssize_t)ft_strlen(str)) \
		&& i[2] >= 0)
		{
			split[i[1]] = ft_substr(str, i[2], (i[0] - i[2]));
			if (!split[i[1]])
				return (ft_undo_alloc(split));
			i[2] = -1;
			i[1]++;
		}
		i[0]++;
	}
	split[i[1]] = NULL;
	return (split);
}

char	**ft_split(char const *str, char set)
{
	char	**split;

	if (!str)
		return (NULL);
	split = malloc(sizeof(char *) * (count_words(str, set) + 1));
	if (!split)
		return (NULL);
	split = write_split(split, str, set);
	return (split);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		k;

	k = -1;
	i = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		*s1 = '\0';
	}
	str = malloc((ft_strlen(s2) + ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++k])
		str[i++] = s2[k];
	str[i] = '\0';
	free(s1);
	return (str);
}
