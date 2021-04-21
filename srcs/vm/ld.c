/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:02:32 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/03 13:02:26 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ld(t_crwr *crwr, t_cursor *temp)
{
	int				num;
	unsigned char	r;
	unsigned char	arg;

	arg = *((unsigned char *)crwr->arena->field + looped(temp->pc, 1));
	if (arg & 0x40)
	{
		r = *((unsigned char *)crwr->arena->field + looped(temp->pc, 4)) - 1;
		num = get_indirect(crwr->arena->field, looped(temp->pc, 2), temp->pc);
	}
	else
	{
		r = *((unsigned char *)crwr->arena->field + looped(temp->pc, 6)) - 1;
		num = get_direct(crwr->arena->field, looped(temp->pc, 2), 1);
	}
	*(temp->registrs + r) = num;
	temp->id = (num ? temp->id & 0x7fffffff : temp->id | 0x80000000);
}

void		lld(t_crwr *crwr, t_cursor *temp)
{
	int				num;
	unsigned char	r;
	unsigned char	arg;

	arg = *((unsigned char *)crwr->arena->field + looped(temp->pc, 1));
	if (arg & 0x40)
	{
		r = *((unsigned char *)crwr->arena->field + looped(temp->pc, 4)) - 1;
		num = get_direct(crwr->arena->field, looped(temp->pc, 2), 0);
		num = get_direct(crwr->arena->field, looped(temp->pc, num), 1);
	}
	else
	{
		r = *((unsigned char *)crwr->arena->field + looped(temp->pc, 6)) - 1;
		num = get_direct(crwr->arena->field, looped(temp->pc, 2), 1);
	}
	*(temp->registrs + r) = num;
	temp->id = (num ? temp->id & 0x7fffffff : temp->id | 0x80000000);
}
