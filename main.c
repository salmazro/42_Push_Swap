/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:57:45 by salmazro          #+#    #+#             */
/*   Updated: 2022/10/14 20:25:57 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int i;
	int ab;
	t_node *head;

	i = 1;
	head = NULL;

	while (i < ac)
	{
		ab = ft_atoi(av[i]);
		// ft_check_doub(head, ab);
		if (ac >= 1)
			ft_lstadd_back(&head, ab);
		i++;
	}
	display_lst(head);
	return (0);
}
