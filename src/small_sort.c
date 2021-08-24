/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:00:42 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/24 19:59:56 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	three_sort(t_stack **stack)
{
	if (three_sa(stack))
		return ;
	if (three_sa_rra(stack))
		return ;
	if (three_ra(stack))
		return ;
	if (three_sa_ra(stack))
		return ;
	if (three_rra(stack))
		return ;
}
