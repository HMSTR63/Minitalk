/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmstrx <hmstrx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 23:22:17 by sojammal          #+#    #+#             */
/*   Updated: 2025/01/10 16:27:18 by hmstrx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_signal(int pid, char h)
{
	int	signal;
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (h & (1 << bit))
			signal = SIGUSR1;
		else
			signal = SIGUSR2;
		if (kill(pid, signal) == -1)
		{
			ft_putstr_fd(RED "Invalid PID. Signal failed.\n" "\e[0m", 2);
			exit(1);
		}
		usleep(100);
		bit++;
	}
}

int	validate_pid(char *pid_str)
{
	int	i;
	int	pid;

	i = 0;
	while (pid_str[i])
	{
		if (!ft_isdigit(pid_str[i]))
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
			ft_putstr_fd(GRN "Valid PID. Sending...\n" "\e[0m", 1);
			while (av[2][i])
			{
				ft_send_signal(pid, av[2][i]);
				i++;
			}
			ft_send_signal(pid, '\0');
		}
	}
	else
	{
		ft_putstr_fd(RED "Invalid args or empty msg.\n" "\e[0m", 2);
		ft_putstr_fd(PUR "Usage: ./client [PID] [MSG]\n" "\e[0m", 2);
	}
}
