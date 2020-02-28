/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:46:23 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/28 15:25:09 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cfork(t_crwr *crwr, t_cursor *temp)
{
	int				num;
	unsigned char	num_code;

	num = get_direct((unsigned char *)crwr->arena->field, temp->pc + 1, 0);
	ft_cursor_add(&(crwr->cursor), ft_cursor_fork(temp, looped(temp->pc, num % IDX_MOD), crwr->cursor->id));
	num_code = *((unsigned char *)crwr->arena->field + crwr->cursor->pc) - 1;
	crwr->cursor->wait = (num_code < 0x10 ? g_op_tab[num_code].wait - 1: 0);
}

void	lfork(t_crwr *crwr, t_cursor *temp)
{
	int				num;
	unsigned char	num_code;

	num = get_direct((unsigned char *)crwr->arena->field, temp->pc + 1, 0);
	ft_cursor_add(&(crwr->cursor), ft_cursor_fork(temp, looped(temp->pc, num), crwr->cursor->id));
	num_code = *((unsigned char *)crwr->arena->field + crwr->cursor->pc) - 1;
	crwr->cursor->wait = (num_code < 0x10 ? g_op_tab[num_code].wait - 1: 0);
}
