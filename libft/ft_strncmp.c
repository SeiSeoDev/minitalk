/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:22:48 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/17 16:53:16 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *f, const char *s, size_t length)
{
	int	i;

	i = 0;
	while (f[i] && s[i] && (size_t)i < length)
	{
		if (f[i] != s[i])
			return ((unsigned char)f[i] - (unsigned char)s[i]);
		i++;
	}
	if ((!f[i] && !s[i]) || (size_t)i >= length)
		return (0);
	else
		return ((unsigned char)f[i] - (unsigned char)s[i]);
}
