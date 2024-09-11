/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maja <maja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:01:38 by maja              #+#    #+#             */
/*   Updated: 2024/09/11 14:23:57 by maja             ###   ########.fr       */
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

#endif /** MINITALK_H */