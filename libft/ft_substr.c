/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iren <iren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 22:53:49 by iren              #+#    #+#             */
/*   Updated: 2021/05/31 20:44:26 by iren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*res;
	size_t	strlen;

	if (str != 0)
	{
		strlen = ft_strlen(str);
		if (start > (unsigned int)strlen)
			start = (unsigned int)strlen;
		if (start + len > strlen)
			len = strlen - start;
		res = malloc(sizeof(char) * (len + 1));
		if (res == NULL)
			return (0);
		ft_memmove(res, &str[start], len);
		res[len] = '\0';
		return (res);
	}
	return (0);
}
