/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:28:59 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/15 11:40:59 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char		correct_reg(unsigned char *field, t_cursor *temp, \
										unsigned char num, unsigned char arg)
{
	unsigned		i;
	unsigned		pc;
	unsigned char	code;

	i = 0;
	pc = (g_op_tab[num].args_exists ? looped(temp->pc, 2) : \
														looped(temp->pc, 1));
	while (i < g_op_tab[num].args)
	{
		code = (arg >> (6 - i * 2)) & 0x03;
		if (code == REG_CODE)
		{
			if (!(*(field + pc)) || *(field + pc) > REG_NUMBER)
				return (0);
			pc = looped(pc, 1);
		}
		else if (code == DIR_CODE)
			pc = (g_op_tab[num].dir_is_four ? looped(pc, 2) : \
														looped(pc, DIR_SIZE));
		else if (code == IND_CODE)
			pc = looped(pc, IND_SIZE);
		i++;
	}
	return (1);
}

static unsigned	steps(unsigned char num, unsigned char arg, char *correct)
{
	unsigned		i;
	unsigned char	count;
	unsigned char	code;
	unsigned char	mask;

	i = 0;
	count = 0;
	while (i < g_op_tab[num].args)
	{
		mask = g_op_tab[num].mask[i];
		code = (arg >> (6 - i * 2)) & 0x03;
		if (code == REG_CODE)
			count += 1;
		else if (code == IND_CODE)
		{
			count += 2;
			code = T_IND;
		}
		else if (code == DIR_CODE)
			count += (g_op_tab[num].dir_is_four ? 2 : 4);
		if (!(mask & code))
			*correct = 0;
		i++;
	}
	return (count);
}

static char		correct(unsigned char *field, t_cursor *temp)
{
	char			correct;
	unsigned char	arg;

	correct = 1;
	temp->step = 1;
	if (temp->nc < 0x10)
	{
		arg = (g_op_tab[temp->nc].args_exists ? \
										*(field + looped(temp->pc, 1)) : 0x80);
		temp->step = steps(temp->nc, arg, &correct) + \
									(g_op_tab[temp->nc].args_exists ? 2 : 1);
		correct = (correct ? correct_reg(field, temp, temp->nc, arg) : 0);
	}
	else
		correct = 0;
	return (correct);
}

void			cycle(t_crwr *crwr)
{
	t_cursor		*temp;

	temp = crwr->cursor;
	while (temp)
	{
		if (temp->wait == -1)
		{
			temp->nc = *((unsigned char *)crwr->arena->field + temp->pc) - 1;
			temp->wait = (temp->nc < 0x10 ? g_op_tab[temp->nc].wait - 1 : 0);
		}
		if (!temp->wait)
		{
			if (correct((unsigned char *)crwr->arena->field, temp))
			{
				(crwr->opt & 0x07 ? debug(crwr, temp) : NULL);
				g_op_tab[temp->nc].func(crwr, temp);
			}
			if (temp->nc == 8 && temp->id & 0x80000000)
				temp->step = 0;
			temp->pc = looped(temp->pc, temp->step);
		}
		temp->wait--;
		temp = temp->next;
	}
}
