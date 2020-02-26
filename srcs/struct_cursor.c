/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:21:18 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/26 17:07:53 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_cursor	*ft_cursor_new(size_t id, size_t count_pl)
{
	size_t		i;
	t_cursor	*new;

	if (!(new = (t_cursor *)malloc(sizeof(t_cursor))))
		ft_error("Problem with malloc for carriage", -1);
	new->pid = id;
	new->id = count_pl - id + 1;
	new->carry = 0;
	new->pc = looped((MEM_SIZE / count_pl) * (new->pid - 1), 0);
	new->last_live = 0;
	new->wait = -1;
	if (!(new->registrs = (int *)malloc(sizeof(int) * REG_NUMBER)))
		ft_error("Problem with malloc for registers at the beginning", -1);
	else
	{
		*(new->registrs) = ~(new->pid - 1);
		i = 0;
		while (i++ < REG_NUMBER)
			*(new->registrs + i) = 0;
	}
	new->next = NULL;
	return (new);
}

void		ft_cursor_add(t_cursor **cursor, t_cursor *new)
{
	t_cursor	*temp;

	if (*cursor && new)
	{
		temp = *cursor;
		new->next = temp;
		*cursor = new;
	}
	else if (!(*cursor) && new)
		*cursor = new;
}
