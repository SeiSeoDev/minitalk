/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seiseo <seiseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:58:19 by seiseo            #+#    #+#             */
/*   Updated: 2021/11/20 19:35:47 by seiseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

int	send_ascii(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (--bit > -1)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
	}
	return (0);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	send_message(pid_t pid_server, char *str)
{
	int i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] >= 32 && str[i] <= 126)
			send_ascii(pid_server, str[i]);
		i++;
	}
	i = 0;
	while (i < ft_strlen(str) * 7)
	{
		kill(pid_server, SIGUSR1);
		usleep(1000);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				neg;
	unsigned int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while ((str[i] <= '\r' && str[i] >= '\t') || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - '0';
	return (nb * neg);
}

int			main(int argc, char **argv)
{
	int pid_server;

	if (argc < 3)
	{
		write(1, "./client [pid] [message]\n", 39);
		return (1);
	}
	if ((pid_server = ft_atoi(argv[1])) == 0)
	{
		write(1, "PID INVALIDE.\n", 14);
		return (1);
	}
	send_message(pid_server, argv[2]);
	return (0);
}