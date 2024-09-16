/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:38:29 by thbasse           #+#    #+#             */
/*   Updated: 2024/09/14 12:23:38 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

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

#endif /** MINITALK_H */