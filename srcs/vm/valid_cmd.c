/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:01:59 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/14 15:44:53 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int			count_players(int ac, char **av)
{
	int		i;
	int		count;

	i = 1;
	count = 0;
	while (i < ac)
	{
		if (!ft_strcmp(*(av + i), OPT_N) || !ft_strcmp(*(av + i), OPT_B) || \
												!ft_strcmp(*(av + i), OPT_D))
		{
			i += 2;
			if (i >= ac)
				ft_error(ERR_COUNT_PARAM, -1);
		}
		else if (!ft_strcmp(*(av + i), OPT_V) || !ft_strcmp(*(av + i), OPT_A) \
				|| !ft_strcmp(*(av + i), OPT_S) || !ft_strcmp(*(av + i), OPT_F))
			i++;
		else
		{
			i++;
			count++;
		}
	}
	return (count);
}

static void			ft_players_add_last(t_players **alst, t_players *new)
{
	t_players	*tmp;

	if (*alst && new)
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else if (!(*alst) && new)
		*alst = new;
}

static t_players	*create_players(int n)
{
	int			i;
	t_players	*temp;
	t_players	*list;

	i = 1;
	list = NULL;
	while (i <= n)
	{
		if (!(temp = (t_players *)malloc(sizeof(t_players))))
			ft_error(ERR_MALLOC_PLAYER, -1);
		temp->id = i;
		temp->filename = NULL;
		temp->name = NULL;
		temp->comment = NULL;
		temp->code = NULL;
		temp->code_size = 0;
		temp->next = NULL;
		ft_players_add_last(&list, temp);
		i++;
	}
	return (list);
}

static void			option(t_crwr *crwr, int ac, char **av)
{
	int		i;

	i = 0;
	while (++i != ac)
	{
		crwr->opt |= (ft_strcmp(*(av + i), OPT_V) ? 0 : 0x80);
		crwr->opt |= (ft_strcmp(*(av + i), OPT_D) ? 0 : 0x20);
		crwr->opt |= (ft_strcmp(*(av + i), OPT_A) ? 0 : 0x08);
		crwr->opt |= (ft_strcmp(*(av + i), OPT_S) ? 0 : 0x04);
		crwr->opt |= (ft_strcmp(*(av + i), OPT_B) ? 0 : 0x02);
		crwr->opt |= (ft_strcmp(*(av + i), OPT_F) ? 0 : 0x01);
		if (!ft_strcmp(*(av + i), OPT_D) && (ac <= i + 1 || \
					(crwr->nbr_cycles = ft_is_int(*(av + i + 1))) < 0))
			ft_error(ERR_CYCLE_OPT, -1);
		if (!ft_strcmp(*(av + i), OPT_B) && (ac <= i + 1 || \
					(crwr->nbr_cycles = ft_is_int(*(av + i + 1))) < 0))
			ft_error(ERR_CYCLE_OPT, -1);
	}
	if ((crwr->opt & 0x20 && crwr->opt & 0x02) || \
		(crwr->opt & 0x04 && crwr->opt & 0x01) || ac == 1)
		ft_usage();
	if (crwr->opt & 0x80)
		crwr->opt &= 0x80;
	if (crwr->opt & 0x04 && crwr->opt & 0x02)
		crwr->opt &= 0xfb;
}

void				valid_command(int ac, char **av, t_crwr **crwr)
{
	int		n;

	if (!(*crwr = (t_crwr *)malloc(sizeof(t_crwr))))
		ft_error(ERR_MALLOC_STRUCTURE, -1);
	(*crwr)->nbr_cycles = -1;
	(*crwr)->opt = 0;
	option(*crwr, ac, av);
	if ((n = count_players(ac, av)) > MAX_PLAYERS)
		ft_error(ERR_COUNT_PL, -1);
	if (!n)
		ft_usage();
	(*crwr)->name = NULL;
	(*crwr)->cursor = NULL;
	(*crwr)->arena = NULL;
	(*crwr)->players = create_players(n);
	fix_created_players(ac, av, (*crwr)->players, n);
}
