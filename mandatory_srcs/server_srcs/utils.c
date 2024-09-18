/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbasse <thbasse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:29:08 by thbasse           #+#    #+#             */
/*   Updated: 2024/09/18 13:29:50 by thbasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

void	free_list(t_chars **first_node)
{
	t_chars	*tmp;

	while (*first_node != NULL)
	{
		tmp = *first_node;
		*first_node = (*first_node)->next;
		free(tmp);
	}
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
