/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:07:09 by thbasse           #+#    #+#             */
/*   Updated: 2024/09/12 19:06:25 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

void	acknowledgement_handler(int signum)
{
	(void)signum;
}

void	send_char(int server_pid, char c)
{
	int bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		pause();
		bit--;
	}
}

void	send_message(int server_pid, const char *message)
{
	int i = 0;

	while (message[i] != '\0')
	{
		send_char(server_pid, message[i]);
		i++;
	}
	send_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	int server_pid;

	if (argc != 3)
	{
		printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return 1;
	}
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, acknowledgement_handler);
	send_message(server_pid, argv[2]);
	return 0;
}
