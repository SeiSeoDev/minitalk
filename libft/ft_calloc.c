/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:10:18 by dasanter          #+#    #+#             */
/*   Updated: 2019/11/20 18:04:04 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*retour;
	size_t	i;

	i = 0;
	retour = malloc(nmemb * size);
	if (!(retour))
		return (NULL);
	while (i < nmemb * size)
		retour[i++] = 0;
	return ((void *)retour);
}
