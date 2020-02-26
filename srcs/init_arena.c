/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:06:41 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/26 17:50:49 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_cursor	*fill_arena(t_crwr *crwr)
{
	unsigned	i;
	unsigned	j;
	int			count;
	t_players	*temp;
	t_cursor	*cursor;

	i = 0;
	cursor = NULL;
	temp = crwr->players;
	count = ft_players_count(temp);
	while (temp)
	{
		j = 0;
		while (j != temp->code_size)
		{
			*((unsigned char *)crwr->arena->field + i + j) = \
								*((unsigned char *)temp->code + j);
			*((unsigned char *)crwr->arena->par_field + i + j) = (0x01 << ((temp->id - 1) % MAX_COLOR_PL)) + (j ? 0 : 0x10);
			j++;
		}
		ft_cursor_add(&cursor, ft_cursor_new(temp->id, count));
		cursor->num_code = *((unsigned char *)crwr->arena->field + cursor->pc);
		cursor->wait = (cursor->num_code && cursor->num_code <= 0x10 ? g_op_tab[cursor->num_code - 1].wait - 1 : 0);
		temp = temp->next;
		i += MEM_SIZE / count;
	}
	return (cursor);
}

t_arena		*init_arena(char alive)
{
	t_arena	*arena;

	if (!(arena = (t_arena *)malloc(sizeof(t_arena))))
		ft_error("Problem with malloc for arena", -4);
	if (!(arena->field = (unsigned char *)malloc(sizeof(char) * MEM_SIZE)))
		ft_error("Problem with malloc for field", -4);
	if (!(arena->par_field = (unsigned char *)malloc(sizeof(char) * MEM_SIZE)))
		ft_error("Problem with malloc for field", -4);
	bzero(arena->field, MEM_SIZE);	// FT
	bzero(arena->par_field, MEM_SIZE);	// FT
	arena->visu = NULL;
	arena->alive = alive;
	arena->cycles = 0;
	arena->nbr_live = 0;
	arena->cycles_without_check = 0;
	arena->cycles_to_die = CYCLE_TO_DIE;
	arena->nbr_check = 0;
	return (arena);
}
