/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_3sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:22:26 by drakan            #+#    #+#             */
/*   Updated: 2022/01/19 21:07:17 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_case(t_push *c)
{
	if (c->list_a[0] > c->list_a[1]
		&& c->list_a[1] < c->list_a[2] && c->list_a[2] > c->list_a[0])
		return (1);
	if (c->list_a[0] > c->list_a[1]
		&& c->list_a[1] > c->list_a[2] && c->list_a[2] < c->list_a[0])
		return (2);
	if (c->list_a[0] > c->list_a[1] && c->list_a[1] < c->list_a[2]
		&& c->list_a[2] < c->list_a[0])
		return (3);
	if (c->list_a[0] < c->list_a[1] && c->list_a[1] > c->list_a[2]
		&& c->list_a[2] > c->list_a[0])
		return (4);
	if (c->list_a[0] < c->list_a[1] && c->list_a[1] > c->list_a[2]
		&& c->list_a[2] < c->list_a[0])
		return (5);
	return (0);
}

void	num_3sort(t_push *c)
{
	if (ft_get_case(c) == 1)
		sa(c, 0);
	else if (ft_get_case(c) == 2)
	{
		sa(c, 0);
		rra(c, 0);
	}
	else if (ft_get_case(c) == 3)
		ra(c, 0);
	else if (ft_get_case(c) == 4)
	{
		sa(c, 0);
		ra(c, 0);
	}
	else if (ft_get_case(c) == 5)
		rra(c, 0);
}
