/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:57:45 by salmazro          #+#    #+#             */
/*   Updated: 2022/10/25 23:30:20 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	int		data;
	t_node	*lst;
	t_node	*lst2;

	i = 1;
	lst = NULL;
	lst2 = NULL;
	while (i < ac)
	{
		data = ft_atoi(av[i]);
		ft_check_doub(lst, data);
		ft_lstadd_back(&lst, ft_lstnew(&data));
		i++;
	}

	printf("------------first-----------\n");
	pb(&lst, &lst2);
	printf("lst 1 -> \n");
	ft_lstdisplay(lst);
	printf("lst 2 -> \n");
	ft_lstdisplay(lst2);
	printf("------------second-----------\n");
	pb(&lst, &lst2);
	printf("lst 1 -> \n");
	ft_lstdisplay(lst);
	printf("lst 2 -> \n");
	ft_lstdisplay(lst2);
	printf("------------third-----------\n");
	pb(&lst, &lst2);
	printf("lst 1 -> \n");
	ft_lstdisplay(lst);
	printf("lst 2 -> \n");
	ft_lstdisplay(lst2);
	printf("-----------op-----------\n");
	printf("sort 3 output:\n");
	sort_three(lst2);
	ft_lstdisplay(lst2);

	printf("------------first-----------\n");
	pa(&lst2, &lst);
	printf("lst 2 -> \n");
	ft_lstdisplay(lst2);
	printf("lst 1 -> \n");
	ft_lstdisplay(lst);
	printf("------------second-----------\n");
	pa(&lst2, &lst);
	printf("lst 2 -> \n");
	ft_lstdisplay(lst2);
	printf("lst 1 -> \n");
	ft_lstdisplay(lst);
	printf("-----------op-----------\n");
	printf("sort 3 output:\n");
	sort_three(lst);
	ft_lstdisplay(lst);
}
