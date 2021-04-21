/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:40:20 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/04 15:50:46 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_name	*ft_name_new(char *name, char *comment, unsigned code_size)
{
	t_name	*new;

	if (!(new = (t_name *)malloc(sizeof(t_name))))
		return (NULL);
	new->name = name;
	new->comment = comment;
	new->code_size = code_size;
	new->next = NULL;
	return (new);
}

static void		ft_name_add_last(t_name **name, t_name *new)
{
	t_name	*temp;

	if (*name && new)
	{
		temp = *name;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else if (new)
		*name = new;
}

t_name			*free_players(t_crwr **crwr)
{
	t_name		*name;
	t_players	*players;

	name = NULL;
	while ((*crwr)->players)
	{
		players = (*crwr)->players;
		(*crwr)->players = (*crwr)->players->next;
		ft_name_add_last(&name, ft_name_new(players->name, players->comment, \
														players->code_size));
		free(players->filename);
		free(players->code);
		free(players);
	}
	return (name);
}
