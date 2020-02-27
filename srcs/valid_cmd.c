/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:01:59 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/27 17:06:55 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				ft_is_int(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (*(str + i) && isdigit(*(str + i)))	// FT
		i++;
	if (*(str + i))
		return (-1);
	return (atoi(str));	// FT
}

static int		count_players(int ac, char **av, int i)
{
	int	count;

	count = 0;
	while (i < ac)
		if (!strcmp(*(av + i), OPT_N))	// FT
		{
			i += 2;
			if (i >= ac || !strcmp(*(av + i), OPT_N))	// FT
				ft_error("Wrong number of parameters", -1);
		}
		else if (!strcmp(*(av + i), OPT_V))	// FT
			i++;
		else
		{
			i++;
			count++;
		}
	return (count);
}

static void		ft_players_add_last(t_players **alst, t_players *new)
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
			ft_error("Problem with malloc for player", -1);
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

void				valid_command(int ac, char **av, t_crwr **crwr)
{
	int		i;
	int		n;

	if (ac == 1)
		ft_error("Usage: ./corewar <champion1.cor> <...>", -1);
	if (!(*crwr = (t_crwr *)malloc(sizeof(t_crwr))))
		ft_error("Error of malloc memory", -1);
	(*crwr)->opt = 0;
	i = 0;
	while (++i != ac)
		(*crwr)->opt |= (strcmp(*(av + i), OPT_V) ? 0 : 0x80);	// FT
	i = 0;
	while (++i != ac)
		(*crwr)->opt |= (strcmp(*(av + i), OPT_A) ? 0 : 0x08);	// FT
	i = 1;
	if (!strcmp(*(av + 1), OPT_DUMP))	// FT
	{
		if (ac <= 2 || ((*crwr)->nbr_cycles = ft_is_int(*(av + 2))) < 0)
			ft_error("Wrong cycle number", -1);
		i = 3;
	}
	else
		(*crwr)->nbr_cycles = -1;
	if ((n = count_players(ac, av, i)) > MAX_PLAYERS || !n)
		ft_error("Too much players", -1);
	(*crwr)->name = NULL;
	(*crwr)->cursor = NULL;
	(*crwr)->arena = NULL;
	(*crwr)->players = create_players(n);
	fix_created_players(ac, av, (*crwr)->players, i);
}
