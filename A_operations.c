/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:35:18 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/25 18:20:13 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function to swap numbers
void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// sa -> swap first 2 element
void	sa(t_node *a)
{
	ft_swap(&a->data, &a->next->data);
	write (1, "sa\n", 3);
}

// ra -> first element become last element
void	ra(t_node *a)
{
	t_node	*temp;

	temp = a;
	while (a->next != NULL)
	{
		ft_swap(&a->data, &a->next->data);
		a = a->next;
	}
	set_indexes(temp, NULL);
	write (1, "ra\n", 3);
}

// rra -> last element become first element
void	rra(t_node *a)
{
	t_node	*last_elem;
	t_node	*temp;

	temp = a;
	while (a->next != NULL)
	{
		last_elem = ft_lstlast(a);
		ft_swap(&last_elem->data, &a->data);
		a = a->next;
	}
	set_indexes(temp, NULL);
	write (1, "rra\n", 4);
}

//pa -> push the top element from stack b to stack a
void	pa(t_node **a, t_node **b)
{
	int		tmp;
	t_node	*tmp_stack;

	tmp_stack = NULL;
	if (!(*b))
	{
		write(2, "Nothing to push to a\n", 22);
		exit(1);
	}
	tmp = (*b)->data;
	tmp_stack = (*b)->next;
	free(*b);
	*b = tmp_stack;
	ft_lstadd_front(a, tmp);
	set_indexes(*a, *b);
	write(1, "pa\n", 3);
}
