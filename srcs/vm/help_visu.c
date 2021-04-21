/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:25:04 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/06 16:26:20 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			print_visu_buy(char *str, unsigned y, unsigned x, unsigned len)
{
	unsigned		i;
	unsigned char	name[len];

	i = 0;
	while (*(str + i) && i < len - 1)
	{
		*(name + i) = *(str + i);
		i++;
	}
	if (*(str + i))
	{
		*(name + i - 1) = '.';
		*(name + i - 2) = '.';
	}
	*(name + i) = '\0';
	mvprintw(y, x, "%*s", len - 1, name);
}

void			draw_box(unsigned line, unsigned column, unsigned y, unsigned x)
{
	mvhline(y, x, ACS_HLINE, column - 2);
	mvhline(y, x - 1, ACS_ULCORNER, 1);
	mvhline(y, x + column - 2, ACS_URCORNER, 1);
	mvhline(y + line - 1, x - 1, ACS_LLCORNER, 1);
	mvhline(y + line - 1, x + column - 2, ACS_LRCORNER, 1);
	mvhline(y + line - 1, x, ACS_HLINE, column - 2);
	mvvline(y + 1, x - 1, ACS_VLINE, line - 2);
	mvvline(y + 1, x + column - 2, ACS_VLINE, line - 2);
}

void			get_key(t_visu *visu)
{
	int		c;

	c = getch();
	if (c == ' ')
	{
		if (visu->cond & 0x08)
		{
			visu->cond &= 0xf7;
			nodelay(stdscr, TRUE);
		}
		else
		{
			visu->cond |= 0x08;
			nodelay(stdscr, FALSE);
		}
	}
	else if (c == 'w')
		visu->cursor = (visu->cursor + 1) % visu->count;
	else if (c == 's')
		visu->cursor = (visu->cursor ? visu->cursor - 1 : visu->count - 1);
	else if (c == 'a')
		visu->mem_part = (visu->mem_part == visu->mem_parts ? 0 : \
								(visu->mem_part + 1) % visu->mem_parts);
	else if (c == 'd')
		visu->cond = (visu->cond & 0xf7) | 0x02;
}

unsigned		get_arena_pair(unsigned char ch)
{
	if (ch & 0x40)
	{
		if (ch & 0x01)
			return (1 + MAX_COLOR_PL);
		else if (ch & 0x02)
			return (2 + MAX_COLOR_PL);
		else if (ch & 0x04)
			return (3 + MAX_COLOR_PL);
		else if (ch & 0x08)
			return (4 + MAX_COLOR_PL);
	}
	else
	{
		if (ch & 0x01)
			return (1);
		else if (ch & 0x02)
			return (2);
		else if (ch & 0x04)
			return (3);
		else if (ch & 0x08)
			return (4);
	}
	return (9);
}

unsigned		get_arena_attr(unsigned char ch)
{
	int		pair;
	int		attr;

	pair = get_arena_pair(ch);
	attr = COLOR_PAIR(pair);
	if (ch & 0x10)
		attr |= A_REVERSE;
	if (ch & 0x20)
		attr |= A_BOLD;
	return (attr);
}
