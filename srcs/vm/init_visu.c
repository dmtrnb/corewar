/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:17:00 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/14 17:09:41 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void				draw_usage(unsigned char size)
{
	draw_box(10, 33, 53, size * 3 + 15);
	mvprintw(54, size * 3 + 27, "USAGE");
	mvprintw(55, size * 3 + 16, "-----------------------------");
	mvprintw(57, size * 3 + 16, "space");
	mvprintw(57, size * 3 + 35, "start/stop");
	mvprintw(60, size * 3 + 16, "d");
	mvprintw(60, size * 3 + 36, "next step");
	mvprintw(59, size * 3 + 16, "s");
	mvprintw(59, size * 3 + 30, "previous cursor");
	mvprintw(58, size * 3 + 16, "w");
	mvprintw(58, size * 3 + 34, "next cursor");
	mvprintw(61, size * 3 + 16, "a");
	mvprintw(61, size * 3 + 26, "next part of memory");
	refresh();
}

static void				draw_other(t_name *name, unsigned char size, \
															unsigned char aff)
{
	unsigned	i;
	t_name		*temp;

	i = 0;
	temp = name;
	while (temp && ++i)
	{
		draw_box(5, 23, 5 + i * 6, size * 3 + 15);
		attron(COLOR_PAIR(i));
		mvprintw(6 + i * 6, size * 3 + 21, "PLAYER %u", i);
		print_visu_buy(temp->name, 8 + i * 6, size * 3 + 16, 20);
		attroff(COLOR_PAIR(i));
		temp = temp->next;
	}
	if (aff)
		NULL;
	{
		draw_box(3, 49, 49, size * 3 + 15);
		attron(COLOR_PAIR(9));
		mvprintw(50, size * 3 + 16, "Aff:");
		mvvline(50, size * 3 + 20, ACS_VLINE, 1);
		attroff(COLOR_PAIR(9));
	}
	refresh();
}

static unsigned char	get_visu_size(void)
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

static void				init_scr(void)
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

t_visu					*get_visu(t_crwr *crwr)
{
	t_visu	*visu;

	init_scr();
	if (!(visu = (t_visu *)malloc(sizeof(t_visu))))
		ft_error(ERR_MALLOC_VISUAL, -1);
	if (!(visu->size = get_visu_size()))
	{
		crwr->opt &= 0x7f;
		endwin();
		ft_putstr(NON_V);
		return (NULL);
	}
	get_visu_windows(crwr->arena, crwr->cursor, visu);
	draw_other(crwr->name, visu->size, crwr->opt & 0x08);
	draw_usage(visu->size);
	return (visu);
}
