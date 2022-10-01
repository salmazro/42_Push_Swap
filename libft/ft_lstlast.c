/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:33:12 by salmazro          #+#    #+#             */
/*   Updated: 2021/10/13 12:33:16 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*elem;

	if (lst == NULL)
		return (NULL);
	elem = lst;
	while (elem->next != NULL)
		elem = elem->next;
	return (elem);
}
