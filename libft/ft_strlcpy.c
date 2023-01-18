/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:56:04 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/17 16:52:14 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	int	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dsize == 0)
	{
		while (src[i])
			i++;
		return ((size_t)i);
	}
	while (src[i] && dsize - 1 > (size_t)i)
	{
		dst[i] = src[i];
		i++;
	}
	if (dsize > 0)
		dst[i] = 0;
	while (src[i])
		i++;
	return ((size_t)i);
}
