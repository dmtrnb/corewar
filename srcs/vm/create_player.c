/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 18:45:10 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/07 14:20:29 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		set_free_pl(t_players *list, char *str)
{
	t_players	*temp;

	temp = list;
	while (temp && temp->filename)
		temp = temp->next;
	if (temp)
		temp->filename = ft_strdup(str);
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
			ft_error(ERR_NUM_PL_EXISTS, -1);
		temp->filename = ft_strdup(str);
	}
}

static void		set_free_players(int ac, char **av, t_players *players)
{
	int		i;

	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(*(av + i), OPT_B) || !ft_strcmp(*(av + i), OPT_D))
			i += 2;
		else if (!ft_strcmp(*(av + i), OPT_V) || !ft_strcmp(*(av + i), OPT_A) \
				|| !ft_strcmp(*(av + i), OPT_S) || !ft_strcmp(*(av + i), OPT_F))
			i++;
		else if (!ft_strcmp(*(av + i), OPT_N))
			i += 3;
		else
		{
			set_free_pl(players, *(av + i));
			i++;
		}
	}
}

void			fix_created_players(int ac, char **av, t_players *players, \
																	int count)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(*(av + i), OPT_B) || !ft_strcmp(*(av + i), OPT_D))
			i += 2;
		else if (!ft_strcmp(*(av + i), OPT_V) || !ft_strcmp(*(av + i), OPT_A) \
				|| !ft_strcmp(*(av + i), OPT_S) || !ft_strcmp(*(av + i), OPT_F))
			i++;
		else if (!ft_strcmp(*(av + i), OPT_N))
		{
			j = ft_is_int(*(av + i + 1));
			if (j <= 0 || j > MAX_PLAYERS || j > count)
				ft_error(ERR_NUM_PL_CANT, -1);
			find_set_id_pl(players, j, *(av + i + 2));
			i += 3;
		}
		else
			i++;
	}
	set_free_players(ac, av, players);
}
