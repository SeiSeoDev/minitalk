/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:53:16 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/19 16:55:43 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*notmalloc(int start, int end)
{
	char	*ret;

	if ((end - start) <= 0)
	{
		ret = malloc(1);
		ret[0] = 0;
		return (ret);
	}
	else
		return (NULL);
}

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ret;

	if (!str || !set)
		return (NULL);
	if (!str[0])
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen((char *)str);
	while (ft_isset(str[start], set))
		start++;
	if (start >= end)
	{
		ret = ft_substr(str, 0, 0);
		return (ret);
	}
	while (ft_isset(str[end - 1], set))
		end--;
	if ((int)(end - start) < 0)
		return (notmalloc(start, end));
	ret = ft_substr(str, (unsigned int)start, (end - start));
	return (ret);
}
