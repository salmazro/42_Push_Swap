/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:06:46 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/22 18:39:26 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_struct(t_all *all, t_node **a, t_node **b)
{
	all->size = ft_lstsize(*a);
	all->sorted = malloc(all->size * sizeof(int));
	if (!all->sorted)
		return ;
	all->stack_a = a;
	all->stack_b = b;
	parse_sorted(all);
	selection_sort(all->sorted, all->size);
	all->chunk_size = return_chunk_size(all);
	parse_indecies(all);
}

void	parse_sorted(t_all *all)
{
	int		i;
	t_node	*tmp;

	tmp = *(all->stack_a);
	i = 0;
	while (tmp && i < all->size)
	{
		all->sorted[i] = tmp->data;
		i++;
		tmp = tmp->next;
	}
}

void	selection_sort(int array[], int size)
{
	int	step;
	int	i;
	int	min_idx;

	step = 0;
	while (step < size - 1)
	{
		i = step + 1;
		min_idx = step;
		while (i < size)
		{
			if (array[i] < array[min_idx])
			min_idx = i;
			i++;
		}
		ft_swap(&array[min_idx], &array[step]);
		step++;
	}
}

void	parse_indecies(t_all *all)
{
	int	i;
	int	d;

	d = 0;
	all->indecies = malloc(all->size / all->chunk_size * sizeof(int));
	i = all->chunk_size;
	while (i < all->size)
	{
		all->indecies[d] = all->sorted[i];
		i += all->chunk_size;
		d++;
	}
}

int	return_chunk_size(t_all *all)
{
	if (all->size > 5 && all->size < 30)
		return (2);
	else if (all->size >= 30 && all->size < 50)
		return (4);
	else if (all->size >= 50 && all->size < 80)
		return (6);
	else if (all->size >= 80 && all->size < 200)
		return (8);
	else if (all->size >= 200 && all->size < 500)
		return (12);
	else if (all->size >= 500 && all->size < 800)
		return (16);
	else
		return (20);
}
