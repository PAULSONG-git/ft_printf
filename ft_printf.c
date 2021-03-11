/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:07:39 by psong             #+#    #+#             */
/*   Updated: 2021/03/10 19:16:38 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_by_type(va_list ap, t_info *info, int i, char *format)
{
	char c;
	int total;

	total = 0;
	c = format[i];
    if (c == 'i')
		print_by_info(info, ap);
	else if (c == 'd')
		print_by_info(info, ap);
	return (total);
}

void	fill_info(va_list ap, t_info *info, char *format, int i)
{
	if (format[i] == '-')
		info->minus = 1;
	else if (format[i] == '0' && info->dot == 0)
		info->zero = 1;
	else if (format[i] == '.')
		info->dot = 1;
	else if ('0' <= format[i] && format[i] <= '9')
	{
		if (('0' <= format[i] && format[i] <= '9') && info->dot == 1)
			info->prec = 10 * info->prec + (format[i] - 48);
		else if (('0' <= format[i] && format[i] <= '9') && info->dot == 0)
			info->width = 10 * info->width + (format[i] - 48);
	}	
	else if (format[i] == '*')
	{
		if (info->dot == 0)
		{
			if ((info->width = va_arg(ap, int)) == 0)
				info->zero = 1;
			else if  (info->width < 0)
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
}

int		read_format(va_list ap, char *format)
{
	int ret;
	int i;
	t_info *info;

	i = 0;
	ret = 0;
	if (!(info = (t_info *)malloc(sizeof(t_info))))
		return (-1);
	while (format[i])
	{
		info_init(info);
		while (format[i] != '%' && format[i] != '\0')
		{
			write(1, &format[i], 1);
			ret++;
			i++;
		}
		if (format[i] == '%' && format[i + 1] != '\0')
			i++;
		while ((format[i] != 'd' &&  format[i] != 's') && format[i])
		{
			fill_info(ap, info, format, i);
			i++;
		}
		if (format[i])
		{
			ret = ret + print_by_type(ap, info, i, format);
			i++;
		}
	}
	free(info);
	info = 0;
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	int ret;
	va_list ap;
	
	va_start(ap, format);
	ret = read_format(ap, (char *)format);
	va_end(ap);
	return (ret);
}
