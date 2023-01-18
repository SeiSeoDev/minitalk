/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:39:12 by dasanter          #+#    #+#             */
/*   Updated: 2019/11/20 17:54:24 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*unloved;

	unloved = (unsigned char *)src;
	tmp = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	while (n)
	{
		*tmp++ = *unloved++;
		n--;
	}
	return (dest);
}
