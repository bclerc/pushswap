/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:00:18 by bclerc            #+#    #+#             */
/*   Updated: 2021/07/13 15:04:43 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	sa(t_push *push)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	t_stack	*tmp3;
	t_stack	*tmp4;

	if (push->sizea > 1)
	{
		tmp1 = push->stacka;
		tmp2 = tmp1->next;
		tmp3 = tmp2->next;
		tmp2->next = tmp1;
		push->stacka = tmp2;
		push->stacka->next = tmp1;
		tmp4 = push->stacka->next;
		tmp4->next = tmp3;
	}
}

void	sb(t_push *push)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	t_stack	*tmp3;
	t_stack	*tmp4;

	if (push->sizeb > 1)
	{
		tmp1 = push->stackb;
		tmp2 = tmp1->next;
		tmp3 = tmp2->next;
		tmp2->next = tmp1;
		push->stackb = tmp2;
		push->stackb->next = tmp1;
		tmp4 = push->stackb->next;
		tmp4->next = tmp3;
	}
}

void	ss(t_push *push)
{
	sa(push);
	sb(push);
}
