/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 20:04:14 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/03 14:03:27 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	debug10(t_cursor *temp, t_debug *deb)
{
	int				num;
	int				num1;
	int				num2;

	num = *(temp->registrs + deb->reg - 1);
	deb->pc = looped(temp->pc, 3);
	num1 = debug10_num1(temp, deb, num);
	num2 = debug10_num2(temp, deb, num, num1);
	printf("%02x%02x%02x%02x", (num >> 24) & 0xff, (num >> 16) & 0xff,
			(num >> 8) & 0xff, (num >> 0) & 0xff);
	printf(" -> \"%02x%02x%02x%02x\"", *(deb->field + looped(num, 0)),
			*(deb->field + looped(num, 1)), *(deb->field + looped(num, 2)),
					*(deb->field + looped(num, 3)));
}

int		debug10_num1(t_cursor *temp, t_debug *deb, int num)
{
	int num1;

	if (deb->arg & 0x20 && deb->arg & 0x10)
	{
		num1 = get_indirect(deb->field, deb->pc, temp->pc);
		printf("r%u (%d) -> (PC (%u) + (at %d steps + ",
				deb->reg, num, temp->pc, num1);
		deb->pc = looped(deb->pc, 2);
	}
	else if (deb->arg & 0x10)
	{
		num1 = *(temp->registrs + *(deb->field + deb->pc) - 1);
		printf("r%u (%d) -> (PC (%u) + (r%u (%d) + ", deb->reg,
				num, temp->pc, *(deb->field + deb->pc), num1);
		deb->pc = looped(deb->pc, 1);
	}
	else
	{
		num1 = get_direct(deb->field, deb->pc, 0);
		printf("r%u (%d) -> (PC (%u) + (%d + ", deb->reg, num, temp->pc, num1);
		deb->pc = looped(deb->pc, 2);
	}
	return (num1);
}

int		debug10_num2(t_cursor *temp, t_debug *deb, int num, int num1)
{
	int num2;

	if (deb->arg & 0x4)
	{
		num2 = *(temp->registrs + *(deb->field + deb->pc) - 1);
		num = looped(temp->pc, (num1 + num2) % IDX_MOD);
		printf("r%u (%d)) %% IDX_MOD = %u -> ",
				*(deb->field + deb->pc), num2, num);
		deb->pc = looped(deb->pc, 1);
	}
	else
	{
		num2 = get_direct(deb->field, deb->pc, 0);
		num = looped(temp->pc, (num1 + num2) % IDX_MOD);
		printf("%d) %% IDX_MOD = %u == ", num2, num);
		deb->pc = looped(deb->pc, 2);
	}
	return (num2);
}

int		debug_idx_mod(t_cursor *temp, t_debug *deb)
{
	int				num2;
	unsigned char	reg;

	if (deb->arg & 0x10)
	{
		reg = *(deb->field + deb->pc);
		num2 = *(temp->registrs + reg - 1);
		printf(" r%u (%d)) %% IDX_MOD) = ", reg, num2);
		deb->pc = looped(deb->pc, 1);
	}
	else
	{
		num2 = get_direct(deb->field, deb->pc, 0);
		printf(" %d) %% IDX_MOD) = ", num2);
		deb->pc = looped(deb->pc, 2);
	}
	return (num2);
}

int		debug_80_40(t_cursor *temp, char *s, t_debug *deb)
{
	int				num1;
	unsigned char	reg;

	if (deb->arg & 0x80 && deb->arg & 0x40)
	{
		printf("at %d steps ", get_direct(deb->field, looped(temp->pc, 2), 0));
		num1 = get_indirect(deb->field, looped(temp->pc, 2), temp->pc);
		printf("(%x) %s ", num1, s);
		deb->pc = looped(temp->pc, 4);
	}
	else if (deb->arg & 0x80)
	{
		printf("%x %s ", (num1 = get_direct(deb->field,
				looped(temp->pc, 2), 1)), s);
		deb->pc = looped(temp->pc, 6);
	}
	else
	{
		reg = *(deb->field + looped(temp->pc, 2));
		num1 = *(temp->registrs + reg - 1);
		printf("r%u (%x) %s ", reg, num1, s);
		deb->pc = looped(temp->pc, 3);
	}
	return (num1);
}

int		debug_20_10(t_cursor *temp, t_debug *deb)
{
	int				num2;

	if (deb->arg & 0x20 && deb->arg & 0x10)
	{
		num2 = get_direct(deb->field, deb->pc, 0);
		printf("at %d steps ", num2);
		num2 = get_indirect(deb->field, deb->pc, temp->pc);
		printf("(%x)", num2);
		deb->pc = looped(deb->pc, 2);
	}
	else if (deb->arg & 0x20)
	{
		num2 = get_direct(deb->field, deb->pc, 1);
		printf("%x", num2);
		deb->pc = looped(deb->pc, 4);
	}
	else
	{
		num2 = *(temp->registrs + *(deb->field + deb->pc) - 1);
		printf("r%u (%x)", *(deb->field + deb->pc), num2);
		deb->pc = looped(deb->pc, 1);
	}
	return (num2);
}

