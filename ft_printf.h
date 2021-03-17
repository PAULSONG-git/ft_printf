/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:08:49 by psong             #+#    #+#             */
/*   Updated: 2021/03/17 14:41:54 by psong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_info
{
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			prec;
	int			nbr;;
	int			posi_nb;
	int			fill_blank;
	int			fill_prec;
	char		*str;
	char		chr;
	int			str_cnt;
	int			total;
	int			negative;
	long long	p;
	unsigned int	unsgnd_nbr;
}				t_info;

int		ft_printf(const char *format, ...);
int		read_format(va_list ap, char *format);
void	info_init(t_info *info);
void 	fill_info(va_list ap, t_info *info, char *format, int i);
int		print_by_type(va_list ap, t_info *info, int i, char *format);
int		c_print_by_info(t_info *info, va_list ap);
int		d_print_by_info(t_info *info, va_list ap);
int		u_print_by_info(t_info *info, va_list ap);
int		s_print_by_info(t_info *info, va_list ap);
int		x_print_by_info(t_info *info, va_list ap);
int		X_print_by_info(t_info *info, va_list ap);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putnbr_b(unsigned int nb);
int		ft_putchar(char c, int fd);
int		print_blank(int zero_flag, int count);
void	positional_nb(t_info *info);
void	positional_unsgnd_nb(t_info *info);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
int		ft_putstr(char *s, int fd);
void	ft_putnbr_base(long long nbr, char *base);
int		ft_putnbr_count(long long nbr, char *base);
int		ft_check_base(char *base);
int		p_print_by_info(t_info *info, va_list ap);
#endif
