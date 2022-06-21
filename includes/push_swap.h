/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drakan <drakan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:20:33 by drakan            #+#    #+#             */
/*   Updated: 2022/01/19 21:08:00 by drakan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFFER_SIZE 100

typedef struct s_push
{
	int			*list_a;
	int			*list_b;
	char		**new_av;
	int			*new_tab;
	int			len_b;
	int			len;
	int			len_ini;
	int			pb;
}				t_push;

int		get_next_line(const int fd, char **line);
int		ft_check_nul(t_push *c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_check_sort(t_push *c);
int		ft_atoi(const char *str, t_push *c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	ft_putstr_fd(char *s, int fd);
int		ft_get_len_ini(char **av);
char	*ft_strchr(const char *s, int c);
char	**ft_split(const char *s, char c);
void	ft_copy_args_to_stack(t_push *c);
void	ft_free_all(t_push *c, int before);
int		ft_check_error(t_push *c);
void	ft_push(t_push *c);
char	*ft_strtrim(char *s1, char set);
void	ft_get_corr_args(t_push *c, char **av);
void	ft_copy_stack_to_tab(t_push *c, int checker);
void	ft_sort_table(t_push *c);
int		ft_get_case(t_push *c);
void	num_3sort(t_push *c);
void	num_5sort(t_push *c);
void	big_sort(t_push *c, int nbr_chunk, int chunk_size);
void	push_a_to_b(t_push *c, int chunk_size);
void	sa(t_push *c, int cheker);
void	ra(t_push *c, int cheker);
void	rra(t_push *c, int cheker);
void	pa(t_push *c, int cheker);
void	pb(t_push *c, int checker);
void	sb(t_push *c, int cheker);
void	rb(t_push *c, int cheker);
void	rrb(t_push *c, int cheker);

#endif
