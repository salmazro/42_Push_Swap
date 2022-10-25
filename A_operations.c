/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_operations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:35:18 by salmazro          #+#    #+#             */
/*   Updated: 2022/10/25 22:27:29 by salmazro         ###   ########.fr       */
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
void	sa(t_node *lst)
{
	ft_swap(&lst->data, &lst->next->data);
	write (1, "sa\n", 3);
}

// ra -> first element become last element
void	ra(t_node *lst)
{
	while (lst->next != NULL)
	{
		ft_swap(&lst->data, &lst->next->data);
		lst = lst->next;
	}
	write (1, "ra\n", 3);
}

// rra -> last element become first element
void	rra(t_node *lst)
{
	t_node	*last_elem;

	while (lst->next != NULL)
	{
		last_elem = ft_lstlast(lst);
		ft_swap(&last_elem->data, &lst->data);
		lst = lst->next;
	}
	write (1, "rra\n", 4);
}

//pb -> push the top element from stack a to stack b
void	pb(t_node **a, t_node **b)
{
	t_node	*temp;

	temp = *a;
	ft_lstadd_front(b, ft_lstnew(&(*a)->data));
	*a = (*a)->next;
	free(temp);
	temp = NULL;
	write (1, "pb\n", 3);
}
