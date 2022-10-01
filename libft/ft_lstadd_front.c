/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:31:38 by salmazro          #+#    #+#             */
/*   Updated: 2021/10/13 12:32:00 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
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
