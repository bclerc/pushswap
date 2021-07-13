/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 13:11:41 by bclerc            #+#    #+#             */
/*   Updated: 2021/07/13 15:42:45 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int three_sa(t_push *push)
{
    printf("ici : \n");
    readList(push->stacka);
    sa(push);
    readList(push->stacka);
    if (check_sort(push, push->stacka))
    {
        printf("%s\n", THREE_SA);
        return (1);
    }
    sa(push);
    return (0);
}

int three_sa_rra(t_push *push)
{
    sa(push);
    rra(push);
    if (check_sort(push, push->stacka))
    {
        printf("%s\n", THREE_SA_RRA);
        return (1);
    }
    ra(push);
    sa(push);
    return (0);
}

int three_ra(t_push *push)
{
    ra(push);
    if (check_sort(push, push->stacka))
    {
        printf("%s\n", THREE_RA);
        return (1);
    }
    rra(push);
    readList(push->stacka);
    return (0);
}

int three_sa_ra(t_push *push)
{
    sa(push);
    ra(push);
    if (check_sort(push, push->stacka))
    {
        printf("%s\n", THREE_SA_RA);
        return (1);
    }
    rra(push);
    sa(push);
    return (0);
}

int three_rra(t_push *push)
{
    rra(push);
    if (check_sort(push, push->stacka))
    {
        printf("%s\n", THREE_RRA);
        return (1);
    }
    ra(push);
    return (0);
}
