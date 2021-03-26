/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paul <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:11:03 by paul              #+#    #+#             */
/*   Updated: 2021/03/26 15:10:56 by psong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					c_print_by_info(t_info *info, va_list ap)
{
	info->chr = va_arg(ap, int);
	if (info->width > 0)
		info->fill_blank = (info->width - 1);
	if (info->minus == 0)
		print_blank(0, info->fill_blank);
	if ((info->fill_prec = info->prec - 1) > 0)
		print_blank(1, info->fill_prec);
	ft_putchar(info->chr, 1);
	if (info->minus == 1)
		print_blank(0, info->fill_blank);
	info->total = info->fill_blank + 1;
	return (info->total);
}

void				s_print_by_info2(t_info *info, va_list ap)
{
	info->str = va_arg(ap, char *);
	info->str_cnt = ft_strlen(info->str);
	if (info->str == NULL)
	{
		info->str = ft_strdup("(null)");
		info->str_cnt = 6;
	}
	else
		info->str = ft_strdup(info->str);
}

int					s_print_by_info(t_info *info, va_list ap)
{
	s_print_by_info2(info, ap);
	if (info->prec < info->str_cnt && info->dot)
	{
		info->str[info->prec] = '\0';
		info->str_cnt = info->prec;
	}
	if (info->width <= info->str_cnt)
		ft_putstr(info->str, 1);
	else if (info->width > info->str_cnt)
	{
		info->fill_blank = (info->width - info->str_cnt);
		if (info->minus == 0)
			print_blank(info->zero, info->fill_blank);
		ft_putstr(info->str, 1);
		if (info->minus == 1)
			print_blank(0, info->fill_blank);
	}
	return (info->fill_blank + info->str_cnt);
}

int					p_print_by_info(t_info *info, va_list ap)
{
	int				total;

	total = 0;
	info->p = va_arg(ap, long long);
	if ((info->total = ft_putnbr_count(info->p, LOWER)) == 0 && info->dot == 0)
		info->total = 1;
	info->fill_blank = info->width - 2 - info->total;
	if (info->minus == 0)
		total += print_blank(info->zero, info->fill_blank);
	ft_putstr("0x", 1);
	if ((info->fill_prec = info->prec - info->total) > 0)
		total += print_blank(1, info->fill_prec);
	if (info->p == 0 && info->dot == 0)
		ft_putchar('0', 1);
	else
		ft_putnbr_base(info->p, LOWER);
	if (info->minus == 1)
		total += print_blank(0, info->fill_blank);
	total = 2 + total + info->total;
	return (total);
}

int					pc_print_by_info(t_info *info)
{
	if (info->zero && info->minus)
		info->zero = 0;
	if (info->width > 0)
		info->fill_blank = (info->width - 1);
	if (info->minus == 0)
		print_blank(info->zero, info->fill_blank);
	ft_putchar('%', 1);
	if (info->minus == 1)
		print_blank(info->zero, info->fill_blank);
	info->total = info->fill_blank + 1;
	return (info->total);
}
