/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 16:58:19 by seiseo            #+#    #+#             */
/*   Updated: 2022/01/12 10:02:10 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_check;

void	error(void)
{
	write(1, "Error PID\n", 10);
	exit(EXIT_FAILURE);
}

void	send_char(unsigned char byte, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (g_check)
		{
			g_check = 0;
			if (byte & (1 << i))
			{
				if (kill(pid, SIGUSR1) < 0)
					error();
			}
			else
			{
				if (kill(pid, SIGUSR2) < 0)
					error();
			}
			i--;
		}
	}
}

void	sig_traitement(int signo)
{
	if (signo == SIGUSR1)
		g_check = 1;
	else
		write(1, "message printed\n", 16);
}

void	send_message(int pid, char *str)
{
	while (*str)
	{
		send_char(*str, pid);
		++str;
	}
	send_char('\0', pid);
}

int	main(int argc, char **argv)
{
	int	pid;

	g_check = 1;
	if (argc < 3 || argc > 3)
	{
		write(1, "./client [pid] [message]\n", 25);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0)
	{
		write(1, "PID INVALIDE.\n", 14);
		return (1);
	}
	signal(SIGUSR1, sig_traitement);
	send_message(pid, argv[2]);
	return (0);
}
