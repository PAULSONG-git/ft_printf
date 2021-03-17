/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:12:52 by psong             #+#    #+#             */
/*   Updated: 2021/01/26 17:25:46 by psong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last_pos;
	int		i;

	i = 0;
	last_pos = 0;
	while (str[i])
	{
		if (str[i] == c)
			last_pos = (char *)&str[i];
		i++;
	}
	if (last_pos)
		return (last_pos);
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
