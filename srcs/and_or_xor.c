/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_xor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:53:10 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/28 13:39:35 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static unsigned	get_pc_and_num(int *num, unsigned char *field, t_cursor *temp, unsigned pc)
{
	unsigned char	arg;

	arg = (temp->pc - pc == 2 || temp->pc - pc == MEM_SIZE - 2 ? \
		*(field + looped(temp->pc, 1)) : *(field + looped(temp->pc, 1)) >> 2);
	if (arg & 0x10 && !(arg & 0x20))
	{
		*num = *(temp->registrs + *(field + pc) - 1);
		pc = looped(pc, 1);
	}
	else
	{
		*num = (arg & 0x10 ? get_indirect(field, pc, temp->pc) : get_direct(field, pc, 1));
		pc = looped(pc, (arg & 0x10 ? IND_SIZE : DIR_SIZE));
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
	temp->id = (num1 & num2 ? temp->id & 0x7ffffff : temp->id | 0x80000000);
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
	temp->id = (num1 & num2 ? temp->id & 0x7ffffff : temp->id | 0x80000000);
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
	temp->id = (num1 & num2 ? temp->id & 0x7ffffff : temp->id | 0x80000000);
}
