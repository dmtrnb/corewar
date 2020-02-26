/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:40:20 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/26 16:52:38 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_name	*ft_name_new(char *name, char *comment)
{
	t_name	*new;

	if (!(new = (t_name *)malloc(sizeof(t_name))))
		return (NULL);
	new->name = name;
	new->comment = comment;
	new->next = NULL;
	return (new);
}

static void		ft_name_add(t_name **name, t_name *new)
{
	t_name	*temp;

	if (new && !(*name))
		*name = new;
	else if (*name)
	{
		temp = *name;
		new->next = temp;
		*name = new;
	}
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
		ft_name_add(&name, ft_name_new(players->name, players->comment));
		free(players->filename);
		free(players->code);
		free(players);
	}
	return (name);
}
