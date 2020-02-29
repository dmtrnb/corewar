/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:46:23 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/29 20:15:37 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cfork(t_crwr *crwr, t_cursor *temp)
{
	int				num;
	unsigned char	num_code;

	num = get_direct((unsigned char *)crwr->arena->field, temp->pc + 1, 0);
	ft_cursor_add(&(crwr->cursor), ft_cursor_fork(temp, looped(temp->pc, num % IDX_MOD), crwr->cursor->id + 1));
	num_code = *((unsigned char *)crwr->arena->field + crwr->cursor->pc) - 1;
	crwr->cursor->wait = (num_code < 0x10 ? g_op_tab[num_code].wait - 1: 0);
	printf("FORK: %u; OLD_ID: %u %u ID: %u %u\n", crwr->arena->cycles, temp->id & 0x7ffffff, temp->pc, crwr->cursor->id & 0x7ffffff, crwr->cursor->pc);
}

void	lfork(t_crwr *crwr, t_cursor *temp)
{
	int				num;
	unsigned char	num_code;

	num = get_direct((unsigned char *)crwr->arena->field, temp->pc + 1, 0);
	ft_cursor_add(&(crwr->cursor), ft_cursor_fork(temp, looped(temp->pc, num), crwr->cursor->id));
	num_code = *((unsigned char *)crwr->arena->field + crwr->cursor->pc) - 1;
	crwr->cursor->wait = (num_code < 0x10 ? g_op_tab[num_code].wait - 1: 0);
	printf("FORK: %u; OLD_ID: %u ID: %u\n", crwr->arena->cycles, temp->id & 0x7ffffff, crwr->cursor->id & 0x7ffffff);
}
