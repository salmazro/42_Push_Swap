/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:06:46 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/17 22:25:30 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_struct(t_all *all, t_node **a, t_node **b, int *array)
{
	all->size = ft_lstsize(*a);
	array = malloc(all->size * sizeof(int));
	all->sorted = array;
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
