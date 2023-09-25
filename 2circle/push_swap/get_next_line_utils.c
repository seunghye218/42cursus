/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:01:18 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/20 16:15:31 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*find_n(char **str, char *buf)
{
	size_t	n_len;
	char	*point_n;
	char	*until_n;
	char	*after_n;

	free(buf);
	point_n = ft_strchr(*str, '\n');
	n_len = point_n - *str + 1;
	until_n = (char *)malloc(sizeof(char) * n_len + 1);
	if (!until_n)
		exit(EXIT_FAILURE);
	ft_strlcpy(until_n, *str, n_len + 1);
	after_n = (char *)malloc(sizeof(char) * (ft_strlen(*str) - n_len + 1));
	if (!after_n)
		exit(EXIT_FAILURE);
	ft_strlcpy(after_n, point_n + 1, (ft_strlen(*str) - n_len + 1));
	free(*str);
	*str = after_n;
	return (until_n);
}

char	*ft_read(t_gnl_list **lst, int fd, char *buf, t_gnl_list **fd_lst)
{
	ssize_t	n;

	while (*fd_lst && (*fd_lst)->fd != fd)
		*fd_lst = (*fd_lst)->next;
	if (*fd_lst && ft_strchr((*fd_lst)->str, '\n'))
		return (find_n(&(*fd_lst)->str, buf));
	n = read(fd, buf, BUFFER_SIZE);
	while (n > 0)
	{
		buf[n] = 0;
		*fd_lst = ft_gnl_lstadd(lst, fd, buf);
		if (*fd_lst && ft_strchr((*fd_lst)->str, '\n'))
			return (find_n(&(*fd_lst)->str, buf));
		n = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (0);
}

t_gnl_list	*ft_gnl_lstnew(int fd, char *buf)
{
	t_gnl_list	*new;
	size_t		buf_size;

	new = (t_gnl_list *)malloc(sizeof(t_gnl_list));
	if (!new)
		exit(EXIT_FAILURE);
	new->fd = fd;
	buf_size = ft_strlen(buf) + 1;
	new->str = (char *)malloc(sizeof(char) * (buf_size));
	if (!new->str)
		exit(EXIT_FAILURE);
	ft_strlcpy(new->str, buf, buf_size);
	new->next = 0;
	return (new);
}

t_gnl_list	*ft_gnl_lstadd(t_gnl_list **lst, int fd, char *buf)
{
	t_gnl_list	*fd_lst;
	char		*tmp;

	fd_lst = *lst;
	while (fd_lst && fd_lst->fd != fd)
		fd_lst = fd_lst->next;
	if (!fd_lst)
	{
		fd_lst = ft_gnl_lstnew(fd, buf);
		if (!fd_lst)
			return (0);
		fd_lst->next = *lst;
		*lst = fd_lst;
	}	
	else
	{
		tmp = ft_strjoin(fd_lst->str, buf);
		free(fd_lst->str);
		fd_lst->str = tmp;
	}
	return (fd_lst);
}

void	ft_gnl_lstdelone(t_gnl_list **lst, int fd)
{
	t_gnl_list	*now;
	t_gnl_list	*next;

	now = *lst;
	next = now->next;
	if (now->fd == fd)
	{
		free(now);
		*lst = next;
		return ;
	}
	while (next && next->fd != fd)
	{
		next = next->next;
		now = now->next;
	}
	if (!next)
		return ;
	now->next = next->next;
	free(next);
}
