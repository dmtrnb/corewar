/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:39:00 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/27 19:42:14 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		main(int ac, char **av)
{
	t_crwr		*crwr;

	valid_command(ac, av, &crwr);
	valid_files(crwr->players);
	crwr->arena = init_arena(crwr->players->id);
	crwr->cursor = fill_arena(crwr);
	crwr->name = free_players(&crwr);
//	printf("%u %u\n", crwr->arena->cycles, crwr->arena->cycles_without_check);
	arena(crwr, crwr->arena, crwr->cursor);
//	printf("%u %u\n", crwr->arena->cycles, crwr->arena->cycles_without_check);
//	printf("%u %u\n", crwr->arena->nbr_check, crwr->arena->cycles_to_die);
//	free_crwr(&crwr);
//	free_cursor(&cursor);
	return (0);
}
