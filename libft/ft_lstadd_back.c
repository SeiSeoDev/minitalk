/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:36:05 by dasanter          #+#    #+#             */
/*   Updated: 2019/11/21 15:51:21 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	if (new && alst)
	{
		if ((*alst) == NULL)
		{
			*alst = new;
			return ;
		}
		while ((tmp)->next)
			(tmp) = (tmp)->next;
		(tmp)->next = new;
		new->next = NULL;
	}
}
