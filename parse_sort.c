/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:08:44 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/22 18:41:24 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// get the smallest number in list
int	return_smallest(t_node *lst)
{
	int	min;

	min = INT_MAX;
	while (lst != NULL)
	{
		if (min > lst->data)
			min = lst->data;
		lst = lst->next;
	}
	return (min);
}

int	return_biggest(t_node *lst)
{
	int	max;

	max = INT_MIN;
	while (lst != NULL)
	{
		if (max < lst->data)
			max = lst->data;
		lst = lst->next;
	}
	return (max);
}

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

void	sort_big_norm(t_all *all, int *d, int *tmp, int i)
{
	if ((*all->stack_a)->data <= all->sorted[*tmp])
	{
		pb(all->stack_a, all->stack_b);
		*d = *d + 1;
	}
	else if ((*all->stack_a)->data <= all->sorted[*tmp + i])
	{
		pb(all->stack_a, all->stack_b);
		rb(*all->stack_b);
		*d = *d + 1;
	}
	else if (return_first_index(all->sorted[*tmp], *all->stack_a) > \
			(ft_lstsize(*all->stack_a) - \
			return_last_index(all->sorted[*tmp], *all->stack_a)))
		rra(*all->stack_a);
	else
		ra(*all->stack_a);
}

// check the all->size of list to know which sort to use
void	parse_algo(t_all *all)
{
	int	i;
	int	tmp;
	int	tmp2;

	i = 0;
	tmp = all->chunk_size;
	tmp2 = tmp;
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
		sort_big(all, i, tmp, tmp2);
	exit_after_sort(all);
}
