/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:02:56 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/26 17:53:02 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		check(t_crwr *crwr, t_cursor *cursor)
{
	t_cursor	*temp;

    if (!crwr->visu && crwr->nbr_cycles == crwr->arena->cycles)
		print_ump(crwr, crwr->arena, cursor);
//		print_dump((*crwr)->arena->field);
	if (crwr->arena->cycles_to_die <= 0)
		return (0);
	else if (crwr->arena->cycles_without_check == crwr->arena->cycles_to_die - 1)
	{
		if (crwr->arena->nbr_live >= NBR_LIVE || crwr->arena->nbr_check >= MAX_CHECKS)
		{
			crwr->arena->cycles_to_die -= CYCLE_DELTA;
			crwr->arena->nbr_check = 1;
		}
		else
			crwr->arena->nbr_check++;
		crwr->arena->nbr_live = 0;
		crwr->arena->cycles_without_check = 0;
		temp = *cursor;
		while (temp)
			temp = (crwr->arena->cycles - temp->last_live >= crwr->arena->cycles_to_die ? ft_cursor_del_id(cursor, temp->id, crwr) : temp->next);
		if (!cursor)
			return (0);
	}
	else
		crwr->arena->cycles_without_check++;
	return (1);
}

void		arena(t_crwr *crwr, t_cursor *cursor)
{
	while (check(crwr, cursor))
//		else
//			cycle(crwr, &cursor);
}

//	if ((*crwr)->visu)
//		visu(crwr);
/*	if ((*crwr)->visu)
    {
		while (getch() != KEY_DOWN)
			;	
        if ((*crwr)->visu)
            endwin();
			}*/
