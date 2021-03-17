/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 10:54:33 by psong             #+#    #+#             */
/*   Updated: 2021/02/01 15:45:21 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dst_ptr = (unsigned char *)dst;
	src_ptr = (unsigned char *)src;
	if (dst_ptr > src_ptr)
		while (++i <= len)
			dst_ptr[len - i] = src_ptr[len - i];
	else
		while (i < len)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
	return (dst);
}
