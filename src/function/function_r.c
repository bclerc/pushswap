/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:03:29 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/24 19:59:07 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;

	if ((*stack) && (*stack)->next)
	{
		tmp = *stack;
		head = (*stack)->next;
		*stack = (*stack)->next;
		tmp->next = NULL;
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = tmp;
		*stack = head;
		return (1);
	}
	return (0);
}

void	rr(t_push *push)
{
	rotate(push->stacka);
	rotate(push->stackb);
}
