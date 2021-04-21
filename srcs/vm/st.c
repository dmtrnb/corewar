/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:10:35 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/06 17:03:24 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	visu_st(unsigned char *par_field, unsigned pc, unsigned pid)
{
	*(par_field + pc) &= 0xf0;
	*(par_field + looped(pc, 1)) &= 0xf0;
	*(par_field + looped(pc, 2)) &= 0xf0;
	*(par_field + looped(pc, 3)) &= 0xf0;
	*(par_field + pc) |= 0x01 << ((pid - 1) % MAX_COLOR_PL);
	*(par_field + looped(pc, 1)) |= 0x01 << ((pid - 1) % MAX_COLOR_PL);
	*(par_field + looped(pc, 2)) |= 0x01 << ((pid - 1) % MAX_COLOR_PL);
	*(par_field + looped(pc, 3)) |= 0x01 << ((pid - 1) % MAX_COLOR_PL);
}

void		st(t_crwr *crwr, t_cursor *temp)
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
		(crwr->opt & 0x80 ? visu_st((unsigned char *)crwr->arena->par_field, \
						looped(temp->pc, adr), (temp->id >> 27) & 0xf) : NULL);
	}
	else
	{
		adr = *(field + looped(temp->pc, 3)) - 1;
		*(temp->registrs + adr) = num;
	}
}

void		sti(t_crwr *crwr, t_cursor *temp)
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
	adr = (adr + (arg & 0x04 ? *(temp->registrs + *(field + looped(temp->pc, \
		off)) - 1) : get_direct(field, looped(temp->pc, off), 0))) % IDX_MOD;
	off = *(field + looped(temp->pc, 2)) - 1;
	num = *(temp->registrs + off);
	*(field + looped(temp->pc, adr)) = num >> 24;
	*(field + looped(temp->pc, adr + 1)) = (num >> 16) & 0xff;
	*(field + looped(temp->pc, adr + 2)) = (num >> 8) & 0xff;
	*(field + looped(temp->pc, adr + 3)) = num & 0xff;
	(crwr->opt & 0x80 ? visu_st((unsigned char *)crwr->arena->par_field, \
						looped(temp->pc, adr), (temp->id >> 27) & 0xf) : NULL);
}
