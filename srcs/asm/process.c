/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/14 16:48:48 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_process(char *line, t_all *all)
{
	char	*new;
	char	*temp;
	int		k;
	int		i;

	if ((new = ft_afterspace(line)) == NULL)
		return ;
	if (ft_strncmp(new, NAME_CMD_STRING, (i = ft_strlen(NAME_CMD_STRING))) == 0)
		ft_proc_name_com(all, new, 1, i);
	else if (ft_strncmp(new, COMMENT_CMD_STRING,
			(i = ft_strlen(COMMENT_CMD_STRING))) == 0)
		ft_proc_name_com(all, new, 5, i);
	else
	{
		temp = ft_trim(new, new);
		k = ft_strlen(temp);
		if (k)
		{
			if (temp[k - 1] == LABEL_CHAR)
				ft_proc_metka(all, temp);
			else if (k != 0)
				ft_add_inc(all, ft_strdup(temp));
		}
		ft_strdel(&temp);
	}
}

void	ft_proc_name_com(t_all *all, char *line, int flag, int i)
{
	char	*new;
	int		s;

	if (flag == 1 && all->name != NULL)
		ft_error(ERR_DBL_NAME, NULL);
	else if (flag == 5 && all->comment != NULL)
		ft_error(ERR_DBL_CMT, NULL);
	new = ft_afterspace(line + i);
	if (new == NULL || new[0] != '"')
		ft_error(ERR_NO_NAME_CMT, NULL);
	else
	{
		s = flag != 1 ? COMMENT_LENGTH : PROG_NAME_LENGTH;
		ft_proc_name_com2(all, flag, new, s);
	}
}

void	ft_proc_name_com2(t_all *all, int flag, char *new, int s)
{
	char	*temp;
	char	*temp2;

	if ((temp = ft_strchr(new + 1, '"')) == NULL)
		ft_keep_read(all, new + 1, flag, s);
	else
	{
		if ((temp2 = ft_afterspace(temp + 1)) != NULL)
		{
			if (temp2[0] != COMMENT_CHAR && temp2[0] != ALT_COMMENT_CHAR)
				ft_error(ERR_CMT, NULL);
		}
		if (flag == 1)
		{
			all->name = ft_create(ft_copy_name_com(new, temp));
			ft_check_len(all->name, flag);
		}
		else
		{
			all->comment = ft_create(ft_copy_name_com(new, temp));
			ft_check_len(all->comment, flag);
		}
	}
}

void	ft_add_inc(t_all *all, char *line)
{
	t_line *new;
	t_line *temp;

	new = ft_create(line);
	temp = all->inc_list;
	if (temp != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
	else
	{
		all->inc_list = new;
	}
}
