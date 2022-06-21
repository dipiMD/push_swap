/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:08:26 by drakan            #+#    #+#             */
/*   Updated: 2022/01/19 21:02:28 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_words(const char *str, char c)
{
	int	i;
	int	flag;
	int	j;

	j = 0;
	i = 0;
	flag = 0;
	while (str[j])
	{
		if (str[j] != c && flag == 0)
		{
			i++;
			flag = 1;
		}
		else if (str[j] == c)
			flag = 0;
		j++;
	}
	i++;
	return (i);
}

static char	**malloc_error(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
	return (NULL);
}

char	*memory_for_the_word(char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * i + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		h;
	int		count;

	count = 0;
	h = 0;
	if (!s)
		return (NULL);
	count = count_words(s, c);
	split = (char **)malloc(sizeof (split) * count);
	if (split == NULL)
		return (NULL);
	while (*s && h < count - 1)
	{
		while (*s && *s == c)
			s++;
		split[h] = memory_for_the_word((char *)s, c);
		if (split[h++] == NULL)
			malloc_error(split);
		while (*s && *s != c)
			s++;
		s++;
	}
	split[h] = NULL;
	return (split);
}
