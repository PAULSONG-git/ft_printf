/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 16:08:49 by psong             #+#    #+#             */
/*   Updated: 2021/03/09 17:39:08 by psong            ###   ########.fr       */
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
	int			posi_nb;
}				t_info;

int		ft_printf(const char *format, ...);
int		read_format(va_list ap, char *format);
void	info_init(t_info *info);
void 	fill_info(t_info *info, char *format, int i);

#endif
