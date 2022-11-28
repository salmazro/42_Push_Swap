/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:54:37 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/22 20:55:42 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// use it to free list a
void	ft_free(t_node **top)
{
	t_node	*tmp;

	tmp = NULL;
	while (*top != NULL)
	{
		tmp = *top;
		*top = (*top)->next;
		free(tmp);
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free (split);
}

char	**ft_undo_alloc(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	return (NULL);
}
