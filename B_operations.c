/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:41:16 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/23 21:41:44 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sb -> swap first 2 element
void	sb(t_node *b)
{
	ft_swap(&b->data, &b->next->data);
	write (1, "sb\n", 3);
}

// rb -> first element become last element
void	rb(t_node *b)
{
	t_node	*temp;

	temp = b;
	while (b->next != NULL)
	{
		ft_swap(&b->data, &b->next->data);
		b = b->next;
	}
	set_indexes(temp, NULL);
	write (1, "rb\n", 3);
}

// rrb -> last element become first element
void	rrb(t_node *b)
{
	t_node	*last_elem;
	t_node	*temp;

	temp = b;
	while (b->next != NULL)
	{
		last_elem = ft_lstlast(b);
		ft_swap(&last_elem->data, &b->data);
		b = b->next;
	}
	set_indexes(temp, NULL);
	write (1, "rrb\n", 4);
}

//pb -> push the top element from stack a to stack b
void	pb(t_node **a, t_node **b)
{
	int		tmp;
	t_node	*tmp_stack;

	tmp_stack = NULL;
	if (!(*a))
	{
		write(2, "Nothing to push to b\n", 22);
		exit(1);
	}
	tmp = (*a)->data;
	tmp_stack = (*a)->next;
	free(*a);
	*a = tmp_stack;
	ft_lstadd_front(b, tmp);
	set_indexes(*b, *a);
	write(1, "pb\n", 3);
}
