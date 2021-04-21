/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_get_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:08:42 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/06 16:21:31 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static WINDOW	*get_visu_proc(t_arena *arena, t_cursor *cursor, \
											unsigned char size, unsigned count)
{
	unsigned	i;
	WINDOW		*proc;

	if (!(proc = newwin(28, 23, 11, size * 3 + 40)))
		ft_error(ERR_MALLOC_VISUAL, -1);
	box(proc, 0, 0);
	mvwprintw(proc, 1, 2, "Cursor            1");
	mvwprintw(proc, 2, 2, "Count    %10u", count);
	mvwprintw(proc, 4, 2, "PC             %4u", cursor->pc);
	mvwprintw(proc, 5, 2, "Carry             %u", cursor->id & 0x80000000);
	mvwprintw(proc, 6, 2, "Alive?          %3s", (arena->\
	cycles_without_check > arena->cycles - cursor->last_live ? "Yes" : "No"));
	mvwprintw(proc, 8, 2, "Operation    %5s", (cursor->nc < 0x10 ? \
										g_op_tab[cursor->nc].name : "None"));
	mvwprintw(proc, 9, 2, "Waiting");
	mvwprintw(proc, 9, 17, "%4u", (cursor->wait < 0 ? 0 : cursor->wait));
	i = 0;
	while (i != REG_NUMBER)
	{
		mvwprintw(proc, 11 + i, 2, "R%02u", i + 1);
		mvwprintw(proc, 11 + i, 11, "0x%08x", *(cursor->registrs + i));
		i++;
	}
	wrefresh(proc);
	return (proc);
}

static WINDOW	*get_visu_arena(t_arena *arena, unsigned char size)
{
	unsigned	i;
	unsigned	attrs;
	WINDOW		*field;

	if (!(field = newwin(66, size * 3 + 12, 0, 1)))
		ft_error(ERR_MALLOC_VISUAL, -1);
	box(field, 0, 0);
	i = 0;
	while (i != COLUMNS * size && i < MEM_SIZE)
	{
		if (!(i % size))
		{
			wattron(field, COLOR_PAIR(9));
			mvwprintw(field, i / size + 1, 2, (i ? "%#06x |" : "0x%04u |"), i);
			wattroff(field, COLOR_PAIR(9));
		}
		wattron(field, (attrs = get_arena_attr(\
									*((unsigned char *)arena->par_field + i))));
		mvwprintw(field, i / size + 1, 11 + i % size * 3, "%02x", \
									*((unsigned char *)arena->field + i));
		wattroff(field, attrs);
		i++;
	}
	wrefresh(field);
	return (field);
}

static WINDOW	*get_visu_live(t_arena *arena, unsigned char size)
{
	unsigned	num;
	WINDOW		*lives;

	num = 40 + 3 * size;
	if (!(lives = newwin(10, 23, 0, num)))
		ft_error(ERR_MALLOC_VISUAL, -1);
	box(lives, 0, 0);
	mvwprintw(lives, 1, 8, "LIVES");
	mvwprintw(lives, 2, 2, "-------------------");
	mvwprintw(lives, 3, 2, "nbr_live");
	mvwprintw(lives, 3, 13, "%8u", arena->nbr_live);
	mvwprintw(lives, 4, 2, "Alive");
	mvwprintw(lives, 4, 13, "%8u", arena->alive);
	mvwprintw(lives, 6, 2, "NBR_LIVE");
	mvwprintw(lives, 6, 13, "%8u", NBR_LIVE);
	mvwprintw(lives, 7, 2, "MAX_CHEKS");
	mvwprintw(lives, 7, 13, "%8u", MAX_CHECKS);
	wrefresh(lives);
	return (lives);
}

static WINDOW	*get_visu_cycle(t_arena *arena, unsigned char size)
{
	unsigned	num;
	WINDOW		*cycles;

	num = 14 + 3 * size;
	if (!(cycles = newwin(10, 23, 0, num)))
		ft_error(ERR_MALLOC_VISUAL, -1);
	box(cycles, 0, 0);
	mvwprintw(cycles, 1, 8, "CYCLES");
	mvwprintw(cycles, 2, 2, "-------------------");
	mvwprintw(cycles, 3, 2, "Cycle");
	mvwprintw(cycles, 3, 13, "%8u", arena->cycles);
	mvwprintw(cycles, 4, 2, "To Die");
	mvwprintw(cycles, 4, 12, "%4u/%04u", arena->cycles_without_check, \
													arena->cycles_to_die);
	mvwprintw(cycles, 7, 2, "DELTA");
	mvwprintw(cycles, 7, 13, "%8u", CYCLE_DELTA);
	wrefresh(cycles);
	return (cycles);
}

void			get_visu_windows(t_arena *arena, t_cursor *cursor, t_visu *visu)
{
	visu->cursor = 0;
	visu->count = count_of_cursor(cursor);
	visu->mem_part = 0;
	visu->mem_parts = MEM_SIZE / (COLUMNS * visu->size) + \
								(MEM_SIZE % (COLUMNS * visu->size) ? 1 : 0);
	visu->cond = 0x80 | 0x08;
	visu->arena = get_visu_arena(arena, visu->size);
	visu->cycles = get_visu_cycle(arena, visu->size);
	visu->lives = get_visu_live(arena, visu->size);
	visu->procces = get_visu_proc(arena, cursor, visu->size, visu->count);
	attron(COLOR_PAIR(9));
	mvprintw(COLUMNS, 3 * visu->size + 14, "MEMORY PART:  %u/%u", \
										visu->mem_part + 1, visu->mem_parts);
	attroff(COLOR_PAIR(9));
}
