#include "corewar.h"

void		debug_action(t_arena *arena, t_cursor *temp, unsigned num)
{
	printf(A27);
	if (num == 10)
	{
		int				num;
		int				num1;
		int				num2;
		unsigned		pc;
		unsigned char	arg;
		unsigned char	reg;
		unsigned char	*field;

		field = (unsigned char *)arena->field;
		arg = *(field + looped(temp->pc, 1));
		reg = *(field + looped(temp->pc, 2));
		num = *(temp->registrs + reg - 1);
		pc = looped(temp->pc, 3);
		if (arg & 0x20 && arg & 0x10)
		{
			num1 = get_indirect(arena->field, pc, temp->pc);
			printf("r%u (%d) -> (PC (%u) + (at %d steps + ", reg, num, temp->pc, num1);
			pc = looped(pc, 2);
		}
		else if (arg & 0x10)
		{
			num1 = *(temp->registrs + *(field + pc) - 1);
			printf("r%u (%d) -> (PC (%u) + (r%u (%d) + ", reg, num, temp->pc, *(field + pc), num1);
			pc = looped(pc, 1);
		}
		else
		{
			num1 = get_direct(arena->field, pc, 0);
			printf("r%u (%d) -> (PC (%u) + (%d + ", reg, num, temp->pc, num1);
			pc = looped(pc, 2);
		}
		if (arg & 0x4)
		{
			num2 = *(temp->registrs + *(field + pc) - 1);
			num = looped(temp->pc, (num1 + num2) % IDX_MOD);
			printf("r%u (%d)) %% IDX_MOD = %u -> ", *(field + pc), num2, num);
			pc = looped(pc, 1);
		}
		else
		{
			num2 = get_direct(arena->field, pc, 0);
			num = looped(temp->pc, (num1 + num2) % IDX_MOD);
			printf("%d) %% IDX_MOD = %u == ", num2, num);
			pc = looped(pc, 2);
		}
		printf("%02x%02x%02x%02x", (num >> 24) & 0xff, (num >> 16) & 0xff, (num >> 8) & 0xff, (num >> 0) & 0xff);
		printf(" -> \"%02x%02x%02x%02x\"", *(field + looped(num, 0)), *(field + looped(num, 1)), *(field + looped(num, 2)), *(field + looped(num, 3)));
	}
	if (num == 0)
	{
		int	live;

		live = get_direct(arena->field, looped(temp->pc, 1), 1);
		live = ~live + 1;
		if (live == ((temp->id >> 27) & 0xf))
			printf("players %d alive + ", live);
		printf("cursor %u alive", temp->id & 0x7ffffff);
	}
	else if (num == 1)
	{
		int				num;
		unsigned char	arg;
		unsigned char	reg;

		arg = *((unsigned char *)arena->field + looped(temp->pc, 1));
		if (arg & 0x40)
			num = get_indirect(arena->field, looped(temp->pc, 2), temp->pc);
		else
			num = get_direct(arena->field, looped(temp->pc, 2), 1);
		reg = *((unsigned char *)arena->field + looped(temp->pc, (arg & 0x40 ? 4 : 6)));
		printf("%d -> r%u + carry -> %d", num, reg, (num ? 0 : 1));
	}
	else if (num == 2)
	{
		int				num;
		unsigned char	arg;
		unsigned char	reg;
		unsigned char	*field;

		field = (unsigned char *)arena->field;
		arg = *(field + looped(temp->pc, 1));
		reg = *(field + looped(temp->pc, 2));
		num = *(temp->registrs + reg - 1);
		if (arg & 0x20)
		{
			printf("r%u (%02x%02x%02x%02x) -> ", reg, (num >> 24) & 0xff, (num >> 16) & 0xff, (num >> 8) & 0xff, (num >> 0) & 0xff);
			num = get_direct(field, looped(temp->pc, 3), 0) % IDX_MOD;
			printf("at %d steps \"%02x%02x%02x%02x\"", num, *(field + looped(temp->pc, num + 0)), *(field + looped(temp->pc, num + 1)), *(field + looped(temp->pc, num + 2)), *(field + looped(temp->pc, num + 3)));
		}
		else
		{
			printf("r%u (%d) -> ", reg, num);
			reg = *(field + looped(temp->pc, 3));
			printf("r%u", reg);
		}
	}
	else if (num == 3)
	{
		int				num1;
		int				num2;
		unsigned char	r1;
		unsigned char	r2;
		unsigned char	r3;
		unsigned char	*field;

		field = (unsigned char *)arena->field;
		r1 = *(field + looped(temp->pc, 2));
		r2 = *(field + looped(temp->pc, 3));
		r3 = *(field + looped(temp->pc, 4));
		num1 = *(temp->registrs + r1 - 1);
		num2 = *(temp->registrs + r2 - 1);
		printf("r%u (%d) + r%u (%d) -> r%u = %d + carry -> %d", r1, num1, r2, num2, r3, num1 + num2, (num1 + num2 ? 0 : 1));
	}
	else if (num == 4)
	{
		int				num1;
		int				num2;
		unsigned char	r1;
		unsigned char	r2;
		unsigned char	r3;
		unsigned char	*field;

		field = (unsigned char *)arena->field;
		r1 = *(field + looped(temp->pc, 2));
		r2 = *(field + looped(temp->pc, 3));
		r3 = *(field + looped(temp->pc, 4));
		num1 = *(temp->registrs + r1 - 1);
		num2 = *(temp->registrs + r2 - 1);
		printf("r%u (%d) - r%u (%d) -> r%u = %d + carry -> %d", r1, num1, r2, num2, r3, num1 - num2, (num1 - num2 ? 0 : 1));
	}
	else if (num == 5)
	{
		int				num1;
		int				num2;
		unsigned		pc;
		unsigned char	arg;
		unsigned char	reg;
		unsigned char	*field;

		field = (unsigned char *)arena->field;
		arg = *(field + looped(temp->pc, 1));
		if (arg & 0x80 && arg & 0x40)
		{
			num1 = get_direct(arena->field, looped(temp->pc, 2), 0);
			printf("at %d steps ", num1);
			num1 = get_indirect(arena->field, looped(temp->pc, 2), temp->pc);
			printf("(%x) AND ", num1);
			pc = looped(temp->pc, 4);
		}
		else if (arg & 0x80)
		{
			num1 = get_direct(arena->field, looped(temp->pc, 2), 1);
			printf("%x AND ", num1);
			pc = looped(temp->pc, 6);
		}
		else
		{
			reg = *(field + looped(temp->pc, 2));
			num1 = *(temp->registrs + reg - 1);
			printf("r%u (%x) AND ", reg, num1);
			pc = looped(temp->pc, 3);
		}
		if (arg & 0x20 && arg & 0x10)
		{
			num2 = get_direct(arena->field, pc, 0);
			printf("at %d steps ", num2);
			num2 = get_indirect(arena->field, pc, temp->pc);
			printf("(%x)", num2);
			pc = looped(pc, 2);
		}
		else if (arg & 0x20)
		{
			num2 = get_direct(arena->field, pc, 1);
			printf("%x", num2);
			pc = looped(pc, 4);
		}
		else
		{
			reg = *(field + pc);
			num2 = *(temp->registrs + reg - 1);
			printf("r%u (%x)", reg, num2);
			pc = looped(pc, 1);
		}
		reg = *(field + pc);
		printf(" -> r%u = %d + carry -> %d", reg, num1 & num2, (num1 & num2 ? 0 : 1));
	}
	else if (num == 6)
	{
		int				num1;
		int				num2;
		unsigned		pc;
		unsigned char	arg;
		unsigned char	reg;
		unsigned char	*field;

		field = (unsigned char *)arena->field;
		arg = *(field + looped(temp->pc, 1));
		if (arg & 0x80 && arg & 0x40)
		{
			num1 = get_direct(arena->field, looped(temp->pc, 2), 0);
			printf("at %d steps ", num1);
			num1 = get_indirect(arena->field, looped(temp->pc, 2), temp->pc);
			printf("(%x) OR ", num1);
			pc = looped(temp->pc, 4);
		}
		else if (arg & 0x80)
		{
			num1 = get_direct(arena->field, looped(temp->pc, 2), 1);
			printf("%x OR ", num1);
			pc = looped(temp->pc, 6);
		}
		else
		{
			reg = *(field + looped(temp->pc, 2));
			num1 = *(temp->registrs + reg - 1);
			printf("r%u (%x) OR ", reg, num1);
			pc = looped(temp->pc, 3);
		}
		if (arg & 0x20 && arg & 0x10)
		{
			num2 = get_direct(arena->field, pc, 0);
			printf("at %d steps ", num2);
			num2 = get_indirect(arena->field, pc, temp->pc);
			printf("(%x)", num2);
			pc = looped(pc, 2);
		}
		else if (arg & 0x20)
		{
			num2 = get_direct(arena->field, pc, 1);
			printf("%x", num2);
			pc = looped(pc, 4);
		}
		else
		{
			reg = *(field + pc);
			num2 = *(temp->registrs + reg - 1);
			printf("r%u (%x)", reg, num2);
			pc = looped(pc, 1);
		}
		reg = *(field + pc);
		printf(" -> r%u = %d + carry -> %d", reg, num1 | num2, (num1 | num2 ? 0 : 1));
	}
	else if (num == 7)
	{
		int				num1;
		int				num2;
		unsigned		pc;
		unsigned char	arg;
		unsigned char	reg;
		unsigned char	*field;

		field = (unsigned char *)arena->field;
		arg = *(field + looped(temp->pc, 1));
		if (arg & 0x80 && arg & 0x40)
		{
			num1 = get_direct(arena->field, looped(temp->pc, 2), 0);
			printf("at %d steps ", num1);
			num1 = get_indirect(arena->field, looped(temp->pc, 2), temp->pc);
			printf("(%x) XOR ", num1);
			pc = looped(temp->pc, 4);
		}
		else if (arg & 0x80)
		{
			num1 = get_direct(arena->field, looped(temp->pc, 2), 1);
			printf("%x XOR ", num1);
			pc = looped(temp->pc, 6);
		}
		else
		{
			reg = *(field + looped(temp->pc, 2));
			num1 = *(temp->registrs + reg - 1);
			printf("r%u (%x) XOR ", reg, num1);
			pc = looped(temp->pc, 3);
		}
		if (arg & 0x20 && arg & 0x10)
		{
			num2 = get_direct(arena->field, pc, 0);
			printf("at %d steps ", num2);
			num2 = get_indirect(arena->field, pc, temp->pc);
			printf("(%x)", num2);
			pc = looped(pc, 2);
		}
		else if (arg & 0x20)
		{
			num2 = get_direct(arena->field, pc, 1);
			printf("%x", num2);
			pc = looped(pc, 4);
		}
		else
		{
			reg = *(field + pc);
			num2 = *(temp->registrs + reg - 1);
			printf("r%u (%x)", reg, num2);
			pc = looped(pc, 1);
		}
		reg = *(field + pc);
		printf(" -> r%u = %d + carry -> %d", reg, num1 ^ num2, (num1 ^ num2 ? 0 : 1));
	}
	else if (num == 8)
	{
		int		num;

		if (temp->id & 0x80000000)
		{
			num = get_direct(arena->field, looped(temp->pc, 1), 0) % IDX_MOD;
			printf("Jumping at %02x%02x (%d) steps -> %u pc", *((unsigned char *)arena->field + looped(temp->pc, 1)), *((unsigned char *)arena->field + looped(temp->pc, 2)), num, looped(temp->pc, num));
		}
		else
			printf("Not jump. pc(%u)->new_pc(%u)", temp->pc, looped(temp->pc, 3));
	}
	else if (num == 9)
	{
		int				num1;
		int				num2;
		unsigned		pc;
		unsigned char	arg;
		unsigned char	reg;
		unsigned char	*field;

		field = (unsigned char *)arena->field;
		arg = *(field + looped(temp->pc, 1));
		pc = looped(temp->pc, 2);
		if (arg & 0x80 && arg & 0x40)
		{
			num1 = get_indirect(arena->field, pc, temp->pc);
			printf("(PC (%u) + (at %02x%02x steps (%d) +", temp->pc, *(field + pc), *(field + looped(pc, 1)), num1);
			pc = looped(pc, 2);
		}
		else if (arg & 0x40)
		{
			reg = *(field + pc);
			num1 = *(temp->registrs + reg - 1);
			printf("(PC (%u) + (r%u (%d) +", temp->pc, reg, num1);
			pc = looped(pc, 1);
		}
		else
		{
			num1 = get_direct(arena->field, pc, 0);
			printf("(PC (%u) + (%d +", temp->pc, num1);
			pc = looped(pc, 2);
		}
		if (arg & 0x10)
		{
			reg = *(field + pc);
			num2 = *(temp->registrs + reg - 1);
			printf(" r%u (%d)) %% IDX_MOD) = ", reg, num2);
			pc = looped(pc, 1);
		}
		else
		{
			num2 = get_direct(arena->field, pc, 0);
			printf(" %d) %% IDX_MOD) = ", num2);
			pc = looped(pc, 2);
		}
		reg = *(field + pc);
		num1 = looped(temp->pc, (num1 + num2) % IDX_MOD);
		num2 = get_direct(arena->field, num1, 1);
		printf("%d ==== %02x%02x%02x%02x -> r%u", num1, (num2 >> 24) & 0xff, (num2 >> 16) & 0xff, (num2 >> 8) & 0xff, (num2 >> 0) & 0xff, reg);
	}
	else if (num == 11)
	{
		int		num;

		num = get_direct(arena->field, looped(temp->pc, 1), 0) % IDX_MOD;
		printf("created new cursor by fork at %d steps in %u pc", num, looped(temp->pc, num));
	}
	else if (num == 12)
	{
		int				num;
		unsigned char	arg;
		unsigned char	reg;

		arg = *((unsigned char *)arena->field + looped(temp->pc, 1));
		if (arg & 0x40)
		{
			num = get_direct(arena->field, looped(temp->pc, 2), 0);
			num = get_direct(arena->field, looped(temp->pc, num), 1);
		}
		else
			num = get_direct(arena->field, looped(temp->pc, 2), 1);
		reg = *((unsigned char *)arena->field + looped(temp->pc, (arg & 0x40 ? 4 : 6)));
		printf("%d -> r%u + carry -> %d", num, reg, (num ? 0 : 1));
	}
	else if (num == 13)
	{
		int				num1;
		int				num2;
		unsigned		pc;
		unsigned char	arg;
		unsigned char	reg;
		unsigned char	*field;

		field = (unsigned char *)arena->field;
		arg = *(field + looped(temp->pc, 1));
		pc = looped(temp->pc, 2);
		if (arg & 0x80 && arg & 0x40)
		{
			num1 = get_indirect(arena->field, pc, temp->pc);
			printf("(PC (%u) + (at %02x%02x steps (%d) +", temp->pc, *(field + pc), *(field + looped(pc, 1)), num1);
			pc = looped(pc, 2);
		}
		else if (arg & 0x40)
		{
			reg = *(field + pc);
			num1 = *(temp->registrs + reg - 1);
			printf("(PC (%u) + (r%u (%d) +", temp->pc, reg, num1);
			pc = looped(pc, 1);
		}
		else
		{
			num1 = get_direct(arena->field, pc, 0);
			printf("(PC (%u) + (%d +", temp->pc, num1);
			pc = looped(pc, 2);
		}
		if (arg & 0x10)
		{
			reg = *(field + pc);
			num2 = *(temp->registrs + reg - 1);
			printf(" r%u (%d))) = ", reg, num2);
			pc = looped(pc, 1);
		}
		else
		{
			num2 = get_direct(arena->field, pc, 0);
			printf(" %d)) = ", num2);
			pc = looped(pc, 2);
		}
		reg = *(field + pc);
		num1 = looped(temp->pc, num1 + num2);
		num2 = get_direct(arena->field, num1, 1);
		printf("%d ==== %02x%02x%02x%02x -> r%u + carry -> %d", num1, (num2 >> 24) & 0xff, (num2 >> 16) & 0xff, (num2 >> 8) & 0xff, (num2 >> 0) & 0xff, reg, (num2 ? 0 : 1));
	}
	else if (num == 14)
	{
		int		num;

		num = get_direct(arena->field, looped(temp->pc, 1), 0);
		printf("created new cursor by lfork at %d steps in %u pc", num, looped(temp->pc, num));
	}
	else if (num == 15)
	{
		int				num;
		unsigned char	reg;

		reg = *((unsigned char *)arena->field + looped(temp->pc, 2));
		num = *(temp->registrs + reg - 1);
		printf("r%u (%d) \"%c\" print", reg, num, num);
	}
	printf(A21);
}

