/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:11:12 by paul              #+#    #+#             */
/*   Updated: 2021/03/26 15:16:34 by psong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_check_base(char *base)
{
	int				i;
	int				j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void				ft_putnbr_base(long long nbr, char *base)
{
	long long		nbr_l;
	char			nbr_c[32];
	long long		base_divider;
	long long		i;

	if (!ft_check_base(base))
		return ;
	base_divider = ft_strlen(base);
	if (nbr < 0)
	{
		nbr_l = nbr;
		nbr_l = -nbr_l;
		ft_putchar('-', 1);
	}
	else
		nbr_l = nbr;
	i = 0;
	while (nbr_l > 0)
	{
		nbr_c[i] = base[nbr_l % base_divider];
		nbr_l /= base_divider;
		i++;
	}
	while (--i >= 0)
		ft_putchar(nbr_c[i], 1);
}

int					ft_putnbr_count(long long nbr, char *base)
{
	long long		nbr_l;
	char			nbr_c[32];
	long long		base_divider;
	long long		i;

	base_divider = ft_strlen(base);
	if (nbr < 0)
	{
		nbr_l = nbr;
		nbr_l = -nbr_l;
		ft_putchar('-', 1);
	}
	else
		nbr_l = nbr;
	i = 0;
	while (nbr_l > 0)
	{
		nbr_c[i] = base[nbr_l % base_divider];
		nbr_l /= base_divider;
		i++;
	}
	return (i);
}

void				positional_nb(t_info *info)
{
	int				i;
	int				tmp;

	i = 0;
	tmp = info->nbr;
	if (info->nbr == 0 && info->prec != 0)
		i = 1;
	else if (info->nbr == 0 && info->prec == 0 && info->dot == 0)
		i = 1;
	while (tmp)
	{
		tmp = tmp / 10;
		i++;
	}
	info->posi_nb = i;
}

void				positional_unsgnd_nb(t_info *info)
{
	unsigned int	i;
	unsigned int	tmp;

	i = 0;
	tmp = info->unsgnd_nbr;
	if (info->unsgnd_nbr == 0 && info->prec != 0)
		i = 1;
	else if (info->unsgnd_nbr == 0 && info->prec == 0 && info->dot == 0)
		i = 1;
	while (tmp)
	{
		tmp = tmp / 10;
		i++;
	}
	info->posi_nb = (int)i;
}
