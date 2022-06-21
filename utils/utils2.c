/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:23:32 by drakan            #+#    #+#             */
/*   Updated: 2022/01/19 21:04:43 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putstr_fd(char *str, int fd)
{
	int		i;

	i = 0;
	if (str)
		while (str[i] != '\0')
			write(fd, &str[i++], 1);
}

int	ft_atoi(const char *str, t_push *c)
{
	int		i;
	long	r;

	i = 1;
	r = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r'
		|| *str == '\n' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
		i = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		r = (r * 10) + (*str - '0');
		str++;
	}
	r = r * i;
	if (r > 2147483647 || r < -2147483648)
	{
		ft_putstr_fd("Error\n", 2);
		ft_free_all(c, 1);
		exit(0);
	}
	return (r);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t		i;
	char		*str;
	char		*arr;

	i = 0;
	if (s1 == NULL)
		return (1);
	str = (char *)s1;
	arr = (char *)s2;
	while ((str[i] || arr[i]))
	{
		if (str[i] != '\0' && arr[i] == '\0')
			return (str[i]);
		if (str[i] == '\0' && arr[i] != '\0')
			return (-arr[i]);
		if (str[i] > arr[i])
			return (str[i] - arr[i]);
		if (str[i] < arr[i])
			return (str[i] - arr[i]);
		i++;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
