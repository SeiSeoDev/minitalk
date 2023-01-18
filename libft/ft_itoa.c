/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:00:46 by dasanter          #+#    #+#             */
/*   Updated: 2019/11/20 17:56:23 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	getsize(int nb)
{
	int	size;

	size = 0;
	if (nb < 0)
	{
		size++;
		nb = nb * -1;
	}
	if (nb == 0)
		size++;
	while (nb)
	{
		size++;
		nb /= 10;
		if (nb == 0)
			return (size++);
	}
	return (size);
}

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*str;
	int				i;

	str = (char *)malloc((getsize(n) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	if (n < 0)
		nb = -n;
	else
		nb = n;
	i = getsize(n);
	str[i] = 0;
	while (i--)
	{
		if (i == 0 && n < 0)
			break ;
		str[i] = nb % 10 + 48;
		nb /= 10;
	}
	return (str);
}
