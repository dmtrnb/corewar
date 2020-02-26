/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 05:15:07 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/26 17:03:38 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

size_t	looped(int num1, int num2)
{
	if (num1 + num2 < 0)
		return ((num1 + num2) % MEM_SIZE + MEM_SIZE);
	else
		return ((num1 + num2) % MEM_SIZE);
}

int		get_direct(void *arena, size_t pc, char size_four)
{
	int		num;

	num = 0;
	if (size_four)
	{
		num += *((unsigned char *)arena + looped(pc, 3));
		num += *((unsigned char *)arena + looped(pc, 2)) << 8;
		num += *((unsigned char *)arena + looped(pc, 1)) << 16;
		num += *((unsigned char *)arena + looped(pc, 0)) << 24;
	}
	else
	{
		num += *((unsigned char *)arena + looped(pc, 1));
		num += *((unsigned char *)arena + looped(pc, 0)) << 8;
		if (*((unsigned char *)arena + looped(pc, 0)) & 0x80)
			num |= 0xffff0000;
	}
	return (num);
}

int		get_indirect(t_cursor *cursor, void *arena, size_t pc)
{
	int	num;

	num = get_direct(arena, pc, 0);
	num = get_direct(arena, looped(cursor->pc, num % IDX_MOD), 1);
	return (num);
}
