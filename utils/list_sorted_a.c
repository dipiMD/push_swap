/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sorted_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:27:51 by drakan            #+#    #+#             */
/*   Updated: 2022/01/19 21:06:01 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_push *c, int cheker)
{
	int	tmp;

	tmp = c->list_a[0];
	c->list_a[0] = c->list_a[1];
	c->list_a[1] = tmp;
	if (cheker == 0)
		ft_putstr_fd("sa\n", 1);
}

void	ra(t_push *c, int cheker)
{
	int		tmp;
	int		i;

	i = 0;
	tmp = c->list_a[0];
	while (i < c->len - 1)
	{
		c->list_a[i] = c->list_a[i + 1];
		i++;
	}
	c->list_a[i] = tmp;
	c->list_a[++i] = '\0';
	if (cheker == 0)
		ft_putstr_fd("ra\n", 1);
}

void	rra(t_push *c, int cheker)
{
	int		*list;
	int		j;
	int		i;

	j = 1;
	list = malloc(sizeof(int) * (c->len + 1));
	list[0] = c->list_a[c->len - 1];
	i = 0;
	while (i < c->len - 1)
	{
		list[j] = c->list_a[i];
		j++;
		i++;
	}
	list[j] = '\0';
	i = -1;
	while (++i < c->len)
		c->list_a[i] = list[i];
	c->list_a[i] = '\0';
	free(list);
	list = NULL;
	if (cheker == 0)
		ft_putstr_fd("rra\n", 1);
}

void	pa(t_push *c, int cheker)
{
	int	i;

	i = 0;
	c->len++;
	c->len_b--;
	c->pb--;
	i = 0;
	while (i < c->len - 1)
	{
		c->list_a[i + 1] = c->list_a[i];
		i++;
	}
	c->list_a[0] = c->list_b[0];
	c->list_a[c->len] = '\0';
	i = 0;
	while (i < c->len_b)
	{
		c->list_b[i] = c->list_b[i + 1];
		i++;
	}
	c->list_b[i] = '\0';
	if (cheker == 0)
		ft_putstr_fd("pa\n", 1);
}
