/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:45:25 by dasanter          #+#    #+#             */
/*   Updated: 2019/11/20 20:35:45 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*back;
	t_list		*tmp;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	back = new;
	while (lst->next)
	{
		lst = lst->next;
		tmp = new;
		new = ft_lstnew(f(lst->content));
		if (!new)
			ft_lstclear(&back, del);
		tmp->next = new;
	}
	new = ft_lstnew(f(lst->content));
	if (!new)
		ft_lstclear(&back, del);
	new->next = NULL;
	return (back);
}
