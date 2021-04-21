/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_xor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:53:10 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/04 15:28:24 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static unsigned	get_pc_and_num(int *num, unsigned char *field, \
												t_cursor *temp, unsigned pc)
{
	unsigned char	arg;

	arg = (pc == looped(temp->pc, 2) ? *(field + looped(temp->pc, 1)) >> 6 : \
								(*(field + looped(temp->pc, 1)) >> 4) & 0x03);
	if (arg & 0x1 && !(arg & 0x2))
	{
		*num = *(temp->registrs + *(field + pc) - 1);
		pc = looped(pc, 1);
	}
	else
	{
		*num = (arg & 0x1 ? get_indirect(field, pc, temp->pc) : \
										get_direct(field, pc, 1));
		pc = looped(pc, (arg & 0x1 ? IND_SIZE : DIR_SIZE));
	}
	return (pc);
}

void			and(t_crwr *crwr, t_cursor *temp)
{
	int				num1;
	int				num2;
	unsigned		pc;
	unsigned char	*field;

	pc = looped(temp->pc, 2);
	field = (unsigned char *)crwr->arena->field;
	pc = get_pc_and_num(&num1, field, temp, pc);
	pc = get_pc_and_num(&num2, field, temp, pc);
	*(temp->registrs + *(field + pc) - 1) = num1 & num2;
	temp->id = (num1 & num2 ? temp->id & 0x7fffffff : temp->id | 0x80000000);
}

void			or(t_crwr *crwr, t_cursor *temp)
{
	int				num1;
	int				num2;
	unsigned		pc;
	unsigned char	*field;

	pc = looped(temp->pc, 2);
	field = (unsigned char *)crwr->arena->field;
	pc = get_pc_and_num(&num1, field, temp, pc);
	pc = get_pc_and_num(&num2, field, temp, pc);
	*(temp->registrs + *(field + pc) - 1) = num1 | num2;
	temp->id = (num1 | num2 ? temp->id & 0x7fffffff : temp->id | 0x80000000);
}

void			xor(t_crwr *crwr, t_cursor *temp)
{
	int				num1;
	int				num2;
	unsigned		pc;
	unsigned char	*field;

	pc = looped(temp->pc, 2);
	field = (unsigned char *)crwr->arena->field;
	pc = get_pc_and_num(&num1, field, temp, pc);
	pc = get_pc_and_num(&num2, field, temp, pc);
	*(temp->registrs + *(field + pc) - 1) = num1 ^ num2;
	temp->id = (num1 ^ num2 ? temp->id & 0x7fffffff : temp->id | 0x80000000);
}
