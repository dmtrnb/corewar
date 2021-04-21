/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:39:57 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/07 16:40:45 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	say_visu_buy(t_name *name, unsigned alive, t_visu *visu)
{
	unsigned char	i;
	t_name			*temp;

	i = 1;
	temp = name;
	while (i++ != alive)
		temp = temp->next;
	nodelay(stdscr, FALSE);
	draw_box(8, 49, 40, visu->size * 3 + 15);
	mvprintw(41, visu->size * 3 + 32, "PLAYER %u WON!", alive);
	mvprintw(46, visu->size * 3 + 30, "Press 'q' to exit");
	attrset(COLOR_PAIR(alive));
	print_visu_buy(temp->name, 43, visu->size * 3 + 16, 34);
	print_visu_buy(temp->comment, 44, visu->size * 3 + 16, 34);
	refresh();
	while (getch() != 'q')
		;
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
			if (arena->cycles_to_die <= 0)
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
