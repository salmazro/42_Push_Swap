/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:30:51 by salmazro          #+#    #+#             */
/*   Updated: 2022/10/21 19:29:20 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_node *lst)
{
	int n1;
	int n2;
	int n3;

	n1 = lst->data;
	n2 = lst->next->data;
	n3 = lst->next->next->data;
	// 1	3	2
	if (n1 < n2 && n1 < n3 && n2 > n3)
	{
		sa(lst);
		ra(lst);
	}
	// 2	1	3
	else if (n1 > n2 && n1 < n3 && n2 < n3)
		sa(lst);
	// 2	3	1
	else if (n1 < n2 && n1 > n3 && n2 > n3)
		rra(lst);
	// 3	1	2
	else if (n1 > n2 && n1 > n3 && n2 < n3)
		ra(lst);
	// 3	2	1
	else if (n1 > n2 && n1 > n3 && n2 > n3)
	{
		sa(lst);
		rra(lst);
	}
}
