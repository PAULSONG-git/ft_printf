/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:09:30 by psong             #+#    #+#             */
/*   Updated: 2021/03/17 15:50:00 by psong            ###   ########.fr       */
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
	info->str = 0;
	info->str_cnt = 0;
	info->chr = 0;
	info->total = 0;
	info->negative = 0;
	info->p = 0;
	info->unsgnd_nbr = 0;
}

int		c_print_by_info(t_info *info, va_list ap)
{
	info->chr = va_arg(ap, int);
	if (info->width > 0)
		info->fill_blank = (info->width - 1);
	if (info->minus == 0)
		print_blank(0, info->fill_blank);
	ft_putchar(info->chr, 1);
	if (info->minus == 1)
		print_blank(0, info->fill_blank);
	info->total = info->fill_blank + 1;
/*
	printf("\n");
	printf("minus : %d\n", info->minus);
	printf("zero : %d\n", info->zero);
	printf("width : %d\n", info->width);
	printf("dot : %d\n", info->dot);
	printf("prec : %d\n", info->prec);
	printf("posi_nb : %d\n", info->posi_nb);
	printf("fill_blank : %d\n", info->fill_blank);
	printf("fill_prec : %d\n", info->fill_prec);
	printf("total : %d\n", info->total);
	printf("\n");
*/
	return (info->total);
}

int		pc_print_by_info(t_info *info)
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
/*
	printf("\n");
	printf("minus : %d\n", info->minus);
	printf("zero : %d\n", info->zero);
	printf("width : %d\n", info->width);
	printf("dot : %d\n", info->dot);
	printf("prec : %d\n", info->prec);
	printf("posi_nb : %d\n", info->posi_nb);
	printf("fill_blank : %d\n", info->fill_blank);
	printf("fill_prec : %d\n", info->fill_prec);
	printf("total : %d\n", info->total);
	printf("\n");
*/
	return (info->total);
}

int		d_print_by_info(t_info *info, va_list ap)
{
	int total;

	total = 0;
	if ((info->nbr = va_arg(ap, int)) < 0)
	{	
		info->negative = 1;
		info->width = info->width - 1;
		info->nbr = info->nbr * -1;
	}
	positional_nb(info);
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
	if (info->negative == 1 && info->zero == 1 && info->fill_blank)
	{
		total += ft_putchar('-', 1);
		info->negative = 0;
	}
	if (info->minus == 0)
		total += print_blank(info->zero, info->fill_blank);
	if (info->negative == 1)
		total += ft_putchar('-', 1);
	if (info->fill_prec)
		total += print_blank(1, info->fill_prec);
	if (!(info->nbr == 0 && info->prec == 0 && info->dot == 1))
		ft_putnbr_fd(info->nbr, 1);
	if (info->minus == 1)
		total += print_blank(0, info->fill_blank);
/*
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
*/
	
	return (total + info->posi_nb);
}

int		u_print_by_info(t_info *info, va_list ap)
{
	int total;

	total = 0;
	info->unsgnd_nbr = va_arg(ap, unsigned int);
	positional_unsgnd_nb(info);
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

int		s_print_by_info(t_info *info, va_list ap)
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

/*	printf("\n");
	printf("minus : %d\n", info->minus);
	printf("zero : %d\n", info->zero);
	printf("width : %d\n", info->width);
	printf("dot : %d\n", info->dot);
	printf("prec : %d\n", info->prec);
	printf("fill_blank : %d\n", info->fill_blank);
	printf("str_cnt : %d\n", info->str_cnt);
	printf("\n");
*/
	return (info->fill_blank + info->str_cnt);
}

int		ft_putnbr_count(long long nbr, char *base)
{
	long long	nbr_l;
	char	nbr_c[32];
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

int		p_print_by_info(t_info *info, va_list ap)
{
	int total;
	
	total = 0;
	info->p = va_arg(ap, long long);
	if (info->p == 0 && info->dot == 1)
		info->fill_blank = info->width -2;
	else if (info->p == 0 && info->dot == 0)
		info->fill_blank = info->width -3;
	else if ((info->total = ft_putnbr_count(info->p, "0123456789abcdef")) > 11)
		info->fill_blank = (info->width - 14);
	else
		info->fill_blank = (info->width - 12);
	if (info->minus == 0)
		total += print_blank(info->zero, info->fill_blank);
	ft_putstr("0x", 1);
	if (info->p == 0 && info->dot == 0)
	{	
		ft_putchar('0', 1);
		total += 1;
	}
	else
		ft_putnbr_base(info->p, "0123456789abcdef");
	if (info->minus == 1)
		total += print_blank(0, info->fill_blank);

	total = total + 2 + info->total;
	return (total);
}

int		x_print_by_info(t_info *info, va_list ap)
{
	int total;
	
	total = 0;
	info->unsgnd_nbr = va_arg(ap, unsigned int);
	if (!(info->posi_nb = ft_putnbr_count(info->unsgnd_nbr, "0123456789abcdef")))
		positional_unsgnd_nb(info);
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
	if (info->minus == 0)
		total += print_blank(info->zero, info->fill_blank);
	if (info->fill_prec)
		total += print_blank(1, info->fill_prec);
	if (!(info->unsgnd_nbr == 0 && info->prec == 0 && info->dot == 1))
	{
		if (info->unsgnd_nbr == 0)
			ft_putchar('0', 1);
		ft_putnbr_base(info->unsgnd_nbr, "0123456789abcdef");
	}
	if (info->minus == 1)
		total += print_blank(0, info->fill_blank);
	return (total + info->posi_nb);
}

int		X_print_by_info(t_info *info, va_list ap)
{
	int total;
	
	total = 0;
	info->unsgnd_nbr = va_arg(ap, unsigned int);
	if (!(info->posi_nb = ft_putnbr_count(info->unsgnd_nbr, "0123456789ABCDEF")))
		positional_unsgnd_nb(info);
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
	if (info->minus == 0)
		total += print_blank(info->zero, info->fill_blank);
	if (info->fill_prec)
		total += print_blank(1, info->fill_prec);
	if (!(info->unsgnd_nbr == 0 && info->prec == 0 && info->dot == 1))
	{
		if (info->unsgnd_nbr == 0)
			ft_putchar('0', 1);
		ft_putnbr_base(info->unsgnd_nbr, "0123456789ABCDEF");
	}
	if (info->minus == 1)
		total += print_blank(0, info->fill_blank);
	return (total + info->posi_nb);
}
	
int		ft_check_base(char *base)
{
	int		i;
	int		j;

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

void	ft_putnbr_base(long long nbr, char *base)
{
	long long	nbr_l;
	char	nbr_c[32];
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

int		ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	nbr;

	if (nb < 0)
	{
		ft_putchar('-', fd);
		nbr = (nb * -1);
	}
	else
		nbr = nb;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar((char)(nbr % 10 + '0'), fd);
}

void	ft_putnbr_b(unsigned int nb)
{
	if (nb >= 10)
		ft_putnbr_b(nb / 10);
	ft_putchar((char)(nb % 10 + '0'), 1);
}

int		print_blank(int zero_flag, int count)
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

void		positional_unsgnd_nb(t_info *info)
{
	unsigned int i;
	unsigned int tmp;

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

void		positional_nb(t_info *info)
{
	int i;
	int tmp;

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

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;
	int		tmp;

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

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

int		ft_putstr(char *s, int fd)
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		write(fd, &s[i++], 1);
	return (i);
}
