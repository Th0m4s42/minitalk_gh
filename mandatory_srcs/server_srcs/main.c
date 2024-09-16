/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:38:40 by thbasse           #+#    #+#             */
/*   Updated: 2024/09/16 20:12:31 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

void free_list(t_chars **first_node)
{
	t_chars *tmp;

	while (*first_node != NULL)
	{
		tmp = *first_node;
		*first_node = (*first_node)->next;
		free(tmp);
	}
}

void	end_of_transmission(t_chars **first_node, t_chars **current_node, size_t *sign_count)
{
	t_chars	*tmp;
	
	*sign_count = 0;
	(*current_node) = NULL;
	while ((*first_node) != NULL)
	{
		tmp = (*first_node)->next;
		ft_printf("%c", (*first_node)->c);
		free(*first_node);
		(*first_node) = tmp;
	}
	ft_printf("\n");
}

void	add_last(t_chars **first_node, t_chars *current_node)
{
	t_chars	*last;

	if (*first_node == NULL)
	{
		*first_node = current_node;
		return ;
	}
	last = (*first_node);
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = current_node;
}

t_chars *init_node(void)
{
	t_chars *new_node;
	
	new_node = (t_chars *)malloc(sizeof(t_chars));
	if (new_node == NULL)
		return (NULL);
	new_node->c = 0;
	new_node->next = NULL;
	return (new_node);
}

void handler(int sign_id, siginfo_t *info, void *ucontext)
{
	static size_t sign_count;
	static t_chars *first_node;
	static t_chars *current_node;
	
	if (sign_count == 0)
	{
		current_node = init_node();
		if (current_node == NULL)
			return ;
	}
	else if (sign_count % 8 == 0)
	{
		add_last(&first_node, current_node);
		current_node = init_node();
		if (current_node == NULL)
			return ;
	}
	if (sign_id == SIGUSR1)
		current_node->c = current_node->c << 1;
	else if (sign_id == SIGUSR2)
		current_node->c = (current_node->c << 1) + 1;
	sign_count++;
	if (sign_id == SIGUSR1 || sign_id == SIGUSR2)
	{
		if (sign_count % 8 == 0 && current_node->c == '\0')
		{
			end_of_transmission(&first_node, &current_node, &sign_count);
			free_list(&first_node);
			free(current_node);
		}
		kill(info->si_pid, SIGUSR1);
		(void)ucontext;
	}
}

int	main(void)
{
	struct sigaction sa;
	ft_bzero(&sa, sizeof(sa));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL))
	{
		ft_putendl_fd("Failed to set up signal handlers", 2);
		return (-1);
	}
	ft_printf("Server PID: %d\n", getpid());
	while(1)
		pause();
	return (0);
}
