/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:04:14 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/01 15:54:53 by nhamill          ###   ########.fr       */
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
			if (*(field + pc) && *(field + pc) > REG_NUMBER)
				return (0);
			pc = looped(pc, 1);
		}
		else if (code == DIR_CODE)
			pc = (g_op_tab[num].dir_is_four ? looped(pc, DIR_SIZE) : looped(pc, 2));
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
	unsigned char	next;

	correct = 1;
	*step = 1;
	*num = *(field + temp->pc) - 1;
	if (*num < 0x10)
	{
		arg = (g_op_tab[*num].args_exists ? *(field + looped(temp->pc, 1)) : 0x80);
		*step = steps(*num, arg, &correct) + (g_op_tab[*num].args_exists ? 2 : 1);
		correct = (correct ? correct_reg(field, temp, *num, arg) : 0);
	}
	else
		correct = 0;
	next = *(field + looped(temp->pc, *step)) - 1;
	temp->wait = (next < 0x10 ? g_op_tab[next].wait - 1 : 0);
	return (correct);
}

void			cycle(t_crwr *crwr)
{
	t_cursor		*temp;
	unsigned char	step;
	unsigned char	num;

	temp = crwr->cursor;
	while (temp)
	{
		if (!temp->wait)
		{
//			printf("%d ", temp->pc);
			if (correct((unsigned char *)crwr->arena->field, temp, &step, &num))
			{
//			printf("%d ", temp->pc);
				g_op_tab[num].func(crwr, temp);
//				debug(crwr->arena, temp, num);
			}
//			printf("%s ", g_op_tab[num].name);
			temp->pc = looped(temp->pc, step);
//			printf("%d %u %u\n", temp->pc, step, crwr->arena->cycles);
		}
		else
			temp->wait--;
		temp = temp->next;
	}
}
