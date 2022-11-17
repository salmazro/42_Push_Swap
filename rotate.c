/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:27:16 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/17 22:32:18 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_down(t_node *a, int data)
{
	while (return_index(data, a) != 0)
		rra(a);
}

void	rotate_a_up(t_node *a, int data)
{
	while (return_index(data, a) != 0)
		ra(a);
}

void	rotate_b_down(t_node *b, int data)
{
	while (return_index(data, b) != 0)
		rrb(b);
}

void	rotate_b_up(t_node *b, int data)
{
	while (return_index(data, b) != 0)
		rb(b);
}

void	rot_b(t_all *all)
{
	if (return_index(return_biggest(*all->stack_b),
			*all->stack_b) <= ft_lstsize(*all->stack_b) / 2)
		rotate_b_up(*all->stack_b, return_biggest(*all->stack_b));
	else
		rotate_b_down(*all->stack_b, return_biggest(*all->stack_b));
}
