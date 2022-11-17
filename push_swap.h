/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:39:20 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/17 22:51:56 by salmazro         ###   ########.fr       */
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
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_all
{
	int				*sorted;
	int				*indecies;
	t_node			**stack_a;
	t_node			**stack_b;
	int				size;
	int				chunk_size;
	int				i;
}	t_all;

# define STACK_A	1
# define SORTED		2
# define STACK_B	3
# define CHUNK_SIZE	4
# define INDECIES	5
# define SIZE		6
# define LARGEST_A	7
# define LARGEST_B	8

t_node	*ft_lstnew(int *data);
void	ft_lstadd_front(t_node **head, int content);
void	ft_lstadd_back(t_node **alst, t_node *data);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstdisplay(t_node *lst);
int		ft_lstsize(t_node *lst);
void	set_indexes(t_node *lst, t_node *lst2);
int		return_index(int data, t_node *lst);
int		return_smallest(t_node *lst);
int		return_biggest(t_node *lst);

void	ft_check_int(const char *str, unsigned long num, int sign);
void	ft_check_doub(t_node *p, int x);
int		ft_atoi(const char *str);
void	ft_error(char *error);

void	parse_struct(t_all *all, t_node **a, t_node **b, int *array);
void	parse_sorted(t_all *all);
void	selection_sort(int array[], int size);
void	parse_indecies(t_all *all);

void	rotate_a_down(t_node *a, int data);
void	rotate_a_up(t_node *a, int data);
void	rotate_b_down(t_node *b, int data);
void	rotate_b_up(t_node *b, int data);
void	rot_b(t_all *all);

void	sort_b(t_all *all);
int		return_chunk_size(t_all *all);
void	parse_algo(t_all *all);

void	sort_two(t_node *lst);
void	sort_three(t_node *lst);
void	sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);
void	sort_big(t_all *all);

void	ft_swap(int *a, int *b);
void	sa(t_node *a);
void	ra(t_node *a);
void	rra(t_node *a);
void	pa(t_node **b, t_node **a);
void	sb(t_node *b);
void	rb(t_node *b);
void	rrb(t_node *b);
void	pb(t_node **a, t_node **b);

void	print_stuff(t_all *all, int flag);

#	endif
