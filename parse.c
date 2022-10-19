/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:57:47 by salmazro          #+#    #+#             */
/*   Updated: 2022/10/14 20:21:36 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check int max
void ft_check_int(const char *str,unsigned long num, int sign)
{
	if (num == 2147483647 && sign == 1)
	{
		ft_error("int max error");
		exit(1);
	}
	else if (num == 2147483648 && sign == -1)
	{
		ft_error("int min error");
		exit(1);
	}
	else if (*str)
	{
		ft_error("error is alpha");
		exit(1);
	}
}

// atoi function
int ft_atoi(const char *str)
{
	unsigned long num;
	int sign;

	num = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - '0';
		str++;
	}
	ft_check_int(str, num, sign);
	return (num * sign);
}

// double checker : to check if there is any duplicate numbers
void ft_check_doub(t_node *p, int x)
{
	t_node *temp;

	temp = p;
	while (temp != NULL)
	{
		if (temp->data == x)
		{
			ft_putendl_fd("duplicate is found",2);
			exit(1);
		}
		temp = temp->next;
	}
}
