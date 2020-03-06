/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:04:14 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/03 13:52:26 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		debug_action(t_cursor *temp, unsigned num, t_debug *deb)
{
	printf(A27);
	if (deb->num == 10)
		debug10(temp, deb);
	else if (num == 3)
		debug_reg(temp, '+', deb);
	else if (num == 4)
		debug_reg(temp, '-', deb);
	else if (num == 5 || num == 6 || num == 7)
		debug_567(temp, deb);
	else if (num == 9 || num == 13)
		debug_9_13(temp, deb);
	else if (num == 12)
		debug_12(temp, deb);
	else if (num == 8)
		debug_8(temp, deb);
	else if (num == 1)
		debug_1(temp, deb);
	else if (num == 2)
		debug_2(temp, deb);
	else
		debug_11_14_15(temp, num, deb);
	printf(A21);
}

void		debug(t_arena *arena, t_cursor *temp, unsigned num)
{
	unsigned char	arg;
	unsigned		pc;
	t_debug			deb;

	debug_general_info(arena, temp, num);
	printf(A10);
	arg = (g_op_tab[num].args_exists ? *((unsigned char*)arena->field
			+ looped(temp->pc, 1)) : 0x80);
	pc = (g_op_tab[num].args_exists ? looped(temp->pc, 2) :
			looped(temp->pc, 1));
	debug_arg(arg, pc, num);
	printf(A10);
	pc = (g_op_tab[num].args_exists ? looped(temp->pc, 2) :
			looped(temp->pc, 1));
	debug_arg_value(arg, pc, num, arena);
	deb.field = (unsigned char *)arena->field;
	deb.arg = *(deb.field + looped(temp->pc, 1));
	deb.reg = *(deb.field + looped(temp->pc, 2));
	deb.num = num;
	debug_action(temp, num, &deb);
	printf(A30);
	getchar();
}
