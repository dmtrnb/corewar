/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:39:00 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/28 19:30:52 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	say_hello(t_name *name)
{
	unsigned	i;
	t_name		*temp;
    
    printf("Introducing contestants...\n");    //    FT
	i = 0;
    temp = name;
    while (temp)
    {
		i++;
        printf("* Player %u, weighing %u bytes, \"%s\" (\"%s\") !\n", i, temp->code_size, temp->name, temp->comment);    //    FT
        temp = temp->next;
    }
}

static void	say_buy(t_crwr *crwr)
{
	unsigned	i;
	t_name		*temp;

	if (crwr->nbr_cycles == (int)crwr->arena->cycles)
	{
		i = 0;
		printf("0x0000 : ");
		while (i != MEM_SIZE)
		{
			if (i && !(i % COLUMNS))
				printf("\n%#06x : ", i);
			printf("%02x ", *((unsigned char *)crwr->arena->field + i));
			i++;
		}
		printf("\n");
	}
	else
	{
		i = 0;
		temp = crwr->name;
		while (temp)
		{
			i++;
			if ((unsigned)crwr->arena->alive == i)
				printf("Contestant %u, \"%s\", has won !\n", i, temp->name);
			temp = temp->next;
		}
	}
}

int		main(int ac, char **av)
{
	t_crwr		*crwr;

	valid_command(ac, av, &crwr);
	valid_files(crwr->players);
	crwr->arena = init_arena(crwr->players->id);
	crwr->cursor = fill_arena(crwr);
	crwr->name = free_players(&crwr);
	(crwr->opt & 0x80 ? NULL : say_hello(crwr->name));
	arena(crwr, crwr->arena);
	(crwr->opt & 0x80 ? NULL : say_buy(crwr));
	pri(crwr->cursor);
	pr(crwr);
	printf("END CYCLES: %u\n", crwr->arena->cycles);
//	free_crwr(&crwr);
//	free_cursor(&cursor);
	return (0);
}
