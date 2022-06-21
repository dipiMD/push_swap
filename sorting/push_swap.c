/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:52:28 by drakan            #+#    #+#             */
/*   Updated: 2022/01/19 21:02:23 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_swap(t_push *c)
{
	if (c->len == 2 && c->list_a[0] > c->list_a[1])
		sa(c, 0);
	else if (c->len == 3)
		num_3sort(c);
	else if (c->len > 3 && c->len <= 5)
		num_5sort(c);
	else if (c->len > 5 && c->len <= 500)
	{
		if (c->len <= 100)
			big_sort(c, 5, c->len / 5);
		else if (c->len > 100 && c->len <= 500)
			big_sort(c, 13, c->len / 13);
	}
}

int	main(int ac, char **av)
{
	t_push	c;

	if (ac > 1)
	{
		ft_get_corr_args(&c, av);
		c.list_a = malloc(sizeof(int) * (c.len_ini + 1));
		c.list_b = malloc(sizeof(int) * (c.len_ini + 1));
		ft_copy_args_to_stack(&c);
		c.len = c.len_ini;
		c.len_b = 0;
		c.pb = 0;
		ft_copy_stack_to_tab(&c, 0);
		ft_sort_table(&c);
		if ((ft_check_error(&c)) == -1)
			write (2, "Error\n", 6);
		if (ft_check_error(&c) == -1 || c.len_ini <= 1)
		{
			ft_free_all(&c, 0);
			exit(0);
		}
		ft_push_swap(&c);
		ft_free_all(&c, 0);
	}
	return (0);
}
