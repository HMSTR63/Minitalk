/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmstrx <hmstrx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 00:59:16 by sojammal          #+#    #+#             */
/*   Updated: 2025/01/10 16:22:15 by hmstrx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_ack(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr_fd(GRN "Message acknowledged.\n" "\e[0m", 1);
}

void	send_signal(int pid, int signal)
{
	if (kill(pid, signal) == -1)
	{
		ft_putstr_fd(RED "Invalid PID. Signal failed.\n" "\e[0m", 2);
		exit(1);
	}
	usleep(600);
}

void	ft_send_signal(int pid, char h)
{
	int	bit;
	int	signal;

	bit = 0;
	while (bit < 8)
	{
		if (h & (1 << bit))
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		send_signal(pid, signal);
		bit++;
	}
}

int	validate_pid(char *pid_str)
{
	int	pid;
	int	i;

	i = 0;
	while (pid_str[i])
	{
		if (pid_str[i] < '0' || pid_str[i] > '9')
		{
			ft_putstr_fd(RED "PID has non-digit chars.\n" "\e[0m", 2);
			return (0);
		}
		i++;
	}
	pid = ft_atoi(pid_str);
	if (pid <= 0)
	{
		ft_putstr_fd(RED "PID must be positive.\n" "\e[0m", 2);
		return (0);
	}
	return (pid);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3 && av[2][0] != '\0')
	{
		pid = validate_pid(av[1]);
		if (pid != 0)
		{
			ft_putstr_fd(GRN "Valid PID.\n" "\e[0m", 1);
			signal(SIGUSR1, handle_ack);
			while (av[2][i])
			{
				ft_send_signal(pid, av[2][i++]);
			}
			ft_send_signal(pid, '\0');
		}
	}
	else
	{
		ft_putstr_fd(RED "Invalid args or empty msg.\n" "\e[0m", 2);
		ft_putstr_fd(PUR "Usage: ./client [PID] [MSG]\n" "\e[0m", 2);
	}
	return (0);
}
