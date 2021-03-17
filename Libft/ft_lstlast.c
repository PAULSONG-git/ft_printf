/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:20:17 by psong             #+#    #+#             */
/*   Updated: 2021/01/31 17:24:44 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lastlst;

	if (lst == NULL)
		return (NULL);
	lastlst = lst;
	while (lastlst->next)
		lastlst = lastlst->next;
	return (lastlst);
}
