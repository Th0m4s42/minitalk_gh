/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:47:15 by thbasse           #+#    #+#             */
/*   Updated: 2024/09/18 14:47:37 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

#include "libft/includes/libft.h"
#include "libft/includes/ft_printf.h"
#include <signal.h>

typedef struct	s_chars
{
	unsigned char	c;
	struct s_chars	*next;
}				t_chars;

typedef struct	s_target
{
	int				target_pid;
	char			*s;
	unsigned int	s_len;
}				t_target;

////////////////////////////////////////UTILS///////////////////////////////////
void	free_list(t_chars **first_node);
void	add_last(t_chars **first_node, t_chars *current_node);

////////////////////////////////////////SERVER//////////////////////////////////
void	end_of_transmission(t_chars **first_node, t_chars **current_node,
								size_t *sign_count);
t_chars	*init_node(void);
void	last_signal(t_chars **current_node, t_chars **first_node,
						size_t *sign_count, siginfo_t *info);
void	handler(int sign_id, siginfo_t *info, void *ucontext);

////////////////////////////////////////CLIENT//////////////////////////////////
t_target	*get_msg(t_target *new_msg);
void		free_exit(t_target *target, const char *msg);
void		send_message(int signum);

#endif /** MINITALK_H */