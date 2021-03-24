/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:07:39 by psong             #+#    #+#             */
/*   Updated: 2021/03/24 17:15:08 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_by_type(va_list ap, t_info *info, int i, char *format)
{
	char c;
	int total;

	total = 0;
	c = format[i];
	if (c == 'c')
		total = c_print_by_info(info, ap);
	else if (c == 'd' || c == 'i')
		total = d_print_by_info(info, ap);
	else if (c == 's')
		total = s_print_by_info(info, ap);
	else if (c == 'p')
		total = p_print_by_info(info, ap);
	else if (c == 'u')
		total = u_print_by_info(info, ap);
	else if (c == 'x')
		total = x_print_by_info(info, ap);
	else if (c == 'X')
		total = X_print_by_info(info, ap);
	else if (c == '%')
		total = pc_print_by_info(info);
	return (total);
}

void				fill_info(va_list ap, t_info *info, char *format, int i)
{
	if (format[i] == '-')
		info->minus = 1;
	else if (format[i] == '0' && info->dot == 0 && info->width == 0)
		info->zero = 1;
	else if (format[i] == '.')
		info->dot = 1;
	else if ('0' <= format[i] && format[i] <= '9')
	{
		if (('0' <= format[i] && format[i] <= '9') && info->dot == 1)
			info->prec = 10 * info->prec + (format[i] - 48);
		else if (('0' <= format[i] && format[i] <= '9') && info->dot == 0)
			info->width = 10 * info->width + format[i] - 48;
	}
	else if (format[i] == '*')
		fill_info2(ap, info);
}

void				fill_info2(va_list ap, t_info *info)
{
	if (info->dot == 0)
	{
		if ((info->width = va_arg(ap, int)) == 0)
			info->zero = 1;
		else if (info->width < 0)
		{
			info->minus = 1;
			info->width = info->width * -1;
		}
	}
	else if (info->dot == 1)
	{
		if ((info->prec = va_arg(ap, int)) < 0)
		{
			info->dot = 0;
			info->prec = 0;
		}
	}
}

int				read_format(va_list ap, char *format, int total, int i)
{
	t_info *info;
	if (format[i] == '\0')
		return (0);
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (-1);
	while (format[i])
	{
		info_init(info);
		while (format[i] != '%' && format[i] != '\0')
			total += ft_putchar(format[i++], 1);
		if (format[i] == '%' && format[i + 1] != '\0')
			i++;
		while (!(ft_strchr(TYPE, format[i])) && format[i] != '\0')
		{
			if (format[i] == ' ')
				total += ft_putchar(format[i++], 1);
			fill_info(ap, info, format, i);
			i++;
		}
		if (format[i])
			total += print_by_type(ap, info, i++, format);
	}
	free(info->str);
	free(info);
	return (total);
}

int				ft_printf(const char *format, ...)
{
	int total;
	va_list ap;

	va_start(ap, format);
	total = read_format(ap, (char *)format, 0, 0);
	va_end(ap);
	return (total);
}
