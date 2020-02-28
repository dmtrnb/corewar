/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_cursor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:21:18 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/28 15:15:16 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_cursor	*ft_cursor_fork(t_cursor *temp, unsigned pc, unsigned id)
{
	unsigned char	i;
	t_cursor		*new;

	if (!(new = (t_cursor *)malloc(sizeof(t_cursor))))
		ft_error("Problem with malloc for carriage", -1);
	new->id = (id & 0x7fffffff) | (temp->id & 0xf8000000);
	new->pc = pc;
	i = 0;
	while (i != REG_NUMBER)
	{
		*(new->registrs + i) = *(temp->registrs + i);
		i++;
	}
	new->last_live = temp->last_live;
	return (new);
}

t_cursor	*ft_cursor_new(size_t id, size_t count_pl)
{
	size_t		i;
	t_cursor	*new;

	if (!(new = (t_cursor *)malloc(sizeof(t_cursor))))
		ft_error("Problem with malloc for carriage", -1);
	new->id = id << 27;
	new->id |= count_pl - id + 1;
	new->pc = looped((MEM_SIZE / count_pl) * (id - 1), 0);
	new->last_live = 0;
	new->wait = -1;
	*(new->registrs) = ~(id - 1);
	i = 0;
	while (i++ < REG_NUMBER)
		*(new->registrs + i) = 0;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void		ft_cursor_add(t_cursor **cursor, t_cursor *new)
{
	if (*cursor && new)
	{
		(*cursor)->prev = new;
		new->next = *cursor;
		*cursor = new;
	}
	else if (!(*cursor) && new)
		*cursor = new;
}

t_cursor	*ft_cursor_del(t_cursor **cursor)
{
	t_cursor	*del;
	t_cursor	*ret;

	if (cursor && *cursor)
	{
		del = *cursor;
		ret = del->next;
		if (del->prev)
			del->next = del->next;
		if (del->next)
			del->next->prev = del->prev;
		free(del);
		del = NULL;
		return (ret);
	}
	return (NULL);
}
