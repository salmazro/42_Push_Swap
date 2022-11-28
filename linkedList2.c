/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedList2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:59:02 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/22 18:34:39 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// get list size
int	ft_lstsize(t_node *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// set list index every time you use operation
void	set_indexes(t_node *lst, t_node *lst2)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst->index = i;
		lst = lst->next;
		i++;
	}
	i = 0;
	while (lst2 != NULL)
	{
		lst2->index = i;
		lst2 = lst2->next;
		i++;
	}
}

// get data index in list
int	return_index(int data, t_node *lst)
{
	while (lst != NULL)
	{
		if (lst->data == data)
			return (lst->index);
		lst = lst->next;
	}
	return (-1);
}

// get the index of the element
int	return_last_index(int data, t_node *lst)
{
	int	last;

	while (lst != NULL)
	{
		if (lst->data <= data)
			last = lst->index;
		lst = lst->next;
	}
	return (last);
}

// get the index of the element
int	return_first_index(int data, t_node *lst)
{
	while (lst != NULL)
	{
		if (lst->data <= data)
			return (lst->index);
		lst = lst->next;
	}
	return (-1);
}
