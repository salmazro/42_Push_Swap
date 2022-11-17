/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:57:45 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/17 22:52:07 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_stuff(t_all *all, int flag)
// {
// 	int	i;

// 	i = -1;
// 	if (flag == STACK_A)
// 		ft_lstdisplay(*all->stack_a);
// 	else if (flag == SORTED)
// 	{
// 		while (++i < all->size)
// 			printf("sorted[%d] is: %d\n", i, all->sorted[i]);
// 	}
// 	else if (flag == STACK_B)
// 		ft_lstdisplay(*all->stack_b);
// 	else if (flag == CHUNK_SIZE)
// 		printf("chunk_size is %d\n", all->chunk_size);
// 	else if (flag == INDECIES)
// 	{
// 		while (++i < all->size / all->chunk_size)
// 			printf("indecie of %d is %d\n",i , all->indecies[i]);
// 	}
// 	else if (flag == SIZE)
// 		printf("size is %d\n", all->size);
// 	else if (flag == LARGEST_A)
// 		printf("Largest number in a is %d\n", return_biggest(*all->stack_a));
// 	else if (flag == LARGEST_B)
// 		printf("Largest number in b is %d\n", return_biggest(*all->stack_b));
// }

int	main(int ac, char **av)
{
	int		data;
	int		*sorted;
	t_node	*a;
	t_node	*b;
	t_all	all;

	all.i = 1;
	a = NULL;
	b = NULL;
	sorted = NULL;
	while (all.i < ac)
	{
		data = ft_atoi(av[all.i]);
		ft_check_doub(a, data);
		ft_lstadd_back(&a, ft_lstnew(&data));
		all.i++;
	}
	set_indexes(a, b);
	parse_struct(&all, &a, &b, sorted);
	parse_algo(&all);
	free(all.indecies);
	free(all.sorted);
}
