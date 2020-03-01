/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:30:12 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/01 17:15:20 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ldi(t_crwr *crwr, t_cursor *temp)
{
	int				adr;
	int				num;
	unsigned char	off;
	unsigned char	arg;
	unsigned char	*field;

	field = (unsigned char *)crwr->arena->field;
	arg = *(field + looped(temp->pc, 1));
	if (arg & 0x40 && !(arg & 0x80))
		adr = *(temp->registrs + *(field + looped(temp->pc, 2)) - 1);
	else if (arg & 0x40)
		adr = get_indirect(field, looped(temp->pc, 2), temp->pc);
	else
		adr = get_direct(field, looped(temp->pc, 2), 0);
	off = 3 + (arg & 0x80 ? 1 : 0);
	if (arg & 0x10)
		adr += *(temp->registrs + *(field + looped(temp->pc, off)) - 1);
	else
		adr += get_direct(field, looped(temp->pc, off), 0);
	adr = looped(adr % IDX_MOD, 0);
	off += (arg & 0x10 ? 1 : 2);
	num = get_direct(field, looped(temp->pc, adr), 1);
	*(temp->registrs + *(field + looped(temp->pc, off)) - 1) = num;
}

void		lldi(t_crwr *crwr, t_cursor *temp)
{
	int				adr;
	int				num;
	unsigned char	off;
	unsigned char	arg;
	unsigned char	*field;

	field = (unsigned char *)crwr->arena->field;
	arg = *(field + looped(temp->pc, 1));
	if (arg & 0x40 && !(arg & 0x80))
		adr = *(temp->registrs + *(field + looped(temp->pc, 2)) - 1);
	else if (arg & 0x40)
		adr = get_indirect(field, looped(temp->pc, 2), temp->pc);
	else
		adr = get_direct(field, looped(temp->pc, 2), 0);
	off = 3 + (arg & 0x80 ? 1 : 0);
	if (arg & 0x10)
		adr += *(temp->registrs + *(field + looped(temp->pc, off)) - 1);
	else
		adr += get_direct(field, looped(temp->pc, off), 0);
	off += (arg & 0x10 ? 1 : 2);
	num = get_direct(field, looped(temp->pc, adr), 1);
	*(temp->registrs + *(field + looped(temp->pc, off)) - 1) = num;
	temp->id = (num ? temp->id & 0x7fffffff : temp->id | 0x80000000);
}
