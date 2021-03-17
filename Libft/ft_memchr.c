/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:12:06 by psong             #+#    #+#             */
/*   Updated: 2021/01/27 16:31:01 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return ((void *)&src[i]);
		i++;
	}
	return (NULL);
}