void	debug_reg(t_cursor *temp, char c, t_debug *deb)
{
	int				num1;
	int				num2;
	int				buf;
	unsigned char	r;

	r = *(deb->field + looped(temp->pc, 2));
	num1 = *(temp->registrs + r - 1);
	printf("r%u (%d) %c ", r, num1, c);
	r = *(deb->field + looped(temp->pc, 3));
	num2 = *(temp->registrs + r - 1);
	printf("r%u (%d) -> ", r, num2);
	r = *(deb->field + looped(temp->pc, 4));
	buf = c == '+' ? num1 + num2 : num1 - num2;
	printf("r%u = %d + carry -> %d", r, buf, (buf ? 0 : 1));
}

void	debug_567(t_cursor *temp, t_debug *deb)
{
	int				num1;
	int				num2;
	int				buf;

	if (deb->num == '5')
		num1 = debug_80_40(temp, "AND", deb);
	else
		num1 = deb->num == '6' ? debug_80_40(temp, "OR", deb)
				: debug_80_40(temp, "XOR", deb);
	num2 = debug_20_10(temp, deb);
	if (deb->num == '5')
		buf = num1 & num2;
	else
		buf = deb->num == '6' ? num1 | num2 : num1 ^ num2;
	deb->arg = *(deb->field + deb->pc);
	printf(" -> r%u = %d + carry -> %d", deb->arg, buf, (buf ? 0 : 1));
}

int		debug_80_40_pc(t_cursor *temp, t_debug *deb)
{
	int				num1;

	deb->pc = looped(temp->pc, 2);
	if (deb->arg & 0x80 && deb->arg & 0x40)
	{
		num1 = get_indirect(deb->field, deb->pc, temp->pc);
		printf("(PC (%u) + (at %02x%02x steps (%d) +", temp->pc,
				*(deb->field + deb->pc),
				*(deb->field + looped(deb->pc, 1)), num1);
		deb->pc = looped(deb->pc, 2);
	}
	else if (deb->arg & 0x40)
	{
		num1 = *(temp->registrs + *(deb->field + deb->pc) - 1);
		printf("(PC (%u) + (r%u (%d) +", temp->pc,
				*(deb->field + deb->pc), num1);
		deb->pc = looped(deb->pc, 1);
	}
	else
	{
		num1 = get_direct(deb->field, deb->pc, 0);
		printf("(PC (%u) + (%d +", temp->pc, num1);
		deb->pc = looped(deb->pc, 2);
	}
	return (num1);
}

void	debug_9_13(t_cursor *temp, t_debug *deb)
{
	int				num1;
	int				num2;
	unsigned char	reg;

	num1 = debug_80_40_pc(temp, deb);
	num2 = debug_idx_mod(temp, deb);
	reg = *(deb->field + deb->pc);
	num1 = looped(temp->pc, num1 + num2);
	num2 = get_direct(deb->field, num1, 1);
	if (deb->num == 9)
		printf("%d ==== %02x%02x%02x%02x -> r%u", num1, (num2 >> 24) & 0xff,
				(num2 >> 16) & 0xff, (num2 >> 8) & 0xff,
						(num2 >> 0) & 0xff, reg);
	else
		printf("%d ==== %02x%02x%02x%02x -> r%u + carry -> %d", num1,
			(num2 >> 24) & 0xff, (num2 >> 16) & 0xff, (num2 >> 8) & 0xff,
					(num2 >> 0) & 0xff, reg, (num2 ? 0 : 1));
}

void	debug_1(t_cursor *temp, t_debug *deb)
{
	int num;

	deb->arg = *(deb->field + looped(temp->pc, 1));
	if (deb->arg & 0x40)
		num = get_indirect(deb->field, looped(temp->pc, 2), temp->pc);
	else
		num = get_direct(deb->field, looped(temp->pc, 2), 1);
	deb->reg = *(deb->field + looped(temp->pc, (deb->arg & 0x40 ? 4 : 6)));
	printf("%d -> r%u + carry -> %d", num, deb->reg, (num ? 0 : 1));
}

void	debug_2(t_cursor *temp, t_debug *deb)
{
	int num;

	num = *(temp->registrs + deb->reg - 1);
	if (deb->arg & 0x20)
	{
		printf("r%u (%02x%02x%02x%02x) -> ", deb->reg, (num >> 24) & 0xff,
				(num >> 16) & 0xff, (num >> 8) & 0xff, (num >> 0) & 0xff);
		num = get_direct(deb->field,
				looped(temp->pc, 3), 0) % IDX_MOD;
		printf("at %d steps \"%02x%02x%02x%02x\"", num,
			*(deb->field + looped(temp->pc, num + 0)),
				*(deb->field + looped(temp->pc, num + 1)),
						*(deb->field + looped(temp->pc, num + 2)),
								*(deb->field + looped(temp->pc, num + 3)));
	}
	else
	{
		printf("r%u (%d) -> ", deb->reg, num);
		deb->reg = *(deb->field + looped(temp->pc, 3));
		printf("r%u", deb->reg);
	}
}

