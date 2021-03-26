/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:59:17 by paul              #+#    #+#             */
/*   Updated: 2021/03/26 16:01:50 by psong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					d_print_by_info(t_info *info, va_list ap)
{
	if ((info->nbr = va_arg(ap, int)) < 0)
	{
		info->negative = 1;
		info->width = info->width - 1;
	}
	positional_nb(info);
	option_init(info);
	if (info->negative == 1 && info->zero == 1 && info->fill_blank)
	{
		info->total += ft_putchar('-', 1);
		info->negative = 0;
	}
	if (info->minus == 0)
		info->total += print_blank(info->zero, info->fill_blank);
	if (info->negative == 1)
		info->total += ft_putchar('-', 1);
	if (info->fill_prec)
		info->total += print_blank(1, info->fill_prec);
	if (!(info->nbr == 0 && info->prec == 0 && info->dot == 1))
		ft_putnbr_a(info->nbr, 1);
	if (info->minus == 1)
		info->total += print_blank(0, info->fill_blank);
	return (info->total + info->posi_nb);
}

int					u_print_by_info(t_info *info, va_list ap)
{
	int total;

	total = 0;
	info->unsgnd_nbr = va_arg(ap, unsigned int);
	positional_unsgnd_nb(info);
	option_init(info);
	if (info->minus == 0)
		total += print_blank(info->zero, info->fill_blank);
	if (info->fill_prec)
		total += print_blank(1, info->fill_prec);
	if (!(info->unsgnd_nbr == 0 && info->prec == 0 && info->dot == 1))
		ft_putnbr_b(info->unsgnd_nbr);
	if (info->minus == 1)
		total += print_blank(0, info->fill_blank);
	return (total + info->posi_nb);
}

int					x_print_by_info(t_info *info, va_list ap)
{
	int				total;

	total = 0;
	info->unsgnd_nbr = va_arg(ap, unsigned int);
	if (!(info->posi_nb = ft_putnbr_count(info->unsgnd_nbr, LOWER)))
		positional_unsgnd_nb(info);
	option_init(info);
	if (info->minus == 0)
		total += print_blank(info->zero, info->fill_blank);
	if (info->fill_prec)
		total += print_blank(1, info->fill_prec);
	if (!(info->unsgnd_nbr == 0 && info->prec == 0 && info->dot == 1))
	{
		if (info->unsgnd_nbr == 0)
			ft_putchar('0', 1);
		ft_putnbr_base(info->unsgnd_nbr, LOWER);
	}
	if (info->minus == 1)
		total += print_blank(0, info->fill_blank);
	return (total + info->posi_nb);
}

int					x2_print_by_info(t_info *info, va_list ap)
{
	int				total;

	total = 0;
	info->unsgnd_nbr = va_arg(ap, unsigned int);
	if (!(info->posi_nb = ft_putnbr_count(info->unsgnd_nbr, UPPER)))
		positional_unsgnd_nb(info);
	option_init(info);
	if (info->minus == 0)
		total += print_blank(info->zero, info->fill_blank);
	if (info->fill_prec)
		total += print_blank(1, info->fill_prec);
	if (!(info->unsgnd_nbr == 0 && info->prec == 0 && info->dot == 1))
	{
		if (info->unsgnd_nbr == 0)
			ft_putchar('0', 1);
		ft_putnbr_base(info->unsgnd_nbr, UPPER);
	}
	if (info->minus == 1)
		total += print_blank(0, info->fill_blank);
	return (total + info->posi_nb);
}
