/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:02:03 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/06 19:02:46 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	free_name(t_name *name)
{
	t_name	*temp;

	while (name)
	{
		free(name->name);
		name->name = NULL;
		free(name->comment);
		name->comment = NULL;
		temp = name;
		name = name->next;
		free(temp);
		temp = NULL;
	}
}

static void	free_cursor(t_cursor *cursor)
{
	t_cursor	*temp;

	while (cursor)
	{
		temp = cursor;
		cursor = cursor->next;
		free(temp);
		temp = NULL;
	}
}

static void	free_arena(t_arena *arena)
{
	if (arena)
	{
		if (arena->visu)
			free(arena->visu);
		arena->visu = NULL;
		if (arena->field)
			free(arena->field);
		arena->field = NULL;
		if (arena->par_field)
			free(arena->par_field);
		arena->par_field = NULL;
		free(arena);
		arena = NULL;
	}
}

void		free_all(t_crwr *crwr)
{
	if (crwr)
	{
		free_name(crwr->name);
		free_arena(crwr->arena);
		free_cursor(crwr->cursor);
		free(crwr);
		crwr = NULL;
	}
}
