/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:08:44 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/17 22:37:17 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b(t_all *all)
{
	while (ft_lstsize(*all->stack_b) != 0)
	{
		if (return_index(return_biggest(*all->stack_b), *all->stack_b) == 0)
		{
			pa(all->stack_a, all->stack_b);
		}
		else
			rot_b(all);

	}
}

int	return_chunk_size(t_all *all)
{
	if (all->size > 5 && all->size < 30)
		return (2);
	else if (all->size >= 30 && all->size < 50)
		return (3);
	else if (all->size >= 50 && all->size < 80)
		return (5);
	else if (all->size >= 80 && all->size < 200)
		return (8);
	else if (all->size >= 200 && all->size < 500)
		return (12);
	else if (all->size >= 500 && all->size < 800)
		return (16);
	else
		return (20);
}

// check the all->size of list to know which sort to use
void	parse_algo(t_all *all)
{
	if (all->size == 1)
		exit(0);
	else if (all->size == 2)
		sort_two(*(all->stack_a));
	else if (all->size == 3)
		sort_three(*(all->stack_a));
	else if (all->size == 4)
		sort_four(all->stack_a, all->stack_b);
	else if (all->size == 5)
		sort_five(all->stack_a, all->stack_b);
	else
		sort_big(all);
}
