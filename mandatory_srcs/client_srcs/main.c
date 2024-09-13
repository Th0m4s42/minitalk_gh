/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:07:09 by thbasse           #+#    #+#             */
/*   Updated: 2024/09/13 20:07:05 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"


char	*get_msg(char *new_msg)
{
	static char	*msg;

	if (new_msg != NULL)
		msg = new_msg;
	return (msg);
}

void	send_message(int server_pid)
{
	int		i;
	int		bit;
	char	*message;
	
	i = 0;
	message = get_msg(NULL);
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
		bit--;
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
	get_msg(argv[2]);
	signal(SIGUSR1, send_message);
	signal(SIGUSR2, send_message);
	send_message(server_pid);
	while (1)
		pause();
	return (0);
}
