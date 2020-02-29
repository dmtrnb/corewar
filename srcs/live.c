/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:09:30 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/29 20:19:06 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char	player_exists(t_name *name, int num)
{
	int		id;
	t_name	*temp;

	id = 0;
	temp = name;
	while (temp)
	{
		id++;
		if (id == num)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void		live(t_crwr *crwr, t_cursor *temp)
{
	int		num;

	temp->last_live = crwr->arena->cycles;
    printf("LIVE: %u id: %u\n", temp->last_live, temp->id & 0x7ffffff);
	num = ~get_direct(crwr->arena->field, looped(temp->pc, 1), 1) + 1;
	if (player_exists(crwr->name, num))
	{
		crwr->arena->alive = num;
		crwr->arena->nbr_live++;
	}
}
/*
	int		attrs;
		if (crwr->visu)
		{
			*((unsigned char *)crwr->arena->par_field + temp->pc) &= 0x1f;
			*((unsigned char *)crwr->arena->par_field + temp->pc) |= 0x40;
			attrs = get_arena_attr(*((unsigned char *)crwr->arena->par_field + temp->pc));
			attrset(attrs);
//			attrset(COLOR_PAIR(MAX_PLAYERS + (~num + 1)));
			mvprintw(temp->pc / COLUMNS + 2, (temp->pc % COLUMNS) * 3 + 3, "%02x", *((unsigned char *)crwr->arena->field + temp->pc));
			need_add_visu(&(crwr->arena), temp->pc, 1);
		}
*/
