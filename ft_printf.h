/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:08:49 by psong             #+#    #+#             */
/*   Updated: 2021/03/10 17:39:32 by paul             ###   ########.fr       */
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
}				t_info;

int		ft_printf(const char *format, ...);
int		read_format(va_list ap, char *format);
void	info_init(t_info *info);
void 	fill_info(va_list ap, t_info *info, char *format, int i);
int		print_by_type(va_list ap, t_info *info, int i, char *format);
int		print_by_info(t_info *info, va_list ap);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putchar_fd(char c, int fd);
int		print_blank(t_info *info, int zero_flag, int count);
void	positional_nb(t_info *info);

#endif
