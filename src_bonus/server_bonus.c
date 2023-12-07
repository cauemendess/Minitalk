/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:02:49 by csilva-m          #+#    #+#             */
/*   Updated: 2023/12/07 15:52:13 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>

void	recive_signal(int sig, siginfo_t *info, void *context)
{
	static char	cur = 0;
	static int	bit = 0;

	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		cur += 0 << bit;
	else if (sig == SIGUSR2)
		cur += 1 << bit;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", cur);
		bit = 0;
		cur = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = recive_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("PID: %d \n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	ft_printf("\n");
	return (0);
}
