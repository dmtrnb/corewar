/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:02:56 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/28 15:28:56 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	check(t_arena *arena, t_cursor **cursor)
{
	t_cursor	*temp;

	arena->nbr_check++;
	if (arena->nbr_live >= NBR_LIVE || arena->nbr_check >= MAX_CHECKS)
	{
		arena->cycles_to_die -= CYCLE_DELTA;
		arena->nbr_check = MAX_CHECKS;
	}
	arena->nbr_live = 0;
	arena->cycles_without_check = 0;
	temp = *cursor;
	while (temp)
		temp = (arena->cycles - temp->last_live >= arena->cycles_to_die ? \
				ft_cursor_del(&temp) : temp->next);
	if (!temp)
		*cursor = NULL;
}

void		arena(t_crwr *crwr, t_arena *arena, t_cursor *cursor)
{
	while (cursor)
	{
		arena->cycles++;
		arena->cycles_without_check++;
		cycle(crwr);
		if (arena->cycles_without_check == arena->cycles_to_die)
			check(arena, &cursor);
		if (arena->cycles_to_die <= 0 || (int)arena->cycles == crwr->nbr_cycles)
			break ;
	}
}
