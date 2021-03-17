/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 15:02:52 by psong             #+#    #+#             */
/*   Updated: 2021/02/01 17:55:44 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	int		i;
	int		tmp;
	char	*s;

	i = 1;
	if (n < 0)
		i++;
	tmp = n;
	while (tmp /= 10)
		i++;
	if (!(s = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	if (n < 0)
		s[0] = '-';
	if (n == 0)
		s[0] = '0';
	while (--i >= 0 && n != 0)
	{
		s[i] = ((n > 0) ? 1 : -1) * (n % 10) + '0';
		n = n / 10;
	}
	return (s);
}
