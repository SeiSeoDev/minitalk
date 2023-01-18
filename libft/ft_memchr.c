/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:13:33 by dasanter          #+#    #+#             */
/*   Updated: 2019/11/21 13:51:53 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	int		i;

	if (n == 0)
		return (NULL);
	i = 0;
	str = (char *)s;
	while (str[i] != c && (size_t)i < n - 1)
		i++;
	if (str[i] == c)
		return (&str[i]);
	return (NULL);
}
