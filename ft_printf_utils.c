/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:09:30 by psong             #+#    #+#             */
/*   Updated: 2021/03/10 17:52:55 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	info_init(t_info *info)
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
}

int		print_by_info(t_info *info, va_list ap)
{
	info->nbr = va_arg(ap, int);
	positional_nb(info);
	if (info->zero && info->minus)
		info->zero = 0;
	if (info->width <= info->posi_nb)
		ft_putnbr_fd(info->nbr, 1);
	else if (info->width > info->posi_nb)
	{
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
			info->fill_prec = info->width - info->posi_nb;
		}
	}
	if (info->minus == 1)
		print_blank(info, info->zero, info->fill_blank);
	if (info->fill_prec)
		print_blank(info, 1, info->fill_prec);
	ft_putnbr_fd(info->nbr, 1);
	if (info->minus == 0)
		print_blank(info, 0, info->fill_blank);
	else if (info->width <= info->prec)
	{
		info->fill_blank = 0;
		info->fill_prec = (info->width - info->posi_nb);
	}

	printf("\n");
	printf("minus : %d\n", info->minus);
	printf("zero : %d\n", info->zero);
	printf("width : %d\n", info->width);
	printf("dot : %d\n", info->dot);
	printf("prec : %d\n", info->prec);
	printf("posi_nb : %d\n", info->posi_nb);
	printf("fill_blank : %d\n", info->fill_blank);
	printf("fill_prec : %d\n", info->fill_prec);
	printf("\n");
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = (nb * -1);
	}
	else
		nbr = nb;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((char)(nbr % 10 + '0'), fd);
}

int		print_blank(t_info *info, int zero_flag, int count)
{
	int i;
	char c;

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

void		positional_nb(t_info *info)
{
	int i;
	int tmp;

	i = 0;
	tmp = info->nbr;
	while (tmp)
	{
		tmp = tmp / 10;
		i++;
	}
	info->posi_nb = i;
}
