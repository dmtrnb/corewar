/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_update.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:27:01 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/09 12:08:31 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	visu_update_cursors1(t_cursor *current, t_arena *arena, \
																t_visu *visu)
{
	unsigned	i;

	wattron(visu->procces, COLOR_PAIR(9));
	mvwprintw(visu->procces, 1, 11, "%10u", visu->cursor + 1);
	mvwprintw(visu->procces, 2, 11, "%10u", visu->count);
	mvwprintw(visu->procces, 4, 17, "%4u", current->pc);
	mvwprintw(visu->procces, 5, 20, "%u", (current->id & 0x80000000 ? 1 : 0));
	mvwprintw(visu->procces, 6, 18, "%3s", (arena->cycles_without_check > \
						arena->cycles - current->last_live ? "Yes" : "No"));
	mvwprintw(visu->procces, 8, 16, "%5s", (current->nc < 0x10 ? \
										g_op_tab[current->nc].name : "None"));
	mvwprintw(visu->procces, 9, 17, "%4u", (current->wait < 0 ? 0 : \
																current->wait));
	i = 0;
	while (i != REG_NUMBER)
	{
		mvwprintw(visu->procces, 11 + i, 11, "0x%08x", \
													*(current->registrs + i));
		i++;
	}
	wattroff(visu->procces, COLOR_PAIR(9));
	wrefresh(visu->procces);
}

static void	visu_update_cursors(t_cursor *cursor, t_arena *arena, \
										t_visu *visu, unsigned char *par_field)
{
	unsigned		i;
	t_cursor		*temp;
	t_cursor		*current;

	i = 0;
	while (i != MEM_SIZE)
	{
		*(par_field + i) &= 0xf;
		i++;
	}
	i = 0;
	temp = cursor;
	current = NULL;
	visu->cursor = (visu->cursor >= visu->count ? visu->count - 1 : \
																visu->cursor);
	while (temp)
	{
		if (i == visu->cursor)
			current = temp;
		*(par_field + temp->pc) |= 0x10;
		temp = temp->next;
		i++;
	}
	if (current)
		visu_update_cursors1(current, arena, visu);
}

static void	visu_update_cycles_lives(t_arena *arena, t_visu *visu)
{
	wattron(visu->cycles, COLOR_PAIR(9));
	mvwprintw(visu->cycles, 3, 13, "%8u", arena->cycles);
	mvwprintw(visu->cycles, 4, 12, "%4u/%04u", arena->cycles_without_check, \
														arena->cycles_to_die);
	wattroff(visu->cycles, COLOR_PAIR(9));
	wrefresh(visu->cycles);
	wattron(visu->lives, COLOR_PAIR(9));
	mvwprintw(visu->lives, 3, 13, "%8u", arena->nbr_live);
	mvwprintw(visu->lives, 4, 13, "%8u", arena->alive);
	wattroff(visu->lives, COLOR_PAIR(9));
	wrefresh(visu->lives);
}

static void	visu_update_arena(unsigned char *field, unsigned char *par_field, \
																t_visu *visu)
{
	unsigned	i;
	unsigned	j;
	unsigned	lim;
	unsigned	attrs;

	i = 0;
	j = visu->size * COLUMNS * visu->mem_part;
	lim = visu->size * COLUMNS * (visu->mem_part + 1);
	while (i + j != lim)
	{
		if (!((i + j) % visu->size))
		{
			wattron(visu->arena, COLOR_PAIR(9));
			mvwprintw(visu->arena, i / visu->size + 1, 2, "0x%04x |", i);
			wattroff(visu->arena, COLOR_PAIR(9));
		}
		wattron(visu->arena, (attrs = get_arena_attr(*(par_field + i + j))));
		mvwprintw(visu->arena, i / visu->size + 1, 11 + i % visu->size * 3, \
													"%02x", *(field + i + j));
		wattroff(visu->arena, attrs);
		i++;
	}
	mvprintw(COLUMNS, 3 * visu->size + 27, "%2u", visu->mem_part + 1);
	wrefresh(visu->arena);
}

void		visu_update(t_crwr *crwr)
{
	if (crwr->arena->visu->count)
		visu_update_cursors(crwr->cursor, crwr->arena, crwr->arena->visu, \
									(unsigned char *)crwr->arena->par_field);
	visu_update_cycles_lives(crwr->arena, crwr->arena->visu);
	visu_update_arena((unsigned char *)crwr->arena->field, \
					(unsigned char *)crwr->arena->par_field, crwr->arena->visu);
}
