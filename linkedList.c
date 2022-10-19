/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedList.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:39:23 by salmazro          #+#    #+#             */
/*   Updated: 2022/10/14 20:28:48 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// travel throught linked list
void	display_lst(t_node *p)
{
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
}

// add element
void	ft_lstadd_back(t_node **alst, int ab)
{
	t_node	*element = (t_node *)malloc(sizeof(t_node));
	t_node	*last = *alst;

	element->data = ab;
	element->next = NULL;

	while (last->next != NULL)
		last = last->next;

	last->next = element;
}
