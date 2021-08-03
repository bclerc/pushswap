/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 23:47:23 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/02 21:29:14 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int get_stack_size(t_stack **stack)
{
    t_stack *tmp;
    int     i;

    i = 0;
    tmp = *stack;
    while (tmp->next)
    {
        tmp = tmp->next;   
        i++;
    }

    return (i);
}

int check_sort(t_stack *stack)
{
    int last;
    t_stack *tmp;

    tmp = stack;
    while (tmp->next)
    {
        if (tmp->value > tmp->next->value)
            return 0;
        tmp = tmp->next;
    }
    return 1;
}
 