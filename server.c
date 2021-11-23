#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>

// void sig_traitement(int sign)
// {
//     printf("%d\n", sign);
// }
void	sig_traitement(int signo)
{
	static size_t	i;
	static int		bit;
	static char		buf[100];

	if (--bit == -1)
	{
		bit = 6;
		++i;
	}
	buf[i] &= ~(1 << 7);
	if (signo == SIGUSR1)
		buf[i] |= (1 << bit);
	else if (signo == SIGUSR2)
		buf[i] &= ~(1 << bit);
	if (i == 99 || buf[i] == 127)
	
	{
		buf[i] = 0;
		write(STDOUT_FILENO, buf, i + 1);
		i = 0;
		bit = 0;
	}
}

int main()
{

    pid_t test;
    test = (int)getpid();
    printf("%d\n", test);
    while (1)
    {
        if(signal(SIGUSR1,sig_traitement)==SIG_ERR) {
            perror("signal");
            exit(EXIT_FAILURE);
        }
        if(signal(SIGUSR2,sig_traitement)==SIG_ERR) {
            perror("signal");
            exit(EXIT_FAILURE);
        }
    }
}
