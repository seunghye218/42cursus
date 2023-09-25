/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:36:43 by kimseungh         #+#    #+#             */
/*   Updated: 2022/04/20 16:18:12 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				n;
	struct s_list	*next;
}	t_list;

typedef struct s_tree
{
	int				n;
	struct s_tree	*l;
	struct s_tree	*r;
}	t_tree;

size_t		ft_strlen(const char *str);
int			ft_isdigit(int c);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
char		**ft_split(char const *s, char c);
t_list		*ft_lstnew(int n);
int			ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
long long	ft_atol(const char *str);
t_tree		*tree_new(int n);
void		tree_insert(t_tree *node, int n);
void		tree_clear(t_tree *node);
void		s_logic(t_list **a, char c);
void		ss(t_list **a, t_list **b, char c);
void		p_logic(t_list **a, t_list **b, char c);
void		r_logic(t_list **a, char c);
void		rr(t_list **a, t_list **b, char c);
void		rr_logic(t_list **a, char c);
void		rrr(t_list **a, t_list **b, char c);
int			*get_arr(t_list *lst);
void		sort_arr(int *arr, int left, int right);
int			*get_sort_arr(t_list *lst);
void		trans_to_index(t_list *a);
void		under_six(t_list **a, t_list **b, int len);
void		three_elem(t_list **lst, char c);
void		insert_elem(t_list **a, t_list **b, int len);
void		exception(t_list **a);
void		four_elem(t_list **a, t_list **b);
void		five_elem(t_list **a, t_list **b);
void		greedy_sort(t_list **a, t_list **b, int len);
void		push_b(t_list **a, t_list **b, int len);
void		push_a(t_list **a, t_list **b, int len);
int			get_chunk(int len);
void		ft_exit(void);
void		check_dup(t_list *lst);
int			check_sort(t_list *a, int len);
t_list		*parsing(int ac, char **av, int i);

# define BUFFER_SIZE 8

typedef struct s_gnl_list
{
	int					fd;
	char				*str;
	struct s_gnl_list	*next;
}	t_gnl_list;

int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strchr(char *str, char c);
char		*ft_strjoin(char *s1, char *s2);
t_gnl_list	*ft_gnl_lstnew(int fd, char *buf);
t_gnl_list	*ft_gnl_lstadd(t_gnl_list **lst, int fd, char *buf);
void		ft_gnl_lstdelone(t_gnl_list **lst, int fd);
char		*ft_read(t_gnl_list **lst, int fd, char *buf, t_gnl_list **fd_lst);
char		*find_n(char **str, char *buf);
char		*get_next_line(int fd);
#endif
