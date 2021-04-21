/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:40:09 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/06 18:46:56 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	zjmp(t_crwr *crwr, t_cursor *temp)
{
	int		num;

	if (temp->id & 0x80000000)
	{
		num = get_direct(crwr->arena->field, looped(temp->pc, 1), 0);
		temp->pc = looped(temp->pc, num % IDX_MOD);
	}
}

void	aff(t_crwr *crwr, t_cursor *temp)
{
	static unsigned	i = 0;
	unsigned char	c;
	unsigned char	r;

	r = *((unsigned char *)crwr->arena->field + looped(temp->pc, 2)) - 1;
	c = *(temp->registrs + r);
	if (crwr->opt & 0x80 && ft_isprint(c))
	{
		attrset(COLOR_PAIR(9));
		mvprintw(50, crwr->arena->visu->size * 3 + 22 + i % 39, "%c", c);
		attrset(COLOR_PAIR(9) | A_REVERSE);
		if ((i % 39) != 38)
			mvprintw(50, crwr->arena->visu->size * 3 + 22 + i % 39 + 1, " ");
		attrset(0);
		refresh();
		i++;
	}
	else if (crwr->opt & 0x08)
		ft_printf("Aff: %c\n", c);
}
