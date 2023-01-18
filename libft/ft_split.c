/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:37:10 by dasanter          #+#    #+#             */
/*   Updated: 2021/11/17 16:48:27 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	n_word(const char *str, int n, char sep)
{
	int		i;

	i = 0;
	while (n > -1 && str[i])
	{
		while (str[i] == sep)
			i++;
		if (!(str[i] == sep) && str[i])
		{
			if (n == 0)
				break ;
			else
				n--;
		}
		while (!(str[i] == sep) && str[i])
			i++;
	}
	if (n == -1)
		while ((str[i] == sep) && str[i])
			i++;
	return (i);
}

int	count_word(const char *str, char sep)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while ((str[i] == sep) && str[i])
			i++;
		if (!(str[i] == sep) && str[i])
			count++;
		while (!(str[i] == sep) && str[i])
			i++;
	}
	return (count);
}

int	size_nword(const char *str, char sep, int n)
{
	int	i;
	int	j;

	j = 0;
	i = n_word(str, n, sep);
	while (str[i + j] != sep && str[i + j] != 0)
		j++;
	return (j);
}

void	*gratuit(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i]);
	free(str);
	return (NULL);
}

char	**ft_split(const char *str, char charset)
{
	char	**af_split;
	int		i;
	int		j;

	i = 0;
	af_split = (char **)malloc((1 + count_word(str, charset)) * sizeof(char *));
	while (i < count_word(str, charset))
	{
		af_split[i] = malloc((1 + size_nword(str, charset, i)) * sizeof(char));
		if (!af_split[i])
			return (gratuit(af_split));
		i++;
	}
	af_split[i--] = NULL;
	while (i >= 0)
	{
		j = -1;
		while (++j < size_nword(str, charset, i))
			af_split[i][j] = str[n_word(str, i, charset) + j];
		af_split[i][j] = '\0';
		i--;
	}
	return (af_split);
}
