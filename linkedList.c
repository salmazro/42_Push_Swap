/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedList.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:39:23 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/25 17:44:08 by salmazro         ###   ########.fr       */
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
void	ft_lstadd_front(t_node **head, int content)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	tmp->data = content;
	tmp->next = NULL;
	tmp->next = *head;
	(*head) = tmp;
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
