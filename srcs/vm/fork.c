/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:46:23 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/04 15:34:24 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	cfork(t_crwr *crwr, t_cursor *temp)
{
	int				num;

	num = get_direct((unsigned char *)crwr->arena->field, \
														looped(temp->pc, 1), 0);
	ft_cursor_add(&(crwr->cursor), ft_cursor_fork(temp, \
						looped(temp->pc, num % IDX_MOD), crwr->cursor->id + 1));
}

void	lfork(t_crwr *crwr, t_cursor *temp)
{
	int				num;

	num = get_direct((unsigned char *)crwr->arena->field, \
														looped(temp->pc, 1), 0);
	ft_cursor_add(&(crwr->cursor), ft_cursor_fork(temp, \
								looped(temp->pc, num), crwr->cursor->id + 1));
}
