/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:34:11 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/17 16:53:40 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	tmp;

	tmp = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			tmp = i;
		i++;
	}
	if (c == 0)
		tmp = i;
	if (tmp != -1)
		return ((char *)&s[tmp]);
	else
		return (NULL);
}
