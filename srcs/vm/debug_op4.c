/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_op4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 14:14:16 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/15 14:50:01 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	debug_st(unsigned char *field, t_cursor *temp, \
												unsigned pc, unsigned char arg)
{
	unsigned char	reg;

	reg = *(field + pc);
	pc = looped(pc, 1);
	ft_printf("r%u (0x%08x) -> ", reg, *(temp->registrs + reg - 1));
	get_arg(field, temp, &pc, (arg >> 4) & 0x03);
}

void	debug_sti(unsigned char *field, t_cursor *temp, \
												unsigned pc, unsigned char arg)
{
	int				num1;
	int				num2;
	int				adr;
	int				num;
	unsigned char	reg;

	reg = *(field + pc);
	pc = looped(pc, 1);
	ft_printf("r%u (0x%08x) -> to ((pc (%u) + (", \
									reg, *(temp->registrs + reg - 1), temp->pc);
	num1 = get_arg(field, temp, &pc, (arg >> 4) & 0x03);
	ft_putstr(" + ");
	num2 = get_arg(field, temp, &pc, (arg >> 2) & 0x03);
	adr = looped(temp->pc, (num1 + num2) % IDX_MOD);
	num = get_direct(field, adr, 1);
	ft_printf(") %% IDX_MOD) = %d) steps in 0x%08x", adr, num);
}
