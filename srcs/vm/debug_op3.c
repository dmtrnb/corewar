/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_op3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 13:10:50 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/16 09:54:55 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	debug_ld(unsigned char *field, t_cursor *temp, \
												unsigned pc, unsigned char arg)
{
	int				adr;
	int				num;
	unsigned char	reg;

	if (arg & 0x40)
	{
		reg = *(field + looped(pc, 2));
		adr = get_direct(field, pc, 0);
		if (temp->nc == 1)
			adr %= IDX_MOD;
		num = get_direct(field, looped(temp->pc, adr), 1);
		ft_printf("0x%08x from %d", num, adr);
		get_mod(adr, (temp->nc == 1 ? 1 : 0));
		ft_putstr(" steps");
	}
	else
	{
		reg = *(field + looped(pc, 4));
		num = get_direct(field, pc, 1);
		ft_printf("0x%08x", num);
	}
	ft_printf(" -> r%u", reg);
}

void	debug_ldi(unsigned char *field, t_cursor *temp, \
											unsigned pc, unsigned char arg)
{
	int		num1;
	int		num2;
	int		adr;
	int		num;

	ft_printf("From (pc (%u) +  (", temp->pc);
	num1 = get_arg(field, temp, &pc, arg >> 6);
	ft_putstr(" + ");
	num2 = get_arg(field, temp, &pc, (arg >> 4) & 0x03);
	if (temp->nc == 9)
	{
		adr = looped(temp->pc, (num1 + num2) % IDX_MOD);
		num = get_direct(field, adr, 1);
		ft_printf(") %% IDX_MOD) = %d steps (0x%08x) -> r%u", \
										adr, num, *(field + pc));
	}
	else
	{
		adr = looped(temp->pc, num1 + num2);
		num = get_direct(field, adr, 1);
		ft_printf(")) = %d steps (0x%08x) -> r%u", adr, num, *(field + pc));
	}
}
