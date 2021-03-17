/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:48:31 by psong             #+#    #+#             */
/*   Updated: 2021/03/16 14:57:19 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	int a = 0;
	int b = 0;
	long long c1 = 0x93b1402710;
	void *c2 = (void *)c1;
	a = ft_printf("%-16.p\n", c1);
	b = printf("%-16.p\n", c2);
	printf("%d\n", a);
	printf("%d\n", b);

	return (0);
}
