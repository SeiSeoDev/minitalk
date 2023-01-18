/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:28:56 by dasanter          #+#    #+#             */
/*   Updated: 2021/12/06 15:01:30 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	j;

	if (!s)
		return (NULL);
	j = 0;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	while (j < len && s[start])
	{
		new[j] = s[start];
		start++;
		j++;
	}
	if (start > (unsigned int)ft_strlen(s))
		new[0] = 0;
	new[j] = 0;
	return (new);
}
