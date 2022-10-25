/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:39:20 by salmazro          #+#    #+#             */
/*   Updated: 2022/10/25 22:17:44 by salmazro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

t_node	*ft_lstnew(int *data);
void	ft_lstadd_front(t_node **lst, t_node *new);
void	ft_lstadd_back(t_node **alst, t_node *data);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstdisplay(t_node *lst);
void	ft_check_int(const char *str, unsigned long num, int sign);
void	ft_check_doub(t_node *p, int x);
int		ft_atoi(const char *str);
void	ft_error(char *error);
void	ft_swap(int *a, int *b);
void	sa(t_node *lst);
void	ra(t_node *lst);
void	rra(t_node *lst);
void	pb(t_node **a, t_node **b);
void	sb(t_node *lst2);
void	rb(t_node *lst2);
void	rrb(t_node *lst2);
void	pa(t_node **b, t_node **a);
void	sort_three(t_node *lst);

#	endif
