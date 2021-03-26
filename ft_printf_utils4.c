/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:11:18 by paul              #+#    #+#             */
/*   Updated: 2021/03/26 16:01:01 by psong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_putnbr_a(int nb, int fd)
{
	unsigned int		nbr;

	if (nb < 0)
		nbr = (nb * -1);
	else
		nbr = nb;
	if (nbr >= 10)
		ft_putnbr_a(nbr / 10, fd);
	ft_putchar((char)(nbr % 10 + '0'), fd);
}

void				ft_putnbr_b(unsigned int nb)
{
	if (nb >= 10)
		ft_putnbr_b(nb / 10);
	ft_putchar((char)(nb % 10 + '0'), 1);
}

char				*ft_strdup(const char *s1)
{
	char				*dst;
	int					i;
	int					tmp;

	i = 0;
	tmp = 0;
	if (s1)
	{
		while (s1[tmp])
			tmp++;
	}
	if (!(dst = (char *)malloc(sizeof(char) * (tmp + 1))))
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

size_t				ft_strlen(const char *str)
{
	size_t				i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;

	i = 0;
	if (n == 0)
		return (0);
	else
	{
		while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i] && i < n - 1)
			i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
