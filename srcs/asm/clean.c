/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/02/25 19:07:03 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_clean_all(t_all *all)
{
	t_line	*temp;
	t_line	*temp2;
	int		i;

	ft_clean_name_com(all->name);
	ft_clean_name_com(all->comment);
	all->name = NULL;
	all->comment = NULL;
	i = 0;
	while (all->inc[i] != NULL)
	{
		ft_strdel(&all->inc[i]);
		i++;
	}
	temp = all->inc_list;
	while (temp != NULL)
	{
		temp2 = temp->next;
		ft_clean_elem(temp);
		temp = temp2;
	}
	all->inc_list = NULL;
}

void	ft_clean_name_com(t_line *temp)
{
	if (temp != NULL)
	{
		ft_strdel(&temp->line);
		ft_strdel(&temp->ans);
		free(temp);
	}
}

void	ft_clean_elem(t_line *temp)
{
	ft_strdel(&temp->ans);
	if (temp->metka != NULL)
		ft_free_mas(temp->metka);
	if (temp->arg != NULL)
		ft_free_mas(temp->arg);
	ft_strdel(&temp->line);
	free(temp);
}
