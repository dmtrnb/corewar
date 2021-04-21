/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 12:44:00 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/04 15:27:02 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add(t_crwr *crwr, t_cursor *temp)
{
	unsigned char	r1;
	unsigned char	r2;
	unsigned char	r3;
	unsigned char	*field;

	field = (unsigned char *)crwr->arena->field;
	r1 = *(field + looped(temp->pc, 2)) - 1;
	r2 = *(field + looped(temp->pc, 3)) - 1;
	r3 = *(field + looped(temp->pc, 4)) - 1;
	*(temp->registrs + r3) = *(temp->registrs + r1) + *(temp->registrs + r2);
	temp->id = (*(temp->registrs + r3) ? \
							temp->id & 0x7fffffff : temp->id | 0x80000000);
}

void	sub(t_crwr *crwr, t_cursor *temp)
{
	unsigned char	r1;
	unsigned char	r2;
	unsigned char	r3;
	unsigned char	*field;

	field = (unsigned char *)crwr->arena->field;
	r1 = *(field + looped(temp->pc, 2)) - 1;
	r2 = *(field + looped(temp->pc, 3)) - 1;
	r3 = *(field + looped(temp->pc, 4)) - 1;
	*(temp->registrs + r3) = *(temp->registrs + r1) - *(temp->registrs + r2);
	temp->id = (*(temp->registrs + r3) ? \
							temp->id & 0x7fffffff : temp->id | 0x80000000);
}
