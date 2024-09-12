/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:38:29 by thbasse           #+#    #+#             */
/*   Updated: 2024/09/12 18:54:53 by thbasse          ###   ########.fr       */
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