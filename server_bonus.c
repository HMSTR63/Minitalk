/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojammal <sojammal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 00:51:07 by sojammal          #+#    #+#             */
/*   Updated: 2025/01/22 17:33:08 by sojammal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset_static_vars(int *pid, int *p_bit, char *h, int *buffer_index)
{
	*pid = 0;
	*p_bit = 0;
	*h = 0;
	*buffer_index = 0;
}

void	print_buffer_and_ack(char *buffer, int *buffer_index, int pid)
{
	int	i;

	i = 0;
	while (i < *buffer_index)
	{
		ft_putchar_fd(buffer[i], 1);
		i++;
	}
	if (buffer[*buffer_index - 1] == '\0')
	{
		kill(pid, SIGUSR1);
	}
	*buffer_index = 0;
}

void	ft_btoa(int sig, siginfo_t *info, void *context)
{
	static int	pid = 0;
	static int	p_bit = 0;
	static char	h = 0;
	static char	buffer[4] = {0};
	static int	buffer_index = 0;

	(void)context;
	if (pid != info->si_pid)
		reset_static_vars(&pid, &p_bit, &h, &buffer_index);
	pid = info->si_pid;
	if (sig == SIGUSR1)
		h |= (1 << p_bit);
	p_bit++;
	if (p_bit == 8)
	{
		buffer[buffer_index++] = h;
		h = 0;
		p_bit = 0;
		if (buffer_index == 4 || buffer[buffer_index - 1] == '\0')
			print_buffer_and_ack(buffer, &buffer_index, pid);
	}
}

int	main(void)
{
	struct sigaction	sig;
	int					pid;

	pid = getpid();
	ft_putstr_fd(CY "Server PID: " "\e[0m", 1);
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
