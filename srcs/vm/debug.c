/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:04:14 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/16 09:53:46 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	debug_args(unsigned char arg, unsigned num)
{
	size_t			i;
	unsigned char	code;

	i = 0;
	while (i < g_op_tab[num].args)
	{
		code = (arg >> (6 - i * 2)) & 0x03;
		if (code == REG_CODE)
			ft_putstr(A23);
		else if (code == DIR_CODE)
			ft_putstr(A24);
		else if (code == IND_CODE)
			ft_putstr(A25);
		if (i != 2)
			ft_putstr(A26);
		i++;
	}
	while (i != 3)
	{
		ft_putstr(A22);
		if (i != 2)
			ft_putstr(A26);
		i++;
	}
	ft_putstr(A21);
}

static void	debug_info(t_arena *arena, t_cursor *temp)
{
	size_t i;

	ft_printf(A1"%u"A21, arena->cycles);
	ft_printf(A5"%u"A21, temp->id & 0x7ffffff);
	ft_printf(A2"%u"A21, arena->alive);
	ft_printf(A3"%u"A21, arena->nbr_live);
	ft_printf(A4"%d"A21, arena->cycles_to_die);
	ft_printf(A6"%u"A21, temp->pc);
	ft_printf(A7"%u"A21, temp->last_live);
	ft_putstr(A8);
	i = 0;
	while (i != REG_NUMBER)
	{
		ft_printf("%d ", *(temp->registrs + i));
		i++;
	}
	ft_putstr(A21);
	ft_printf(A9"%s"A21, g_op_tab[temp->nc].name);
	ft_putstr(A10);
}

static void	debug_action(unsigned char *field, t_cursor *temp, \
												unsigned pc, unsigned char arg)
{
	if (arg)
		NULL;
	ft_putstr(A27);
	if (temp->nc == 1 || temp->nc == 12)
		debug_ld(field, temp, pc, arg);
	else if (temp->nc == 2)
		debug_st(field, temp, pc, arg);
	if (temp->nc == 3 || temp->nc == 4)
		debug_add_sub(field, temp, pc);
	else if (temp->nc == 5 || temp->nc == 6 || temp->nc == 7)
		debug_and_or_xor(field, temp, pc, arg);
	else if (temp->nc == 8)
		debug_zjmp(field, temp, pc);
	else if (temp->nc == 9 || temp->nc == 13)
		debug_ldi(field, temp, pc, arg);
	else if (temp->nc == 10)
		debug_sti(field, temp, pc, arg);
	else if (temp->nc == 11 || temp->nc == 14)
		debug_fork(field, temp, pc);
	else if (temp->nc == 15)
		debug_aff(field, temp, pc);
	ft_putstr(A21);
}

void		debug(t_crwr *crwr, t_cursor *temp)
{
	unsigned		pc;
	unsigned char	arg;
	unsigned char	*field;

	if (crwr->nbr_cycles < 0 || (int)crwr->arena->cycles >= crwr->nbr_cycles)
	{
		field = (unsigned char *)crwr->arena->field;
		arg = (g_op_tab[temp->nc].args_exists ? \
							*(field + looped(temp->pc, 1)) : 0x80);
		pc = looped(temp->pc, arg == 0x80 ? 1 : 2);
		debug_info(crwr->arena, temp);
		debug_args(arg, temp->nc);
		if (temp->nc == 0)
			debug_live(field, temp, crwr->name, pc);
		else
			debug_action(field, temp, pc, arg);
		ft_putstr(A30);
		if (crwr->opt & 0x06 && !(crwr->opt & 0x01))
			while (getchar() != '\n')
				;
	}
}
