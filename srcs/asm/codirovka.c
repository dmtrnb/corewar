/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codirovka.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/07 15:37:30 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_codirovka(t_all *all)
{
	t_line	*temp;
	int		i;

	temp = all->inc_list;
	while (temp != NULL)
	{
		if (temp->line != NULL)
		{
			all->size += temp->size;
			i = 0;
			ft_some(temp);
			while (temp->arg[i] != NULL)
			{
				ft_arg(temp, temp->arg[i]);
				i++;
			}
		}
		temp = temp->next;
	}
}

void	ft_some(t_line *temp)
{
	char *new;

	new = ft_convert(temp->op, 16, 1);
	temp->ans[0] = temp->op < 16 ? '0' : '\0';
	temp->ans = ft_strcat(temp->ans, new);
	ft_strdel(&new);
	if (temp->cod != 0)
	{
		new = ft_convert(temp->cod, 16, 1);
		temp->ans = ft_strcat(temp->ans, new);
		ft_strdel(&new);
	}
}

void	ft_arg(t_line *temp, char *arg)
{
	char			*new;
	char			f[DIR_SIZE];
	long long int	i;

	f[0] = '0';
	f[1] = '\0';
	if (arg[0] == 'r')
	{
		i = ft_atoi(arg + 1);
		new = ft_convert(i, 16, 1);
		if (i < 16)
			temp->ans = ft_strcat(temp->ans, f);
		temp->ans = ft_strcat(temp->ans, new);
		ft_strdel(&new);
	}
	else if (arg[0] == DIRECT_CHAR)
		ft_arg2(temp, arg + 1, temp->dir);
	else
		ft_arg2(temp, arg, IND_SIZE);
}

void	ft_arg2(t_line *temp, char *arg, int size)
{
	long long int	i;
	char			*new;
	char			*temp1;

	if (arg[0] == LABEL_CHAR)
	{
		ft_search_label(temp, arg, size);
		return ;
	}
	i = ft_atoi(arg);
	new = ft_convert(i, 16, size);
	temp1 = ft_add_null(new, size * 2);
	temp->ans = ft_strcat(temp->ans, temp1);
	ft_strdel(&temp1);
}
