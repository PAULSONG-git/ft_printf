/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 14:30:27 by paul              #+#    #+#             */
/*   Updated: 2021/02/01 15:54:14 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*to_find)
		return ((char *)&str[i]);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && i + j < len)
		{
			j++;
			if (to_find[j] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
