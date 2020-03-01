/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:02:56 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/01 18:21:41 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	check(t_arena *arena, t_cursor **cursor)
{
	t_cursor	*temp;

	unsigned wo = arena->cycles_without_check;
	unsigned ct = 0;
	unsigned count = 0;
	
	arena->nbr_check++;
	if (arena->nbr_live >= NBR_LIVE || arena->nbr_check >= MAX_CHECKS)
	{
		arena->cycles_to_die -= CYCLE_DELTA;
		arena->nbr_check = 0;
	}
	arena->nbr_live = 0;
	arena->cycles_without_check = 0;
	temp = *cursor;
	while (temp)
	{
		ct++;
		temp = (arena->cycles - temp->last_live >= (unsigned)arena->cycles_to_die ? \
				ft_cursor_del(cursor, &temp) : temp->next);
	}
	temp = *cursor;
	while (temp)
	{
		count++;
//		printf("pid: %4u id: %4u last_live: %4u\n", (temp->id >> 27) & 0xf, temp->id & 0x7ffffff, temp->last_live);
		temp = temp->next;
	}
	printf("CYCLES: %u (%u) --- COUNT: %u->%u\n", arena->cycles, wo, ct, count);
}

void		arena(t_crwr *crwr, t_arena *arena)
{
	if (!crwr->nbr_cycles)
		return ;
	while (crwr->cursor)
	{
		arena->cycles++;
		arena->cycles_without_check++;
//		printf("%s %d ", g_op_tab[*((unsigned char *)arena->field + crwr->cursor->pc) - 1].name, crwr->cursor->pc);
		cycle(crwr);
//		printf("%d %u\n", crwr->cursor->pc, crwr->arena->cycles);
		if (arena->cycles_without_check == (unsigned)arena->cycles_to_die)
			check(arena, &(crwr->cursor));
		if (arena->cycles_to_die <= 0 || (int)arena->cycles == crwr->nbr_cycles)
			break ;
	}
	if (!crwr->cursor)
		crwr->nbr_cycles = -1;
}
