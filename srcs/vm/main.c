/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 13:39:00 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/07 16:47:02 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			main(int ac, char **av)
{
	t_crwr		*crwr;

	valid_command(ac, av, &crwr);
	valid_files(crwr->players);
	crwr->arena = init_arena(crwr->players->id);
	crwr->cursor = fill_arena(crwr, 0);
	crwr->name = free_players(&crwr);
	crwr->arena->visu = (crwr->opt & 0x80 ? get_visu(crwr) : crwr->arena->visu);
	(crwr->opt & 0x80 ? visu_arena(crwr, crwr->arena, crwr->arena->visu) : \
													arena(crwr, crwr->arena));
	free_all(crwr);
	return (0);
}
