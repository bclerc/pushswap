/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:58:27 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/23 14:04:34 by bclerc           ###   ########.fr       */
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


typedef struct s_push
{
	int 	totalnumber;
	int		argc;
	int		size;
	int		ra;
	t_stack **stacka;
	t_stack **stackb;

}				t_push;

int	get_stack_size(t_stack **stack);
int		pushs(t_stack **stack, t_stack **stack2);
void	five_sort(t_push *push);
int 	three_sa(t_stack **stack);
int 	three_sa_rra(t_stack **stack);
int		three_ra(t_stack **stack);
int		three_sa_ra(t_stack **stack);
int		three_rra(t_stack **stack);
void 	ss(t_push *push);
void	rr(t_push *push);
int		rrr(t_push *push);
int		reverse_rotate(t_stack **stack);
void	swap(t_stack **stack);
int		rotate(t_stack **stack);
int 	check_sort(t_stack *stack);
int	 	add(int number, t_stack** stack);
void	readList(t_stack *stack);
void	stackdel(t_stack *alst);
void	stackdelone(t_stack *alst);
int		sort(t_push *push);
void	small_sort(t_push *push);
void 	three_sort(t_stack **stack);

# endif