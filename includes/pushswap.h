/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:58:27 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/25 14:27:06 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "libft/libft.h"
# include <stdio.h>
# define THREE_SA "sa"
# define THREE_SA_RRA "sa\nrra"
# define THREE_SA_RA "sa\nra"
# define THREE_RRA "rra"
# define THREE_RA "ra"



typedef struct		s_stack
{
	int 	value;
	struct s_stack *next;

}				t_stack;

typedef	struct		s_instruct 
{
	int	type;
	int top;
	int	needed;
}					t_instruct;

typedef struct	s_median
{
	int quarter;
	int median;
	int three_quarter;	
}				t_median;

typedef struct s_push
{
	int 	totalnumber;
	int		argc;
	int		size;
	int		tried;
	int		ra;
	t_stack **stacka;
	t_stack **stackb;

}				t_push;

t_median	get_all_median(t_stack **stack);
void		exit_error(t_push *push, char *msg);
void 		ss(t_push *push);
void		rr(t_push *push);
void		five_sort(t_push *push);
void		swap(t_stack **stack);
void		readList(t_stack *stack);
void		stackdel(t_stack *alst);
void		stackdelone(t_stack *alst);
void 		three_sort(t_stack **stack);
void		smagll_sort(t_push *push);
void		do_instruct(t_push *push, t_instruct instruct);
void		smart_push_a(t_push *push);
void		value_sort(int *value, int len);
int			get_stack_size(t_stack **stack);
int			is_in_stack(int value, t_stack **stack);
int			repush_a(t_push *push, int *i);
int			big_sort(t_push *push);
int			pushs(t_stack **stack, t_stack **stack2);
int			three_sa(t_stack **stack);
int 		three_sa_rra(t_stack **stack);
int			three_ra(t_stack **stack);
int			three_sa_ra(t_stack **stack);
int			three_rra(t_stack **stack);
int			rrr(t_push *push);
int			reverse_rotate(t_stack **stack);
int			rotate(t_stack **stack);
int 		check_sort(t_stack *stack);
int	 		add(int number, t_stack** stack);
int			sort(t_push *push);
int			get_median(t_stack **stack);
int			get_high_pos(t_stack **stack);
int			get_low_pos(t_stack **stack);
int			check_if_ra(t_push *push, int part, int median);

# endif