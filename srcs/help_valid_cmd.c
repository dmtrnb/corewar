/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_valid_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:37:40 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/04 15:38:47 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned		ft_players_count(t_players *list)
{
	unsigned	count;
	t_players	*temp;

	count = 0;
	temp = list;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

static void		set_free_pl(t_players *list, char *str)
{
	t_players	*temp;

	temp = list;
	while (temp && temp->filename)
		temp = temp->next;
	if (temp)
		temp->filename = strdup(str);
}

static void		find_set_id_pl(t_players *list, int num, char *str)
{
	t_players	*temp;

	temp = list;
	while (temp && temp->id != num)
		temp = temp->next;
	if (temp)
	{
		if (temp->filename)
			ft_error("Player with this number already exist", -1);
		temp->filename = strdup(str);
	}
}

void			fix_created_players(int ac, char **av, t_players *players, \
																	int i)
{
	int		j;
	int		k;
	int		count;

	j = i;
	count = ft_players_count(players);
	while (i < ac)
		if (!strcmp(*(av + i), OPT_N))
		{
			k = ft_is_int(*(av + i + 1));
			if (k <= 0 || k > MAX_PLAYERS || k > count)
				ft_error("Player with such number cannot exist", -1);
			find_set_id_pl(players, k, *(av + i + 2));
			i += 3;
		}
		else
			i++;
	while (j < ac)
		if (!strcmp(*(av + j), OPT_N))
			j += 3;
		else if (!strcmp(*(av + j), OPT_A))
			j++;
		else
		{
			(strcmp(av[j], OPT_V) ? set_free_pl(players, av[j]) : NULL);
			j++;
		}
}
