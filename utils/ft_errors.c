/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:20:38 by drakan            #+#    #+#             */
/*   Updated: 2022/01/19 21:06:26 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_double(t_push *c)
{
	int		i;

	i = 0;
	while (i < c->len - 1)
	{
		if (c->new_tab[i] == c->new_tab[i + 1])
			return (-1);
		if (c->new_tab[i] == 34 && c->new_tab[i + 1] == 34)
			return (-1);
		i++;
	}
	return (1);
}

int	ft_check_args(t_push *c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (c->new_av[i])
	{
		j = 0;
		while (c->new_av[i][j])
		{
			if ((c->new_av[i][j] == '+' || c->new_av[i][j] == '-')
				&& (c->new_av[i][j + 1] < '0' || c->new_av[i][j + 1] > '9'))
				return (-1);
			if ((c->new_av[i][j] < '0' || c->new_av[i][j] > '9')
				&& (c->new_av[i][j] != '-' && c->new_av[i][j] != '+'))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_error(t_push *c)
{
	if (ft_check_double(c) == -1 || ft_check_args(c) == -1)
		return (-1);
	return (1);
}
