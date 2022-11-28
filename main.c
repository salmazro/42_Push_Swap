/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:57:45 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/25 18:20:40 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// this function checks the parsing part
void	parse(t_node **a, t_all *all, int ac, char **av)
{
	char	*c;
	int		data;
	int		i;

	c = NULL;
	data = 0;
	while (all->i < ac)
	{
		c = ft_strjoin(c, " ");
		c = ft_strjoin(c, av[all->i]);
		all->i++;
	}
	i = count_words(c, ' ');
	all->split = ft_split(c, ' ');
	free (c);
	all->i = 0;
	while (all->i < i)
	{
		data = ft_atoi(all->split[all->i], all, *a);
		ft_check_doub(*a, data, all);
		ft_order(all->split, all, a);
		ft_lstadd_back(a, ft_lstnew(&data));
		all->i++;
	}
}

// this function is used to initialize variables for int main
void	init_struct(t_all *all)
{
	all->sorted = 0;
	all->indecies = 0;
	all->size = 0;
	all->chunk_size = 0;
	all->i = 1;
	all->stack_a = NULL;
	all->split = NULL;
	all->stack_b = NULL;
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	t_all	all;

	a = NULL;
	b = NULL;
	init_struct(&all);
	parse(&a, &all, ac, av);
	set_indexes(a, b);
	parse_struct(&all, &a, &b);
	parse_algo(&all);
}
