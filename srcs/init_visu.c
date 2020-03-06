/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:17:00 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/06 14:34:24 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			draw_other(t_name *name, unsigned char size)
{
	unsigned	i;
	unsigned	j;
	char		nick[21];
	t_name		*temp;

	i = 0;
	temp = name;
	while (temp && ++i)
	{
		j = 0;
		while (*(temp->name + j) && j < 19)
		{
			*(nick + j) = *(temp->name + j);
			j++;
		}
		if (*(temp->name + j))
		{
			*(nick + j - 1) = '.';
			*(nick + j - 2) = '.';
		}
		*(nick + j) = '\0';
		draw_box(5, 23, 5 + i * 6, size * 3 + 15);
		attron(COLOR_PAIR(i));
		mvprintw(6 + i * 6, size * 3 + 21, "PLAYER %u", i);
		mvprintw(8 + i * 6, size * 3 + 16, "%19s", nick);
		attroff(COLOR_PAIR(i));
		temp = temp->next;
	}
	draw_box(10, 33, 53, size * 3 + 15);
	mvprintw(54, size * 3 + 27, "USAGE");
	mvprintw(55, size * 3 + 16, "-----------------------------");
	mvprintw(57, size * 3 + 16, "space");
	mvprintw(57, size * 3 + 35, "start/stop");
	mvprintw(60, size * 3 + 16, "d");
	mvprintw(60, size * 3 + 36, "next step");
	mvprintw(59, size * 3 + 16, "a");
	mvprintw(59, size * 3 + 30, "previous cursor");
	mvprintw(58, size * 3 + 16, "w");
	mvprintw(58, size * 3 + 34, "next cursor");
	mvprintw(61, size * 3 + 16, "s");
	mvprintw(61, size * 3 + 26, "next part of memory");
	refresh();
}

static WINDOW	*get_visu_proc(t_arena *arena, t_cursor *cursor, unsigned char size, unsigned count)
{
	unsigned	i;
	WINDOW		*proc;

	if (!(proc = newwin(28, 23, 11, size * 3 + 40)))
		ft_error("m", -1);
	box(proc, 0, 0);
	mvwprintw(proc, 1, 2, "Cursor");
	mvwprintw(proc, 1, 20, "1");
	mvwprintw(proc, 2, 2, "Count");
	mvwprintw(proc, 2, 11, "%10u", count);
	mvwprintw(proc, 4, 2, "PC");
	mvwprintw(proc, 4, 17, "%4u", cursor->pc);
	mvwprintw(proc, 5, 2, "Carry");
	mvwprintw(proc, 5, 20, "%u", cursor->id & 0x80000000);
	mvwprintw(proc, 6, 2, "Alive?");
	mvwprintw(proc, 6, 18, "%3s", (arena->cycles_without_check > arena->cycles - cursor->last_live ? "Yes" : "No"));
	mvwprintw(proc, 8, 2, "Operation");
	mvwprintw(proc, 8, 16, "%5s", (cursor->nc < 0x10 ? g_op_tab[cursor->nc].name : "None"));
	mvwprintw(proc, 9, 2, "Waiting");
	mvwprintw(proc, 9, 17, "%4u", (cursor->wait < 0 ? 0 : cursor->wait));
	i = 0;
	while (i != REG_NUMBER)
	{
		mvwprintw(proc, 11 + i, 2, "R%02u", i + 1);
		mvwprintw(proc, 11 + i, 11, (*(cursor->registrs + i) ? "%#010x" : "0x%08x"), *(cursor->registrs + i));
		i++;
	}
	wrefresh(proc);
	return (proc);
}

