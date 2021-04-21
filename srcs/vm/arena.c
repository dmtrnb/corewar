/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:02:56 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/07 16:45:00 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	say_hello(t_name *name)
{
	unsigned	i;
	t_name		*temp;

	ft_putstr(MSG_INTRO);
	i = 0;
	temp = name;
	while (temp)
	{
		i++;
		ft_printf("* Player %u, weighing %u bytes, \"%s\" (\"%s\") !\n", \
								i, temp->code_size, temp->name, temp->comment);
		temp = temp->next;
	}
}

static void	say_dump(unsigned char *field)
{
	unsigned	i;

	i = 0;
	ft_putstr("0x0000 : ");
	while (i != MEM_SIZE)
	{
		if (i && !(i % COLUMNS))
			ft_printf("\n0x%04x : ", i);
		ft_printf("%02x ", *(field + i));
		i++;
	}
	ft_putstr("\n");
}

static void	say_buy(t_crwr *crwr)
{
	unsigned	i;
	t_name		*temp;

	i = 0;
	temp = crwr->name;
	while (temp)
	{
		i++;
		if ((unsigned)crwr->arena->alive == i)
			ft_printf("Contestant %u, \"%s\", has won !\n", i, temp->name);
		temp = temp->next;
	}
}

void		arena(t_crwr *crwr, t_arena *arena)
{
	say_hello(crwr->name);
	if (!crwr->nbr_cycles)
		return ;
	while (crwr->cursor)
	{
		arena->cycles++;
		arena->cycles_without_check++;
		cycle(crwr);
		if (arena->cycles_without_check == (unsigned)arena->cycles_to_die)
			check(arena, &(crwr->cursor));
		if (arena->cycles_to_die <= 0 || \
			((int)arena->cycles == crwr->nbr_cycles && crwr->opt & 0x20))
			break ;
	}
	if (!crwr->cursor)
		crwr->nbr_cycles = -1;
	if (crwr->nbr_cycles == (int)crwr->arena->cycles)
		say_dump((unsigned char *)crwr->arena->field);
	else
		say_buy(crwr);
}
