/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_op2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 12:12:08 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/15 14:06:50 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	debug_add_sub(unsigned char *field, t_cursor *temp, unsigned pc)
{
	int				num1;
	int				num2;
	char			sign;
	unsigned char	reg1;
	unsigned char	reg2;

	sign = (temp->nc == 3 ? '+' : '-');
	reg1 = *(field + pc);
	reg2 = *(field + looped(pc, 1));
	num1 = *(temp->registrs + reg1 - 1);
	num2 = *(temp->registrs + reg2 - 1);
	ft_printf("r%u (0x%08x) %c r%u (0x%08x) = 0x%08x -> r%u", reg1, num1, \
								sign, reg2, num2, \
		(sign == '+' ? num1 + num2 : num1 - num2), *(field + looped(pc, 2)));
}

void	debug_and_or_xor(unsigned char *field, t_cursor *temp, \
												unsigned pc, unsigned char arg)
{
	int		num1;
	int		num2;
	int		num;
	char	sign;

	if (temp->nc == 5)
		sign = '&';
	else
		sign = (temp->nc == 6 ? '|' : '^');
	num1 = get_arg(field, temp, &pc, arg >> 6);
	ft_printf(" %c ", sign);
	num2 = get_arg(field, temp, &pc, (arg >> 4) & 0x03);
	if (sign == '&')
		num = num1 & num2;
	else
		num = (sign == '|' ? num1 | num2 : num1 ^ num2);
	ft_printf(" = 0x%08x -> r%u", num, *(field + pc));
}
