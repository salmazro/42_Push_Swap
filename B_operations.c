/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:41:16 by salmazro          #+#    #+#             */
/*   Updated: 2022/10/25 23:16:43 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sb -> swap first 2 element
void	sb(t_node *lst2)
{
	ft_swap(&lst2->data, &lst2->next->data);
	write (1, "sb\n", 3);
}

// rb -> first element become last element
void	rb(t_node *lst2)
{
	while (lst2->next != NULL)
	{
		ft_swap(&lst2->data, &lst2->next->data);
		lst2 = lst2->next;
	}
	write (1, "rb\n", 3);
}

// rrb -> last element become first element
void	rrb(t_node *lst2)
{
	t_node	*last_elem;

	while (lst2->next != NULL)
	{
		last_elem = ft_lstlast(lst2);
		ft_swap(&last_elem->data, &lst2->data);
		lst2 = lst2->next;
	}
	write (1, "rrb\n", 4);
}

//pa -> push the top element from stack b to stack a
void	pa(t_node **b, t_node **a)
{
	t_node	*temp;

	temp = *b;
	ft_lstadd_front(a, ft_lstnew(&(*b)->data));
	*b = (*b)->next;
	free(temp);
	temp = NULL;
	write (1, "pb\n", 3);
}
