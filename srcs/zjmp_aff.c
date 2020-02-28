/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:40:09 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/28 14:27:15 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_crwr *crwr, t_cursor *temp)
{
	int		num;

	num = get_direct(crwr->arena->field, temp->pc + 1, 0);
	if (temp->id & 0x80000000)
		temp->pc = looped(num % IDX_MOD, -3);
}

void	aff(t_crwr *crwr, t_cursor *temp)
{
	unsigned char	c;
	unsigned char	r;

	r = *((unsigned char *)crwr->arena->field + looped(temp->pc, 2)) - 1;
	c = *(temp->registrs + r);
	if (crwr->opt & 0x08)
		printf("Aff: %c\n", c);
}
