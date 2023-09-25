/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungpar <seungpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 20:17:25 by seungpar          #+#    #+#             */
/*   Updated: 2021/12/05 18:37:04 by seungpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	ret = (char *)malloc(len + 1);
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	if (ft_strlen(s) > start)
		ft_strlcpy(ret, s + start, len + 1);
	return (ret);
}
