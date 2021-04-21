/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metka.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/07 15:31:11 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_new_with_space(char *new)
{
	char *temp;

	temp = ft_strjoin(" ", new);
	ft_strdel(&new);
	return (temp);
}

void	ft_proc_metka(t_all *all, char *line)
{
	char	*temp;
	char	*new;
	char	*big;
	int		k;

	big = ft_strdup(line);
	while (get_next_line(all->fd, &temp))
	{
		new = ft_trim(temp, temp);
		if ((k = ft_strlen(new)) == 0)
		{
			ft_strdel(&temp);
			ft_strdel(&new);
			continue ;
		}
		big = ft_stepler(big, new);
		ft_strdel(&temp);
		if (new[k - 1] != LABEL_CHAR)
		{
			ft_strdel(&new);
			break ;
		}
		ft_strdel(&new);
	}
	ft_proc_metka2(all, big, temp);
}

void	ft_proc_metka2(t_all *all, char *big, char *temp)
{
	char *new;

	ft_strdel(&temp);
	new = ft_trim(big, big);
	ft_strdel(&big);
	ft_add_inc(all, new);
}

char	*ft_stepler(char *what, char *who)
{
	char	*new;

	new = ft_strjoin(what, who);
	ft_strdel(&what);
	return (new);
}
