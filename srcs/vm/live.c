/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:09:30 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/04 15:40:51 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char	player_exists(t_name *name, int num)
{
	int		id;
	t_name	*temp;

	id = 0;
	temp = name;
	while (temp)
	{
		id++;
		if (id == num)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void		live(t_crwr *crwr, t_cursor *temp)
{
	int		num;

	temp->last_live = crwr->arena->cycles;
	num = ~get_direct(crwr->arena->field, looped(temp->pc, 1), 1) + 1;
	crwr->arena->nbr_live++;
	if (player_exists(crwr->name, num))
		crwr->arena->alive = num;
}
