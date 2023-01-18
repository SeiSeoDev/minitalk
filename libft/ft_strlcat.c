/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:28:57 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/17 16:51:32 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	int	i;
	int	j;
	int	size;

	j = 0;
	i = 0;
	if ((size_t)ft_strlen(dst) > dsize)
		return (ft_strlen(src) + dsize);
	i = ft_strlen(dst);
	size = i;
	while (src[j] && (size_t)i < dsize - 1)
		dst[i++] = src[j++];
	dst[i] = 0;
	return (size + ft_strlen(src));
}
