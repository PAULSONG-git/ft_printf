/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:13:48 by psong             #+#    #+#             */
/*   Updated: 2021/01/22 18:20:05 by psong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		nb;

	nb = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		nb++;
	}
	return (nb);
}
