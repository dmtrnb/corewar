/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:10:35 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/27 22:23:27 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	st(t_crwr *crwr, t_cursor *temp)
{
	int				r;
	int				adr;
	int				num;
	unsigned char	arg;
	unsigned char	*field;

	field = (unsigned char *)crwr->arena->field;
	arg = *(field + looped(temp->pc, 1));
	r = *(field + looped(temp->pc, 2)) - 1;
	num = *(temp->registrs + r);
	if (arg & 0x20)
	{
		adr = get_direct(field, looped(temp->pc, 3), 0) % IDX_MOD;
		*(field + looped(temp->pc, adr)) = num >> 24;
		*(field + looped(temp->pc, adr + 1)) = (num >> 16) & 0xff;
		*(field + looped(temp->pc, adr + 2)) = (num >> 8) & 0xff;
		*(field + looped(temp->pc, adr + 3)) = num & 0xff;
	}
	else
	{
		adr = *(field + looped(temp->pc, 3)) - 1;
		*(temp->registrs + adr) = num;
	}
}

void	sti(t_crwr *crwr, t_cursor *temp)
{
	int				off;
	int				adr;
	int				num;
	unsigned char	arg;
	unsigned char	*field;

	field = (unsigned char *)crwr->arena->field;
	arg = *(field + looped(temp->pc, 1));
	if (arg & 0x20 && arg & 0x10)
		adr = get_indirect(field, looped(temp->pc, 3), temp->pc);
	else if (arg & 0x10)
		adr = *(temp->registrs + *(field + looped(temp->pc, 3)) - 1);
	else
		adr = get_direct(field, looped(temp->pc, 3), 0);
	off = 3 + (!(arg & 0x20) && arg & 0x10 ? 1 : 2);
	if (arg & 0x04)
		adr += *(temp->registrs + *(field + looped(temp->pc, off)) - 1);
	else
		adr += get_direct(field, looped(temp->pc, off), 0);
	adr = adr % IDX_MOD;
	off = *(field + looped(temp->pc, 2)) - 1;
	num = *(temp->registrs + off);
	*(field + looped(temp->pc, adr)) = num >> 24;
	*(field + looped(temp->pc, adr + 1)) = (num >> 16) & 0xff;
	*(field + looped(temp->pc, adr + 2)) = (num >> 8) & 0xff;
	*(field + looped(temp->pc, adr + 3)) = num & 0xff;
}
