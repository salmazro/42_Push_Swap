/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:57:47 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/22 20:59:49 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
	{
		c++;
	}
	return (c);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy((char *)str, (s + start), len + 1);
	return (str);
}

// print error
void	ft_error(char *error, t_all *all, t_node *a, int toggle)
{
	if (all->indecies)
		free(all->indecies);
	if (all->sorted)
		free(all->sorted);
	if (toggle && a)
		ft_free(&a);
	if (all->stack_a)
		ft_free(all->stack_a);
	if (all->stack_b)
		ft_free(all->stack_b);
	if (all->split)
		free_split(all->split);
	while (*error)
		write(STDERR_FILENO, error++, 1);
	exit(EXIT_FAILURE);
}

void	exit_after_sort(t_all *all)
{
	if (all->indecies)
		free(all->indecies);
	if (all->sorted)
		free(all->sorted);
	if (all->stack_a)
		ft_free(all->stack_a);
	if (all->stack_b)
		ft_free(all->stack_b);
	if (all->split)
		free_split(all->split);
	exit(EXIT_SUCCESS);
}
