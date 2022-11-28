/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:30:51 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/22 15:26:40 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort two numbers
void	sort_two(t_node *lst)
{
	if (lst->data > lst->next->data)
		sa(lst);
}

// sort three numbers using all cases
void	sort_three(t_node *lst)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = lst->data;
	n2 = lst->next->data;
	n3 = lst->next->next->data;
	if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		sa(lst);
		ra(lst);
	}
	else if (n1 > n2 && n1 < n3 && n2 < n3)
		sa(lst);
	else if (n1 < n2 && n1 > n3 && n2 > n3)
		rra(lst);
	else if (n1 > n2 && n1 > n3 && n2 < n3)
		ra(lst);
	else if (n1 > n2 && n1 > n3 && n2 > n3)
	{
		sa(lst);
		rra(lst);
	}
}

// sort four using push and sort three
void	sort_four(t_node **a, t_node **b)
{
	rotate_a_up(*a, return_smallest(*a));
	pb(a, b);
	sort_three(*a);
	pa(b, a);
}

// sort five using push and sort four
void	sort_five(t_node **a, t_node **b)
{
	if (return_index(return_smallest(*a), *a) <= 3)
		rotate_a_up(*a, return_smallest(*a));
	else
		rotate_a_down(*a, return_smallest(*a));
	pb(a, b);
	sort_four(a, b);
	pa(b, a);
}

// sort big number
void	sort_big(t_all *all, int d, int tmp, int tmp2)
{
	while (ft_lstsize(*all->stack_a) != 0 && tmp < all->size)
	{
		if (d == all->chunk_size)
		{
			d = 0;
			tmp += tmp2;
			if (tmp > all->size)
				break ;
		}
		if (ft_lstsize(*all->stack_a) <= 100)
			sort_big_norm(all, &d, &tmp, 15);
		else if (ft_lstsize(*all->stack_a) <= 500)
			sort_big_norm(all, &d, &tmp, 30);
	}
	while (ft_lstsize(*all->stack_a) != 0)
		pb(all->stack_a, all->stack_b);
	sort_b(all);
}
