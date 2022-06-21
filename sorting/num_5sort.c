/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_5sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:12:19 by drakan            #+#    #+#             */
/*   Updated: 2022/01/19 21:07:00 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	num_5sort_2(t_push *c)
{
	int	len;

	len = c->len;
	if (len == 2)
	{
		if (c->list_a[0] > c->list_a[1])
			sa(c, 0);
		if (c->list_b[0] < c->list_b[1])
			sb(c, 0);
		pa(c, 0);
		pa(c, 0);
	}
	else
	{
		num_3sort(c);
		if (c->list_b[0] < c->list_b[1])
			sb(c, 0);
		pa(c, 0);
		pa(c, 0);
	}
}

void	num_5sort(t_push *c)
{
	int	median_stack;
	int	i;
	int	j;

	i = 0;
	j = 0;
	median_stack = c->new_tab[c->len_ini / 2];
	free(c->new_tab);
	c->new_tab = NULL;
	ft_copy_stack_to_tab(c, 0);
	while (i < c->len_ini)
	{
		if (c->new_tab[i] < median_stack)
			pb(c, 0);
		else
			ra(c, 0);
		i++;
	}
	num_5sort_2(c);
}
