/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:07:09 by thbasse           #+#    #+#             */
/*   Updated: 2024/09/13 18:56:39 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"


void	acknowledgement_handler(int signum)
{
	static int	received = 0;
	
	if (signum == SIGUSR1)
	{
		++received;
		ft_printf("Received bits: %d\n", received);
	}
	else if (signum == SIGUSR2)
	{
		ft_printf("Transmission completed!\n");
		exit(0);
	}
}

void	send_message(int server_pid, const char *message)
{
	int i;
	int bit;
	
	i = 0;
	while (message[i] != '\0')
	{
		bit = 7;
		while (bit >= 0)
		{
			if (message[i] >> bit & 1)
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			pause();
			bit--;
		}
		i++;
	}
	bit = 7;
	while (bit >= 0)
	{
		kill(server_pid, SIGUSR1);
		pause();
	}
}

int	main(int argc, char **argv)
{
	int server_pid;

	if (argc != 3)
	{
		printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, acknowledgement_handler);
	signal(SIGUSR2, acknowledgement_handler);
	send_message(server_pid, argv[2]);
	while (1)
		pause();
	return (0);
}
