/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:23:08 by drakan            #+#    #+#             */
/*   Updated: 2022/01/19 21:07:47 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_big_nbr(t_push *c)
{
	int	ret;
	int	i;

	i = 0;
	ret = c->list_b[0];
	while (i < c->len_b)
	{
		if (c->list_b[i] > ret)
			ret = c->list_b[i];
		i++;
	}
	return (ret);
}

int	get_big_nbr_pos(t_push *c, int nbr)
{
	int	i;

	i = 0;
	while (i < c->len_b)
	{
		if (c->list_b[i] == nbr)
			return (i);
		i++;
	}
	return (-1);
}

void	last_sort(t_push *c, int pos_num, int midle_stack)
{
	int	big_nbr;
	int	i;
	int	stack_lengt;

	i = 0;
	stack_lengt = c->len_b;
	while (i < stack_lengt)
	{
		midle_stack = c->len_b / 2;
		big_nbr = get_big_nbr(c);
		pos_num = get_big_nbr_pos(c, big_nbr);
		if (pos_num <= midle_stack)
		{
			while (pos_num-- > 0)
				rb(c, 0);
			pa(c, 0);
		}
		else
		{
			while (pos_num++ < c->len_b)
				rrb(c, 0);
			pa(c, 0);
		}
		i++;
	}
}

void	big_sort(t_push *c, int nbr_chunk, int chunk_size)
{
	int	i;
	int	j;
	int	inc;

	j = 0;
	i = 0;
	inc = chunk_size;
	while (i < nbr_chunk)
	{
		while (j < chunk_size)
		{
			push_a_to_b(c, chunk_size);
			j++;
		}
		chunk_size += inc;
		i++;
	}
	while (c->len)
		pb(c, 0);
	last_sort(c, 0, 0);
}
