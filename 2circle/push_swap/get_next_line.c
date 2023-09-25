/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:01:08 by seunghye          #+#    #+#             */
/*   Updated: 2022/04/20 16:13:03 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static t_gnl_list	*lst;
	t_gnl_list			*fd_lst;
	char				*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		exit(EXIT_FAILURE);
	fd_lst = lst;
	buf = ft_read(&lst, fd, buf, &fd_lst);
	if (buf)
		return (buf);
	if (fd_lst)
	{
		buf = fd_lst->str;
		ft_gnl_lstdelone(&lst, fd);
		if (!*buf)
		{
			free(buf);
			return (0);
		}
		return (buf);
	}
	return (0);
}

char	*ft_strchr(char *str, char c)
{
	while (*str != c && *str)
		str++;
	if (*str == c)
		return (str);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	size_1;
	size_t	size_2;

	if (!s1 || !s2)
		return (0);
	size_1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (size_1 + size_2 + 1));
	if (!str)
		exit(EXIT_FAILURE);
	ft_strlcpy(str, s1, size_1 + 1);
	ft_strlcpy(str + size_1, s2, size_2 + 1);
	return (str);
}
