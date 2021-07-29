/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:00:18 by bclerc            #+#    #+#             */
/*   Updated: 2021/07/28 16:14:12 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if ((*stack) == NULL)
		return ;
	tmp1 = *stack;
	tmp2 = (*stack)->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	(*stack) = tmp2;
}

void	ss(t_push *push)
{
	swap(push->stacka);
	swap(push->stackb);
}
