/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_op1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 11:01:03 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/16 09:52:45 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	debug_live(unsigned char *field, t_cursor *temp, \
													t_name *name, unsigned pc)
{
	int		id;
	int		num;
	t_name	*tmp;

	ft_putstr(A27);
	ft_printf("cursor %u is alive", temp->id & 0x7ffffff);
	id = 0;
	tmp = name;
	num = ~get_direct(field, pc, 1) + 1;
	while (tmp)
	{
		id++;
		if (id == num)
		{
			ft_printf(", player %u is alive", (temp->id >> 27) & 0xf);
			break ;
		}
		tmp = tmp->next;
	}
	ft_putstr(A21);
}

void	debug_zjmp(unsigned char *field, t_cursor *temp, unsigned pc)
{
	int		num;

	num = get_direct(field, pc, 0);
	ft_printf((temp->id & 0x80000000 ? "Jump to %d" : "Not jump to %d"), \
																num % IDX_MOD);
	get_mod(num, 1);
	ft_putstr(" steps");
	if (temp->id & 0x80000000)
		ft_printf(" -> 0x%08x", \
					get_direct(field, looped(temp->pc, num % IDX_MOD), 1));
}

void	debug_fork(unsigned char *field, t_cursor *temp, unsigned pc)
{
	int		num;
	int		adr;

	num = get_direct(field, pc, 0);
	adr = looped(temp->pc, num % IDX_MOD);
	ft_printf("New cursor was created on %u pc (0x%08x) by %s", \
					adr, get_direct(field, adr, 1), g_op_tab[temp->nc].name);
}

void	debug_aff(unsigned char *field, t_cursor *temp, unsigned pc)
{
	unsigned char	reg;

	reg = *(field + pc);
	ft_printf("r%u (0x%02x) was printed", reg, *(temp->registrs + reg - 1));
}
