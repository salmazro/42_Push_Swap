/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmazro <salmazro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:39:20 by salmazro          #+#    #+#             */
/*   Updated: 2022/11/25 18:12:21 by salmazro         ###   ########.fr       */
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
	char			**split;
	int				size;
	int				chunk_size;
	int				i;
	int				sign;
}	t_all;

t_node			*ft_lstnew(int *data);
void			ft_lstadd_front(t_node **head, int content);
void			ft_lstadd_back(t_node **alst, t_node *data);
t_node			*ft_lstlast(t_node *lst);
int				ft_lstsize(t_node *lst);
void			set_indexes(t_node *lst, t_node *lst2);
int				return_index(int data, t_node *lst);
int				return_last_index(int data, t_node *lst);
int				return_first_index(int data, t_node *lst);

int				ft_atoi(const char *str, t_all *list, t_node *a);
void			ft_check_doub(t_node *p, int x, t_all *all);
void			ft_order(char **split, t_all *all, t_node **a);
size_t			count_words(char const *str, char set);
char			**ft_split(char const *str, char set);
char			*ft_strjoin(char *s1, char *s2);

size_t			ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_error(char *error, t_all *all, t_node *a, int toggle);
void			exit_after_sort(t_all *all);
void			ft_free(t_node **top);
void			free_split(char **split);
char			**ft_undo_alloc(char **s);

void			ft_swap(int *a, int *b);
void			sa(t_node *a);
void			ra(t_node *a);
void			rra(t_node *a);
void			pa(t_node **a, t_node **b);
void			rb(t_node *b);
void			rrb(t_node *b);
void			pb(t_node **a, t_node **b);

void			parse_struct(t_all *all, t_node **a, t_node **b);
void			parse_sorted(t_all *all);
void			selection_sort(int array[], int size);
void			parse_indecies(t_all *all);
int				return_chunk_size(t_all *all);
int				return_smallest(t_node *lst);
int				return_biggest(t_node *lst);
void			sort_b(t_all *all);
void			sort_big_norm(t_all *all, int *d, int *tmp, int i);
void			parse_algo(t_all *all);
void			sort_two(t_node *lst);
void			sort_three(t_node *lst);
void			sort_four(t_node **a, t_node **b);
void			sort_five(t_node **a, t_node **b);
void			sort_big(t_all *all, int d, int tmp, int tmp2);
void			rotate_a_down(t_node *a, int data);
void			rotate_a_up(t_node *a, int data);
void			rot_b(t_all *all);

#	endif
