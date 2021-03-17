/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:48:31 by psong             #+#    #+#             */
/*   Updated: 2021/03/17 14:30:53 by psong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int a = 0;
	int b = 0;
	
	unsigned int c = 0;
	a = ft_printf("%3.*x\n", -4, c);
	b = printf("%3.*x\n", -4, c);
	printf("%d\n", a);
	printf("%d\n", b);

	return (0);
}