void	debug_12(t_cursor *temp, t_debug *deb)
{
	int num;

	deb->arg = *(deb->field + looped(temp->pc, 1));
	if (deb->arg & 0x40)
	{
		num = get_direct(deb->field, looped(temp->pc, 2), 0);
		num = get_direct(deb->field, looped(temp->pc, num), 1);
	}
	else
		num = get_direct(deb->field, looped(temp->pc, 2), 1);
	deb->reg = *(deb->field + looped(temp->pc, (deb->arg & 0x40 ? 4 : 6)));
	printf("%d -> r%u + carry -> %d", num, deb->reg, (num ? 0 : 1));
}

void	debug_8(t_cursor *temp, t_debug *deb)
{
	int num;

	if (temp->id & 0x80000000)
	{
		num = get_direct(deb->field, looped(temp->pc, 1), 0) % IDX_MOD;
		printf("Jumping at %02x%02x (%d) steps -> %u pc", *(deb->field +
				looped(temp->pc, 1)), *(deb->field + looped(temp->pc, 2)),
						num, looped(temp->pc, num));
	}
	else
		printf("Not jump. pc(%u)->new_pc(%u)", temp->pc, looped(temp->pc, 3));
}

void	debug_general_info(t_arena *arena, t_cursor *temp, unsigned num)
{
	size_t i;

	printf(A1"%u"A21, arena->cycles);
	printf(A5"%u"A21, temp->id & 0x7ffffff);
	printf(A2"%u"A21, arena->alive);
	printf(A3"%u"A21, arena->nbr_live);
	printf(A4"%d"A21, arena->cycles_to_die);
	printf(A6"%u"A21, temp->pc);
	printf(A7"%u"A21, temp->last_live);
	printf(A8);
	i = 0;
	while (i != REG_NUMBER)
	{
		printf("%d ", *(temp->registrs + i));
		i++;
	}
	printf(A21);
	printf(A9"%s"A21, g_op_tab[num].name);
}

void	debug_arg(unsigned char arg, unsigned pc, unsigned num)
{
	size_t			i;
	unsigned char	code;

	i = 0;
	while (i < g_op_tab[num].args)
	{
		code = (arg >> (6 - i * 2)) & 0x03;
		debug_arg2(code, num, &pc);
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
}

void	debug_arg2(unsigned char code, unsigned num, unsigned *pc)
{
	if (code == REG_CODE)
	{
		printf(A23);
		*pc = looped(*pc, 1);
	}
	else if (code == DIR_CODE)
	{
		printf(A24);
		*pc = (g_op_tab[num].dir_is_four ? looped(*pc, 2) :
				looped(*pc, DIR_SIZE));
	}
	else if (code == IND_CODE)
	{
		printf(A25);
		*pc = looped(*pc, IND_SIZE);
	}
	else
		printf(A22);
}

void	debug_arg_value(unsigned char arg, unsigned pc,
			unsigned num, t_arena *arena)
{
	size_t			i;
	unsigned char	code;

	i = 0;
	while (i < g_op_tab[num].args)
	{
		code = (arg >> (6 - i * 2)) & 0x03;
		debug_arg_value2(code, num, &pc, arena);
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
}

void	debug_arg_value2(unsigned char code, unsigned num,
		unsigned *pc, t_arena *arena)
{
	if (code == REG_CODE)
	{
		printf("r%u", *((unsigned char *)arena->field + *pc));
		*pc = looped(*pc, 1);
	}
	else if (code == DIR_CODE)
	{
		printf("%02x%02x", *((unsigned char *)arena->field + looped(*pc, 0)),
				*((unsigned char *)arena->field + looped(*pc, 1)));
		if (!g_op_tab[num].dir_is_four)
			printf("%02x%02x", *((unsigned char *)arena->field + looped(*pc,
					2)), *((unsigned char *)arena->field + looped(*pc, 3)));
		*pc = (g_op_tab[num].dir_is_four ? looped(*pc, 2) :
				looped(*pc, DIR_SIZE));
	}
	else if (code == IND_CODE)
	{
		printf("%02x%02x", *((unsigned char *)arena->field + looped(*pc, 0)),
					*((unsigned char *)arena->field + looped(*pc, 1)));
		*pc = looped(*pc, IND_SIZE);
	}
	else
		printf(A22);
}

void	debug_11_14_15(t_cursor *temp, unsigned num, t_debug *deb)
{
	if (num == 11)
	{
		num = get_direct(deb->field, looped(temp->pc, 1), 0) % IDX_MOD;
		printf("created new cursor by fork at %d steps in %u pc",
				num, looped(temp->pc, num));
	}
	else if (num == 14)
	{
		num = get_direct(deb->field, looped(temp->pc, 1), 0);
		printf("created new cursor by lfork at %d steps in %u pc",
				num, looped(temp->pc, num));
	}
	else if (num == 15)
	{
		num = *(temp->registrs + deb->reg - 1);
		printf("r%u (%d) \"%c\" print", deb->reg, num, num);
	}
	else
		printf(A22);
}
