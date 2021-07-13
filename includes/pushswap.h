/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:58:27 by bclerc            #+#    #+#             */
/*   Updated: 2021/07/13 15:01:20 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "libft/libft.h"
# include <stdio.h>
# define THREE_SA "sa"
# define THREE_SA_RRA "sa rra"
# define THREE_SA_RA "sa ra"
# define THREE_RRA "rra"
# define THREE_RA "ra"



typedef struct		s_stack
{
	int 	value;
	struct s_stack *next;

}				t_stack;

typedef struct s_push
{
	int 	totalnumber;
	int		argc;
	int		sizea;
	int		sizeb;
	t_stack *stacka;
	t_stack *stackb;

}				t_push;

int 	three_sa(t_push *push);
int 	three_sa_rra(t_push *push);
int		three_ra(t_push *push);
int		three_sa_ra(t_push *push);
int		three_rra(t_push *push);
void 	ss(t_push *push);
void 	sb(t_push *push);
void 	sa(t_push *push);
void	rr(t_push *push);
int 	pa(t_push *push);
int 	pb(t_push *push);
int		ra(t_push *push);
int		rb(t_push *push);
int		rra(t_push *push);
int		rrb(t_push *push);
int		rrr(t_push *push);
int 	check_sort(t_push *push, t_stack *stack);
int	 	add(int number, t_stack** stack);
void	readList(t_stack *stack);
void	stackdel(t_stack *alst);
void	stackdelone(t_stack *alst);
void	small_sort(t_push *push);
void 	three_sort(t_push *push);

# endif