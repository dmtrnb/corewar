/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/14 16:45:00 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_trim_label(char *str, t_line *temp)
{
	int		i;
	char	*new_line;
	char	*str2;

	i = 0;
	while (str[i] == temp->line[i])
		i++;
	if (temp->line[i] == '\0')
	{
		ft_strdel(&temp->line);
		return ;
	}
	str2 = ft_strdup(temp->line + i);
	new_line = ft_strtrim(str2);
	ft_strdel(&temp->line);
	temp->line = new_line;
	ft_strdel(&str2);
}

void	ft_valid_label_chars(char *str)
{
	char	*chars;
	int		i;

	chars = ft_strdup(LABEL_CHARS);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(LABEL_CHARS, str[i]) == NULL && str[i] != LABEL_CHAR)
		{
			ft_strdel(&chars);
			ft_error(ERR_LBL_CHAR, NULL);
		}
		i++;
	}
	ft_strdel(&chars);
}

void	ft_labels(t_all *all)
{
	t_line	*temp;
	char	*str;
	char	*old;

	temp = all->inc_list;
	while (temp != NULL)
	{
		if (temp->line[0] != '\0')
		{
			ft_labels2(temp, all, &str, &old);
			if (str != NULL)
			{
				ft_valid_label_chars(str);
				if (ft_labels3(temp, &str, &old) == 1)
					break ;
			}
			if (temp->next == NULL)
				ft_strdel(&old);
		}
		temp = temp->next;
	}
}

void	ft_labels2(t_line *temp, t_all *all, char **str, char **old)
{
	char **mass;

	if (temp->next == NULL)
		*old = ft_strdup(temp->line);
	mass = ft_strsplit_wide(temp->line, ' ');
	ft_check_space_btwn_labels(mass, all, 0, NULL);
	*str = ft_labels_only(mass[0]);
	*str = ft_check_for_tabs_and_trim(*str);
	ft_free_mas(mass);
}

int		ft_labels3(t_line *temp, char **str, char **old)
{
	ft_valid_label_chars(*str);
	if (temp->next == NULL && ft_strcmp(*str, *old) == 0)
	{
		temp->metka = ft_strsplit(*str, LABEL_CHAR);
		ft_strdel(&temp->line);
		ft_strdel(str);
		ft_strdel(old);
		return (1);
	}
	temp->metka = ft_strsplit(*str, LABEL_CHAR);
	ft_trim_label(*str, temp);
	ft_strdel(str);
	return (0);
}
