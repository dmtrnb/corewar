/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_valid_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 14:37:40 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/07 16:39:08 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			check(t_arena *arena, t_cursor **cursor)
{
	t_cursor	*temp;

	temp = *cursor;
	while (temp)
		temp = (arena->cycles - temp->last_live >= \
	(unsigned)arena->cycles_to_die ? ft_cursor_del(cursor, &temp) : temp->next);
	arena->nbr_check++;
	if (arena->nbr_live >= NBR_LIVE || arena->nbr_check >= MAX_CHECKS)
	{
		arena->cycles_to_die -= CYCLE_DELTA;
		arena->nbr_check = 0;
	}
	arena->nbr_live = 0;
	arena->cycles_without_check = 0;
}

unsigned		count_of_cursor(t_cursor *cursor)
{
	unsigned	count;
	t_cursor	*temp;

	count = 0;
	temp = cursor;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

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

int				ft_is_int(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (*(str + i) && ft_isdigit(*(str + i)))
		i++;
	if (*(str + i))
		return (-1);
	return (ft_atoi(str));
}
