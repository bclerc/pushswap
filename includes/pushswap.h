/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:58:27 by bclerc            #+#    #+#             */
/*   Updated: 2021/05/20 15:40:17 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include "libft/libft.h"
# include <stdio.h>


typedef struct		s_stack
{
	int 	value;
	void	*next;

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

void 	ss(t_push *push);
void 	sb(t_push *push);
void 	sa(t_push *push);
void	rr(t_push *push);
int 	pa(t_push *push);
int 	pb(t_push *push);
int		ra(t_push *push);
int		rb(t_push *push);
int	 	add(int number, t_stack** stack);

#endif