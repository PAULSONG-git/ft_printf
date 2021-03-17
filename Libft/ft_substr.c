/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:53:50 by psong             #+#    #+#             */
/*   Updated: 2021/02/01 16:23:28 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	size;

	if (s == 0)
		return (NULL);
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	size = ft_strlen(s);
	if (size <= start)
	{
		dst[0] = '\0';
		return (dst);
	}
	ft_strlcpy(dst, s + start, len + 1);
	return (dst);
}
