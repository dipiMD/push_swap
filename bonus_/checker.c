/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 01:45:33 by drakan            #+#    #+#             */
/*   Updated: 2022/01/19 21:08:11 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_push_more(t_push *c, char *arg)
{
	if (ft_strcmp(arg, "ra") == 0)
		ra(c, 1);
	else if (ft_strcmp(arg, "rb") == 0)
		rb(c, 1);
	else if (ft_strcmp(arg, "rr") == 0)
	{
		ra(c, 1);
		rb(c, 1);
	}
	else if (ft_strcmp(arg, "rra") == 0)
		rra(c, 1);
	else if (ft_strcmp(arg, "rrb") == 0)
		rrb(c, 1);
	else if (ft_strcmp(arg, "rrr") == 0)
	{
		rra(c, 1);
		rrb(c, 1);
	}
}

void	ft_sort_push(t_push *c, char *arg)
{
	if (ft_strcmp(arg, "sa") == 0)
		sa(c, 1);
	else if (ft_strcmp(arg, "sb") == 0)
		sb(c, 1);
	else if (ft_strcmp(arg, "ss") == 0)
	{
		sa(c, 1);
		sb(c, 1);
	}
	else if (ft_strcmp(arg, "pa") == 0)
		pa(c, 1);
	else if (ft_strcmp(arg, "pb") == 0)
		pb(c, 1);
	else
		ft_sort_push_more(c, arg);
}

int	check_command(char *command)
{
	if (ft_strcmp(command, "sa") != 0 && ft_strcmp(command, "sb") != 0
		&& ft_strcmp(command, "ra") != 0 && ft_strcmp(command, "rb") != 0
		&& ft_strcmp(command, "pa") != 0 && ft_strcmp(command, "pb") != 0
		&& ft_strcmp(command, "rra") != 0 && ft_strcmp(command, "rrb") != 0
		&& ft_strcmp(command, "rr") != 0 && ft_strcmp(command, "rrr") != 0
		&& ft_strcmp(command, "ss") != 0)
		return (-1);
	return (1);
}

void	ft_push(t_push *c)
{
	char	*arg;

	arg = NULL;
	while (get_next_line(0, &arg))
	{
		if (check_command(arg) == -1)
		{
			write (2, "Error\n", 6);
			free(arg);
			exit(0);
		}
		ft_sort_push(c, arg);
		free(arg);
	}
	if (ft_check_sort(c) == 0 || c->len_b)
		ft_putstr_fd("KO\n", 1);
	else if (ft_check_sort(c) == 1)
		ft_putstr_fd("OK\n", 1);
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
		ft_copy_stack_to_tab(&c, 1);
		ft_sort_table(&c);
		if ((ft_check_error(&c)) == -1)
			write (2, "Error\n", 6);
		if (ft_check_error(&c) == -1 || c.len_ini <= 1)
		{
			ft_free_all(&c, 0);
			exit(0);
		}
		ft_push(&c);
		ft_free_all(&c, 0);
	}
	return (0);
}
