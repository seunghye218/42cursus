/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghye <seunghye@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:05:01 by seunghye          #+#    #+#             */
/*   Updated: 2021/12/06 18:18:49 by seunghye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size_1;
	size_t	size_2;

	if (!s1 || !s2)
		return (0);
	size_1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	if (!(size_1 + size_2))
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (size_1 + size_2 + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, size_1 + 1);
	ft_strlcat(str, s2, size_1 + size_2 + 1);
	return (str);
}
