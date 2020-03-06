/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:02:56 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/06 15:18:51 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		visu_update_cursors(t_cursor *cursor, t_arena *arena, t_visu *visu)
{
	unsigned		i;
	t_cursor		*temp;
	t_cursor		*current;
	unsigned char	*par_field;

	i = 0;
	par_field = (unsigned char *)arena->par_field;
	while (i != MEM_SIZE)
	{
		*(par_field + i) &= 0xf;
		i++;
	}
	i = 0;
	temp = cursor;
	current = NULL;
	visu->cursor = (visu->cursor >= visu->count ? visu->count - 1 : visu->cursor);
	while (temp)
	{
		if (i == visu->cursor)
			current = temp;
		*(par_field + temp->pc) |= 0x10;
		temp = temp->next;
		i++;
	}
	wattron(visu->procces, COLOR_PAIR(9));
	mvwprintw(visu->procces, 1, 11, "%10u", visu->cursor + 1);
	mvwprintw(visu->procces, 2, 11, "%10u", visu->count);
	if (current)
	{
		mvwprintw(visu->procces, 4, 17, "%4u", current->pc);
		mvwprintw(visu->procces, 5, 20, "%u", (current->id & 0x80000000 ? 1 : 0));
		mvwprintw(visu->procces, 6, 18, "%3s", (arena->cycles_without_check > arena->cycles - current->last_live ? "Yes" : "No"));
		mvwprintw(visu->procces, 8, 16, "%5s", (current->nc < 0x10 ? g_op_tab[current->nc].name : "None"));
		mvwprintw(visu->procces, 9, 17, "%4u", (current->wait < 0 ? 0 : current->wait));
		i = 0;
		while (i != REG_NUMBER)
		{
			mvwprintw(visu->procces, 11 + i, 11, "0x%08x", *(current->registrs + i));
			i++;
		}
	}
	wattroff(visu->procces, COLOR_PAIR(9));
	wrefresh(visu->procces);
}

void		visu_update_cycles_lives(t_arena *arena, t_visu *visu)
{	
	wattron(visu->cycles, COLOR_PAIR(9));
	mvwprintw(visu->cycles, 3, 13, "%8u", arena->cycles);
	mvwprintw(visu->cycles, 4, 12, "%4u/%04u", arena->cycles_without_check, arena->cycles_to_die);
	wattroff(visu->cycles, COLOR_PAIR(9));
	wrefresh(visu->cycles);
	wattron(visu->lives, COLOR_PAIR(9));
	mvwprintw(visu->lives, 3, 13, "%8u", arena->nbr_live);
	mvwprintw(visu->lives, 4, 13, "%8u", arena->alive);
	wattroff(visu->lives, COLOR_PAIR(9));
	wrefresh(visu->lives);
}

void		visu_update_arena(unsigned char *field, unsigned char *par_field, t_visu *visu)
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
			mvwprintw(visu->arena, i / visu->size + 1, 2, (i ? "%#06x |" : "0x%04u |"), i);
			wattroff(visu->arena, COLOR_PAIR(9));
		}
		wattron(visu->arena, (attrs = get_arena_attr(*(par_field + i + j))));
		mvwprintw(visu->arena, i / visu->size + 1, 11 + i % visu->size * 3, "%02x", *(field + i + j));
		wattroff(visu->arena, attrs);
		i++;
	}
	mvprintw(COLUMNS, 3 * visu->size + 27, "%2u", visu->mem_part + 1);
	wrefresh(visu->arena);
}

void		visu_update(t_crwr *crwr)
{
	(crwr->arena->visu->count ? visu_update_cursors(crwr->cursor, crwr->arena, crwr->arena->visu) : NULL);
	visu_update_cycles_lives(crwr->arena, crwr->arena->visu);
	visu_update_arena((unsigned char *)crwr->arena->field, (unsigned char *)crwr->arena->par_field, crwr->arena->visu);
}

static void	check(t_arena *arena, t_cursor **cursor)
{
	t_cursor	*temp;

	temp = *cursor;
	while (temp)
		temp = (arena->cycles - temp->last_live >= \
	(unsigned)arena->cycles_to_die ? ft_cursor_del(cursor, &temp) : temp->next);
	arena->nbr_check++;
	if (arena->nbr_live >= NBR_LIVE || arena->nbr_check >= MAX_CHECKS)
	{
		arena->cycles_to_die -= CYCLE_DELTA;
		arena->nbr_check = 0;
	}
	arena->nbr_live = 0;
	arena->cycles_without_check = 0;
}

void		say_visu_buy(t_name *name, unsigned alive, t_visu *visu)
{
	unsigned char	i;
	unsigned char	nick[34];
	unsigned char	comm[34];
	t_name			*temp;

	i = 1;
	temp = name;
	while (i++ != alive)
		temp = temp->next;
	i = 0;
	while ((*(temp->name + i) || *(temp->comment + i)) && i < 33)
	{
		if (*(temp->name + i))
			*(nick + i) = *(temp->name + i);
		if (*(temp->comment + i))
			*(comm + i) = *(temp->comment + i);
		i++;
	}
	if (*(temp->name + i))
	{
		*(nick + i - 1) = '.';
		*(nick + i - 2) = '.';
	}
	if (*(temp->comment + i))
	{
		*(comm + i - 1) = '.';
		*(comm + i - 2) = '.';
	}
	*(nick + i) = '\0';
	*(comm + i) = '\0';
	nodelay(stdscr, FALSE);
	draw_box(9, 49, 39, visu->size * 3 + 15);
	mvprintw(40, visu->size * 3 + 32, "PLAYER %u WON!", alive);
	mvprintw(45, visu->size * 3 + 30, "Press 'q' to exit");
	attrset(COLOR_PAIR(alive));
	mvprintw(42, visu->size * 3 + 16, "%33s", nick);
	mvprintw(43, visu->size * 3 + 16, "%33s", comm);
	while (getch() != 'q')
		;
	if (name && alive)
		NULL;
	delwin(visu->arena);
	delwin(visu->cycles);
	delwin(visu->lives);
	delwin(visu->procces);
	endwin();
}

void		visu_arena(t_crwr *crwr, t_arena *arena, t_visu *visu)
{
	while (visu->cond & 0x80)
	{
		visu->count = count_of_cursor(crwr->cursor);
		get_key(visu);
		if (!(visu->cond & 0x08))
		{
			arena->cycles++;
			arena->cycles_without_check++;
			cycle(crwr);
			if (arena->cycles_without_check == (unsigned)arena->cycles_to_die)
				check(arena, &(crwr->cursor));
			if (arena->cycles_to_die <= 0 || (int)arena->cycles == crwr->nbr_cycles)
				break ;
			if (visu->cond & 0x02)
				visu->cond = (visu->cond & 0xfd) | 0x08;
			if (!crwr->cursor)
				visu->cond &= 0x7f;
		}
		visu_update(crwr);
	}
	say_visu_buy(crwr->name, arena->alive, visu);
	if (!crwr->cursor)
		crwr->nbr_cycles = -1;
}

void		arena(t_crwr *crwr, t_arena *arena)
{
	if (!crwr->nbr_cycles)
		return ;
	while (crwr->cursor)
	{
		arena->cycles++;
		arena->cycles_without_check++;
		cycle(crwr);
		if (arena->cycles_without_check == (unsigned)arena->cycles_to_die)
			check(arena, &(crwr->cursor));
		if (arena->cycles_to_die <= 0 || (int)arena->cycles == crwr->nbr_cycles)
			break ;
	}
	if (!crwr->cursor)
		crwr->nbr_cycles = -1;
}
