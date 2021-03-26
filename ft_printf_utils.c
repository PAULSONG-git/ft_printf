/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:09:30 by psong             #+#    #+#             */
/*   Updated: 2021/03/26 15:09:45 by psong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				info_init(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->dot = 0;
	info->prec = 0;
	info->nbr = 0;
	info->posi_nb = 0;
	info->fill_blank = 0;
	info->fill_prec = 0;
	info->str = 0;
	info->str_cnt = 0;
	info->chr = 0;
	info->total = 0;
	info->negative = 0;
	info->p = 0;
	info->unsgnd_nbr = 0;
}

int					ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int					ft_putstr(char *s, int fd)
{
	int				i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		write(fd, &s[i++], 1);
	return (i);
}

int					print_blank(int zero_flag, int count)
{
	int				i;
	char			c;

	c = ' ';
	if (zero_flag)
		c = '0';
	i = 0;
	while (i < count)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

void				option_init(t_info *info)
{
	if (info->zero && info->minus)
		info->zero = 0;
	if (info->zero && info->dot)
		info->zero = 0;
	if (info->width > info->prec)
	{
		if (info->prec > info->posi_nb)
		{
			info->fill_blank = (info->width - info->prec);
			info->fill_prec = (info->prec - info->posi_nb);
		}
		else if (info->prec <= info->posi_nb)
		{
			info->fill_blank = info->width - info->posi_nb;
			info->fill_prec = 0;
		}
	}
	else if (info->width <= info->prec)
	{
		info->fill_blank = 0;
		if ((info->fill_prec = info->prec - info->posi_nb) < 0)
			info->fill_prec = 0;
	}
}
