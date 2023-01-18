/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasanter <dasanter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:57:18 by dasanter          #+#    #+#             */
/*   Updated: 2022/01/12 10:02:49 by dasanter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "stdio.h"

void	clean(char *str)
{
	int	i;

	i = -1;
	while (++i < 255)
		str[i] = 0;
}

void	sig_traitement(int signo, siginfo_t *info, void *context)
{
	static int		i = 0;
	static int		bit = 8;
	static char		buf[256];

	(void)context;
	if (--bit == -1)
	{
		bit = 7;
		++i;
	}
	if (signo == SIGUSR1)
	{
		buf[i] = (buf[i] & ~(1UL << bit)) | (1 << bit);
		printf("1 : %lu\n", 1UL << bit);
	}
	else if (signo == SIGUSR2)
	{
		printf("0 : %lu\n", 1UL << bit);
		buf[i] = (buf[i] & ~(1UL << bit)) | (0 << bit);
	}
	if ((buf[i] == 0 && bit == 0) || (i == 255 && bit == 0))
	{
		write(1, buf, ft_strlen(buf));
		i = -1;
		clean(buf);
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				test;
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	test = (int)getpid();
	ft_putnbr_fd(test, 1);
	write(1, "\n", 1);
	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = sig_traitement;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	while (1)
		pause();
	return (0);
}
