/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:03:41 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/28 19:36:31 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	pushs(t_stack **stack, t_stack **stack2)
{
	t_stack	*tmp1;

	tmp1 = *stack;
	*stack = tmp1->next;
	tmp1->next = *stack2;
	(*stack2) = tmp1;
	return (1);
}
