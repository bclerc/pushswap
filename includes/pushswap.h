/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 15:58:27 by bclerc            #+#    #+#             */
/*   Updated: 2021/05/18 15:56:07 by bclerc           ###   ########.fr       */
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

#endif