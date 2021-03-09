/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:07:39 by psong             #+#    #+#             */
/*   Updated: 2021/03/09 17:45:42 by psong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_info(t_info *info, char *format, int i)
{
	if (format[i] == '-')
		info->minus = 1;
	else if (format[i] == '0')
		info->zero = 1;
	else if (format[i] == '.')
		info->dot = 1;
	else if ((0 <= format[i] && format[i] <= 9) || format[i] == '*')
		printf("this is digit or *");
}

int		read_format(va_list ap, char *format)
{
	int ret;
	int i;
	t_info *info;

	i = 0;
	ret = 0;
	while (format[i])
	{
		if (!(info = (t_info *)malloc(sizeof(t_info))))
			return (-1);
		info_init(info);
		while (format[i] != '%' && format[i] != '\0')
		{
			write(1, &format[i], 1);
			ret = ret + 1;
			i++;
		}
		if (format[i] == '%')
			i = i + 1;
		while ((format[i] != 'd' &&  format[i] != 's') && format[i])
		{
			fill_info(info, format, i);
			i++;
		}
	}
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
