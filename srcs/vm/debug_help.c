/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 13:50:09 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/15 14:52:33 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_arg(unsigned char *field, t_cursor *temp, \
											unsigned *pc, unsigned char arg)
{
	int		adr;
	int		num;

	if (arg == REG_CODE)
	{
		adr = *(field + *pc);
		num = *(temp->registrs + adr - 1);
		ft_printf("r%u (0x%08x)", adr, num);
		*pc = looped(*pc, 1);
		return (num);
	}
	else if (arg == IND_CODE)
	{
		adr = get_direct(field, *pc, 0);
		num = get_direct(field, looped(temp->pc, adr % IDX_MOD), 1);
		ft_printf("0x%08x from %d", num, adr);
		get_mod(adr, 1);
		ft_putstr(" steps");
		*pc = looped(*pc, 2);
		return (num);
	}
	num = get_direct(field, *pc, (g_op_tab[temp->nc].dir_is_four ? 0 : 1));
	ft_printf("0x%08x", num);
	*pc = looped(*pc, g_op_tab[temp->nc].dir_is_four ? 2 : 4);
	return (num);
}

void	get_mod(int num, char mod)
{
	if (mod)
	{
		if (num >= IDX_MOD || num <= -IDX_MOD)
			ft_printf(" (%d %% IDX_MOD)", num);
	}
	else
	{
		if (num >= MEM_SIZE || num <= -MEM_SIZE)
			ft_printf(" (%d %% MEM_SIZE)", num);
	}
}
