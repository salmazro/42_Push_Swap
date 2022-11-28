/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:57:47 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/25 17:59:09 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// this function is to check int max and min
void	ft_check_int(const char *str, unsigned long num, int sign, t_all *all)
{
	(void)str;
	if (num > 2147483647 && sign == 1)
	{
		ft_error("Error\n", all, NULL, 0);
	}
	else if (num > 2147483648 && sign == -1)
	{
		ft_error("Error\n", all, NULL, 0);
	}
}

// this function is to check alpha
static int	atoi_part2(const char *str, int *i, t_all *all, t_node *a)
{
	unsigned long	nums;

	nums = 0;
	while (str[*i] && !((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32))
	{
		if (!(str[*i] >= '0' && str[*i] <= '9'))
			ft_error("Error\n", all, a, 1);
		nums = (str[*i] - '0') + (nums * 10);
		ft_check_int(str, nums, all->sign, all);
		(*i)++;
	}
	return (nums);
}

// this function is to convert char to int
int	ft_atoi(const char *str, t_all *list, t_node *a)
{
	int				i;
	unsigned long	nums;

	i = 0;
	list->sign = 1;
	nums = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			list->sign *= -1;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
		nums = atoi_part2(str, &i, list, a);
	else
		ft_error("Error\n", list, a, 1);
	return (nums * list->sign);
}

// this function is to check if there is any duplicate numbers
void	ft_check_doub(t_node *p, int x, t_all *all)
{
	t_node	*temp;

	temp = p;
	while (temp != NULL)
	{
		if (temp->data == x)
		{
			ft_error("Error\n", all, p, 1);
		}
		temp = temp->next;
	}
}

// this function is to check if the numbers in order
void	ft_order(char **split, t_all *all, t_node **a)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = i + 1;
		while (split[j])
		{
			if (ft_atoi(split[i], all, *a) > ft_atoi(split[j], all, *a))
				return ;
			j++;
		}
		i++;
	}
	ft_error("", all, *a, 0);
}
