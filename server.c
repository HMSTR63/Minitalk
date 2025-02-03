/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:27:33 by sojammal          #+#    #+#             */
/*   Updated: 2025/01/22 17:43:09 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_btoa(int sig, siginfo_t *info, void *context)
{
	static int	pid;
	static int	p_bit;
	static char	h;

	(void)context;
	if (pid != info->si_pid)
	{
		pid = info->si_pid;
		p_bit = 0;
		h = 0;
	}
	if (sig == SIGUSR1)
		h |= (1 << p_bit);
	p_bit++;
	if (p_bit == 8)
	{
		ft_putchar_fd(h, 1);
		h = 0;
		p_bit = 0;
		pid = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;
	int					pid;

	pid = getpid();
	ft_putstr_fd(CY "Server PID: \e[0m", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n" GRN "Waiting...\n" "\e[0m", 1);
	sig.sa_sigaction = ft_btoa;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
