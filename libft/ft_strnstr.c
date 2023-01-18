/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:32:09 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/17 16:53:29 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!tofind[0])
		return ((char *)str);
	while (str[i] && (size_t)i < len)
	{
		if (str[i] == tofind[0])
		{
			j = 0;
			while (tofind[j] != 0 && str[i + j] == tofind[j] && (size_t)(i + j)
					< len)
				j++;
			if (tofind[j] == 0)
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
