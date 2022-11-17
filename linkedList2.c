/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedList2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:59:02 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/17 19:28:05 by salmazro         ###   ########.fr       */
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

// get the smallest number in list
int	return_smallest(t_node *lst)
{
	int	min;

	min = INT_MAX;
	while (lst != NULL)
	{
		if (min > lst->data)
			min = lst->data;
		lst = lst->next;
	}
	return (min);
}

int	return_biggest(t_node *lst)
{
	int	max;

	max = INT_MIN;
	while (lst != NULL)
	{
		if (max < lst->data)
			max = lst->data;
		lst = lst->next;
	}
	return (max);
}
