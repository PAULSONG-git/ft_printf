/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:48:31 by psong             #+#    #+#             */
/*   Updated: 2021/03/09 16:41:49 by psong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int ret;

	ft_printf("option: [0][-][width][.prec] \n");
	ret = ft_printf("Hello \n");
	printf("ret is : %d \n", ret);
	return (0);
}
