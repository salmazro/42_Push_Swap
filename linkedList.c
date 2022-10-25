/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedList.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:39:23 by salmazro          #+#    #+#             */
/*   Updated: 2022/10/24 23:06:24 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// add a new list
t_node	*ft_lstnew(int *data)
{
	t_node	*lst;

	lst = (t_node *)malloc(sizeof(t_node));
	if (!lst)
		return (0);
	lst->data = *data;
	lst->next = NULL;
	return (lst);
}

// add element in the beginning of list
void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (new)
	{
		if (lst)
		{
			new->next = *lst;
			*lst = new;
		}
		else
			*lst = new;
	}
}

// add element in the end of list
void	ft_lstadd_back(t_node **alst, t_node *data)
{
	t_node	*last_elem;

	if (!*alst)
	{
		*alst = data;
		return ;
	}
	last_elem = ft_lstlast(*alst);
	last_elem->next = data;
}

// check last element in list
t_node	*ft_lstlast(t_node *lst)
{
	t_node	*elem;

	if (lst == NULL)
		return (NULL);
	elem = lst;
	while (elem->next != NULL)
		elem = elem->next;
	return (elem);
}

// display the list
void	ft_lstdisplay(t_node *lst)
{
	while (lst != NULL)
	{
		printf("%d\n", lst->data);
		lst = lst->next;
	}
}
