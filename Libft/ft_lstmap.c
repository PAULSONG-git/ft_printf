/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psong <psong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:26:40 by psong             #+#    #+#             */
/*   Updated: 2021/01/28 19:35:41 by paul             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;

	if (!lst || !f)
		return (NULL);
	if (!((map = ft_lstnew(f(lst->content)))))
	{
		ft_lstclear(&map, del);
		return (NULL);
	}
	map->next = ft_lstmap(lst->next, f, del);
	return (map);
}
