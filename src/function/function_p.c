/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:03:41 by bclerc            #+#    #+#             */
/*   Updated: 2021/07/13 15:05:04 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	pa(t_push *push)
{
	t_stack	*tmp;

	if (push->sizeb < 0)
		return (0);
	tmp = push->stacka;
	push->stacka = push->stacka->next;
	push->sizea--;
	push->sizeb++;
	add(tmp->value, &push->stackb);
	free(tmp);
	if (push->sizea < 1)
		push->stacka = NULL;
	return (1);
}

int	pb(t_push *push)
{
	t_stack	*tmp;

	if (push->sizea < 0)
		return (0);
	tmp = push->stackb;
	push->stackb = push->stackb->next;
	push->sizeb--;
	push->sizea++;
	add(tmp->value, &push->stacka);
	free(tmp);
	if (push->sizea < 1)
		push->stacka = NULL;
	return (1);
}
