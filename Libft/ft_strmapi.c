/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:17:00 by psong             #+#    #+#             */
/*   Updated: 2021/02/01 18:59:10 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
		i++;
	if (!(dst = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	dst[i] = '\0';
	i = 0;
	while (s[i])
	{
		dst[i] = (*f)(i, s[i]);
		i++;
	}
	return (dst);
}