void		debug(t_arena *arena, t_cursor *temp, unsigned num)
{
	printf(A1"%u"A21, arena->cycles);
	printf(A5"%u"A21, temp->id & 0x7ffffff);
	printf(A2"%u"A21, arena->alive);
	printf(A3"%u"A21, arena->nbr_live);
	printf(A4"%d"A21, arena->cycles_to_die);
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
			pc = (g_op_tab[num].dir_is_four ? looped(pc, 2) : looped(pc, DIR_SIZE));
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
			printf("r%u", *((unsigned char *)arena->field + pc));
			pc = looped(pc, 1);
		}
		else if (code == DIR_CODE)
		{
			printf("%02x%02x", *((unsigned char *)arena->field + looped(pc, 0)), *((unsigned char *)arena->field + looped(pc, 1)));
			if (!g_op_tab[num].dir_is_four)
				printf("%02x%02x", *((unsigned char *)arena->field + looped(pc, 2)), *((unsigned char *)arena->field + looped(pc, 3)));
			pc = (g_op_tab[num].dir_is_four ? looped(pc, 2) : looped(pc, DIR_SIZE));
		}
		else if (code == IND_CODE)
		{
			printf("%02x%02x", *((unsigned char *)arena->field + looped(pc, 0)), *((unsigned char *)arena->field + looped(pc, 1)));
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
	debug_action(arena, temp, num);
	getchar();
}