static WINDOW	*get_visu_arena(t_arena *arena, unsigned char size, t_visu *visu)
{
	unsigned	i;
	unsigned	attrs;
	WINDOW		*field;

	if (!(field = newwin(66, size * 3 + 12, 0, 1)))
		ft_error("m", -1);
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
		wattron(field, (attrs = get_arena_attr(*((unsigned char *)arena->par_field + i))));
		mvwprintw(field, i / size + 1, 11 + i % size * 3, "%02x", *((unsigned char *)arena->field + i));
		wattroff(field, attrs);
		i++;
	}
	attron(COLOR_PAIR(9));
	mvprintw(COLUMNS, 3 * size + 14, "MEMORY PART:  %u/%u", visu->mem_part + 1, visu->mem_parts);
	attroff(COLOR_PAIR(9));
	wrefresh(field);
	return (field);
}

static WINDOW	*get_visu_live(t_arena *arena, unsigned char size)
{
	unsigned	num;
	WINDOW		*lives;

	num = 40 + 3 * size;
	if (!(lives = newwin(10, 23, 0, num)))
		ft_error("m", -1);
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
		ft_error("m", -1);
	box(cycles, 0, 0);
	mvwprintw(cycles, 1, 8, "CYCLES");
	mvwprintw(cycles, 2, 2, "-------------------");
	mvwprintw(cycles, 3, 2, "Cycle");
	mvwprintw(cycles, 3, 13, "%8u", arena->cycles);
	mvwprintw(cycles, 4, 2, "To Die");
	mvwprintw(cycles, 4, 12, "%4u/%04u", arena->cycles_without_check, arena->cycles_to_die);
	mvwprintw(cycles, 7, 2, "DELTA");
	mvwprintw(cycles, 7, 13, "%8u", CYCLE_DELTA);
	wrefresh(cycles);
	return (cycles);
}

unsigned char	get_visu_size(void)
{
	if (LINES < 68 || COLS < 78)
		return (0x0);
	else if (COLS >= 450)
		return (0x80);
	else if (COLS >= 258)
		return (0x40);
	else if (COLS >= 162)
		return (0x20);
	else if (COLS >= 114)
		return (0x10);
	else if (COLS >= 90)
		return (0x08);
	else if (COLS >= 78)
		return (0x04);
	return (0x0);
}

void	init_scr(void)
{
	initscr();
	if (noecho() || cbreak() || keypad(stdscr, TRUE))
	{
		endwin();
		exit(5);
	}
	if (!has_colors() || start_color())
	{
		endwin();
		exit(6);
	}
	curs_set(0);
	nodelay(stdscr, FALSE);
	mousemask(ALL_MOUSE_EVENTS, NULL);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_GREEN, COLOR_WHITE);
	init_pair(6, COLOR_MAGENTA, COLOR_WHITE);
	init_pair(7, COLOR_CYAN, COLOR_WHITE);
	init_pair(8, COLOR_RED, COLOR_WHITE);
	init_pair(9, COLOR_WHITE, COLOR_BLACK);
	refresh();
}

t_visu			*get_visu(t_crwr *crwr)
{
	t_visu	*visu;

	init_scr();
	if (!(visu = (t_visu *)malloc(sizeof(t_visu))))
		ft_error("malloc visu", -1);
	if (!(visu->size = get_visu_size()))
	{
		crwr->opt |= 0x7f;
		endwin();
		printf("Too small window\(");
		return (NULL);
	}
    visu->cursor = 0;
    visu->count = count_of_cursor(crwr->cursor);
    visu->mem_part = 0;
    visu->mem_parts = MEM_SIZE / (COLUMNS * visu->size) + (MEM_SIZE % (COLUMNS * visu->size) ? 1 : 0);
	visu->cond = 0x80 | 0x08;
	visu->arena = get_visu_arena(crwr->arena, visu->size, visu);
	visu->cycles = get_visu_cycle(crwr->arena, visu->size);
	visu->lives = get_visu_live(crwr->arena, visu->size);
	visu->procces = get_visu_proc(crwr->arena, crwr->cursor, visu->size, visu->count);
	draw_other(crwr->name, visu->size);
	return (visu);
}
