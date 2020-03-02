/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:46:23 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/02 16:03:26 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cfork(t_crwr *crwr, t_cursor *temp)
{
	int				num;

	num = get_direct((unsigned char *)crwr->arena->field, temp->pc + 1, 0);
	ft_cursor_add(&(crwr->cursor), ft_cursor_fork(temp, looped(temp->pc, num % IDX_MOD), crwr->cursor->id + 1));
	crwr->cursor->nc = *((unsigned char *)crwr->arena->field + crwr->cursor->pc) - 1;
	crwr->cursor->wait = (crwr->cursor->nc < 0x10 ? g_op_tab[crwr->cursor->nc].wait - 1 : 0);
//	printf("%u %u %u\n", crwr->cursor->nc, crwr->cursor->wait, crwr->cursor->id & 0x7ffffff);
}

void	lfork(t_crwr *crwr, t_cursor *temp)
{
	int				num;

	num = get_direct((unsigned char *)crwr->arena->field, temp->pc + 1, 0);
	ft_cursor_add(&(crwr->cursor), ft_cursor_fork(temp, looped(temp->pc, num), crwr->cursor->id));
	crwr->cursor->nc = *((unsigned char *)crwr->arena->field + crwr->cursor->pc) - 1;
	crwr->cursor->wait = (crwr->cursor->nc < 0x10 ? g_op_tab[crwr->cursor->nc].wait - 1: 0);
//	printf("%u %u %u\n", crwr->cursor->nc, crwr->cursor->wait, crwr->cursor->id & 0x7ffffff);
}
