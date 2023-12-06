/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilva-m <csilva-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:57:49 by csilva-m          #+#    #+#             */
/*   Updated: 2023/11/30 12:23:36 by csilva-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../libft/libft.h"

int		g_setexit = 0;

void	handler(int signal)
{
	if (signal == SIGUSR1)
	{
		g_setexit = 1;
		ft_printf("Message received\n");
	}
}

void	send_sig(unsigned char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_setexit = 0;
		if ((c >> i & 1))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i++;
		while (!g_setexit)
			;
	}
}

int	main(int ac, char **av)
{
	char	*msg;

	if (ac == 3)
	{
		msg = av[2];
		ac = ft_atoi(av[1]);
		while (*msg)
		{
			signal(SIGUSR1, handler);
			signal(SIGUSR2, handler);
			send_sig(*msg, ac);
			msg++;
		}
	}
}
