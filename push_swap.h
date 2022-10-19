/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:39:20 by salmazro          #+#    #+#             */
/*   Updated: 2022/10/14 20:21:39 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct s_node
{
	int data;
	struct s_node *next;
}	t_node;

void	display_lst(t_node *p);
void	ft_lstadd_back(t_node **alst, int ab);
t_node	*ft_lstlast(t_node *lst);
void ft_check_int(const char *str,unsigned long num, int sign);
void ft_check_doub(t_node *p, int x);
int ft_atoi(const char *str);
void	ft_error(char *error);
void	ft_putendl_fd(char *s, int fd);

# endif
