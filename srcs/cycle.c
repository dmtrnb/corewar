/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:04:14 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/29 21:16:39 by nhamill          ###   ########.fr       */
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

void		debug(t_arena *arena, t_cursor *temp, unsigned num)
{
	printf(A1"%u"A21, arena->cycles);
	printf(A2"%u"A21, arena->alive);
	printf(A3"%u"A21, arena->nbr_live);
	printf(A4"%d"A21, arena->cycles_to_die);
	printf(A5"%u"A21, temp->id & 0x7ffffff);
	printf(A6"%u"A21, temp->pc);
	printf(A7"%u"A21, temp->last_live);
	size_t i = 0;
	printf(A8);
	while (i != REG_NUMBER)
	{
		printf("%d ", *(temp->registrs + i));
		i++;
	}
	printf(A21);
	printf(A9"%s"A21, g_op_tab[num].name);
	printf(A10);
	unsigned char	code;
	unsigned char	arg = (g_op_tab[num].args_exists ? *((unsigned char *)arena->field + looped(temp->pc, 1)) : 0x80);
	unsigned pc = (g_op_tab[num].args_exists ? looped(temp->pc, 2) : looped(temp->pc, 1));
	i = 0;
	while (i < g_op_tab[num].args)
	{
		code = (arg >> (6 - i * 2)) & 0x03;
		if (code == REG_CODE)
		{
			printf(A23);
			pc = looped(pc, 1);
		}
		else if (code == DIR_CODE)
		{
			printf(A24);
			pc = (g_op_tab[num].dir_is_four ? looped(pc, DIR_SIZE) : looped(pc, 2));
		}
		else if (code == IND_CODE)
		{
			printf(A25);
			pc = looped(pc, IND_SIZE);
		}
		else
			printf(A22);
		if (i != 2)
			printf(A26);
		i++;
	}
	while (i != 3)
	{
		printf(A22);
		if (i != 2)
			printf(A26);
		i++;
	}
	printf(A21);
	printf(A10);
	pc = (g_op_tab[num].args_exists ? looped(temp->pc, 2) : looped(temp->pc, 1));
	i = 0;
	while (i < g_op_tab[num].args)
	{
		code = (arg >> (6 - i * 2)) & 0x03;
		if (code == REG_CODE)
		{
			printf("%d", *(temp->registrs + *((unsigned char *)arena->field + pc) - 1));
			pc = looped(pc, 1);
		}
		else if (code == DIR_CODE)
		{
			printf("%d", get_direct(arena->field, pc, g_op_tab[num].dir_is_four));
			pc = (g_op_tab[num].dir_is_four ? looped(pc, DIR_SIZE) : looped(pc, 2));
		}
		else if (code == IND_CODE)
		{
			printf("%d", get_indirect(arena->field, pc, temp->pc));
			pc = looped(pc, IND_SIZE);
		}
		else
			printf(A22);
		if (i != 2)
			printf(A26);
		i++;
	}
	while (i != 3)
	{
		printf(A22);
		if (i != 2)
			printf(A26);
		i++;
	}
	printf(A21);
	getchar();
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
			if (correct((unsigned char *)crwr->arena->field, temp, &step, &num))
			{
				g_op_tab[num].func(crwr, temp);
				debug(crwr->arena, temp, num);
			}
			temp->pc = looped(temp->pc, step);
		}
		else
			temp->wait--;
		temp = temp->next;
	}
}
