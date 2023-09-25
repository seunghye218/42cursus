/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <seungpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:51:34 by seungpar          #+#    #+#             */
/*   Updated: 2021/12/01 15:54:37 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ret;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ret = (char *)malloc(i + j + 1);
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	ft_strlcat(ret, s1, i + j + 1);
	ft_strlcat(ret, s2, i + j + 1);
	return (ret);
}
