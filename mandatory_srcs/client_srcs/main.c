/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:07:09 by thbasse           #+#    #+#             */
/*   Updated: 2024/09/18 13:13:30 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

t_target	*get_msg(t_target *new_msg)
{
	static t_target	*msg;

	if (new_msg != NULL)
		msg = new_msg;
	return (msg);
}

void	free_exit(t_target *target, const char *msg)
{
	if (msg)
		ft_printf("%s\n", msg);
	if (target)
	{
		free(target->s);
		free(target);
	}
	exit(0);
}

void	send_message(int signum)
{
	static unsigned int		i;
	static int				bits_count;
	static t_target			*target;

	if (target == NULL)
		target = get_msg(NULL);
	if (i > target->s_len)
		free_exit(target, "Message sent successfully");
	if ((*(target->s + i) >> (7 - bits_count)) & 1)
		signum = SIGUSR2;
	else
		signum = SIGUSR1;
	if (bits_count == 7)
	{
		i++;
		bits_count = 0;
	}
	else
	{
		bits_count++;
	}
	kill(target->target_pid, signum);
}

int	main(int argc, char **argv)
{
	t_target	*target;

	if (argc != 3)
	{
		printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	target = malloc(sizeof(t_target));
	if (target == NULL)
		return (1);
	target->target_pid = ft_atoi(argv[1]);
	target->s = ft_strdup(argv[2]);
	target->s_len = ft_strlen(argv[2]);
	get_msg(target);
	signal(SIGUSR1, send_message);
	signal(SIGUSR2, send_message);
	send_message(0);
	while (1)
		pause();
	return (0);
}
