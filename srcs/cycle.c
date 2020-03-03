/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:28:59 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/03 17:37:25 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char			correct_reg(unsigned char *field, t_cursor *temp, unsigned char num, unsigned char arg)
{
	unsigned		i;
	unsigned		pc;
	unsigned char	code;

    i = 0;
	pc = (g_op_tab[num].args_exists ? looped(temp->pc, 2) : looped(temp->pc, 1));
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
			pc = (g_op_tab[num].dir_is_four ? looped(pc, 2) : looped(pc, DIR_SIZE));
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

static char		correct(unsigned char *field, t_cursor *temp, unsigned char *step, unsigned char *num)
{
	char			correct;
	unsigned char	arg;

	correct = 1;
	*step = 1;
	*num = temp->nc;
	if (*num < 0x10)
	{
		arg = (g_op_tab[*num].args_exists ? *(field + looped(temp->pc, 1)) : 0x80);
		*step = steps(*num, arg, &correct) + (g_op_tab[*num].args_exists ? 2 : 1);
		correct = (correct ? correct_reg(field, temp, *num, arg) : 0);
	}
	else
		correct = 0;
//	temp->nc = *(field + looped(temp->pc, *step)) - 1;
//	temp->wait = (temp->nc < 0x10 ? g_op_tab[temp->nc].wait - 1 : 0);
//	if (cyc == 1075 && ((temp->id & 0x7ffffff) == 4))
//		printf("%u %u %u\n", temp->nc, temp->wait, *step);
	return (correct);
}

void			cycle(t_crwr *crwr)
{
	t_cursor		*temp;
	unsigned char	step;
	unsigned char	num;

//	if (crwr->opt & 0x80)
//		printf("It is now cycle %u\n", crwr->arena->cycles);
	temp = crwr->cursor;
	while (temp)
	{
		if (!temp->wait)
		{
			if (correct((unsigned char *)crwr->arena->field, temp, &step, &num))
			{
//				if (crwr->opt & 0x80)
				if (crwr->opt & 0x80 && crwr->arena->cycles > 9165)
//					bebug(crwr->arena, temp, num);
					debug(crwr->arena, temp, num);
				g_op_tab[num].func(crwr, temp);
				if (crwr->opt & 0x80 && crwr->arena->cycles > 9165)
//				if (crwr->opt & 0x80)
					debug(crwr->arena, temp, num);
			}
			if (num == 8 && temp->id & 0x80000000)
				step = 0;
			temp->pc = looped(temp->pc, step);
		}
		temp = temp->next;
	}
	temp = crwr->cursor;
	while (temp)
	{
		if (!temp->wait)
		{
			temp->nc = *((unsigned char *)crwr->arena->field + temp->pc) - 1;
			temp->wait = (temp->nc < 0x10 ? g_op_tab[temp->nc].wait - 1 : 0);
		}
		else
			temp->wait--;
		temp = temp->next;
	}
}
