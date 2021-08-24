/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 20:00:39 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/24 20:02:56 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	three_sa(t_stack **stack)
{
	swap(stack);
	if (check_sort(*stack))
	{
		printf("%s\n", THREE_SA);
		return (1);
	}
	swap(stack);
	return (0);
}

int	three_sa_rra(t_stack **stack)
{
	swap(stack);
	reverse_rotate(stack);
	if (check_sort(*stack))
	{
		printf("%s\n", THREE_SA_RRA);
		return (1);
	}
	rotate(stack);
	swap(stack);
	return (0);
}

int	three_ra(t_stack **stack)
{
	rotate(stack);
	if (check_sort(*stack))
	{
		printf("%s\n", THREE_RA);
		return (1);
	}
	reverse_rotate(stack);
	return (0);
}

int	three_sa_ra(t_stack **stack)
{
	swap(stack);
	rotate(stack);
	if (check_sort(*stack))
	{
		printf("%s\n", THREE_SA_RA);
		return (1);
	}
	reverse_rotate(stack);
	swap(stack);
	return (0);
}

int	three_rra(t_stack **stack)
{
	reverse_rotate(stack);
	if (check_sort(*stack))
	{
		printf("%s\n", THREE_RRA);
		return (1);
	}
	rotate(stack);
	return (0);
}
