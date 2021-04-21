/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/02/26 17:05:15 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_check_for_tabs_and_trim(char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	if (ft_strchr(str, ' ') != NULL || ft_strchr(str, '\t') != NULL)
	{
		ret = ft_strnew(ft_len(str) + 1);
		while (str[i] != '\0')
		{
			if (str[i] == ' ' || str[i] == '\t')
				i++;
			else
				ret[j++] = str[i++];
		}
		ret[j] = '\0';
		ft_strdel(&str);
		return (ret);
	}
	return (str);
}

void	ft_check_space_btwn_labels(char **mass, t_all *all, int i, char *line)
{
	char	*str;
	char	*temp;

	while (mass[++i] != NULL)
	{
		if (mass[i][ft_strlen(mass[i]) - 1] == LABEL_CHAR &&
					ft_check_label_for_command(str, all) != 0)
		{
			str = ft_strjoin(mass[0], mass[i]);
			ft_strdel(&mass[0]);
			mass[0] = str;
		}
		else
		{
			if (line != NULL)
				temp = ft_strjoin(line, mass[i]);
			else
				temp = ft_strdup(mass[i]);
			if (line != NULL)
				ft_strdel(&line);
			line = temp;
		}
	}
	ft_strdel(&mass[1]);
	mass[1] = line;
}

int		ft_check_label_for_command(char *str, t_all *all)
{
	int i;
	int l;

	i = 0;
	while (all->inc[i] != NULL)
	{
		l = ft_strlen(all->inc[i]);
		if (ft_strncmp(str, all->inc[i], l) == 0 && str[l] == ':')
			return (0);
		i++;
	}
	return (1);
}

int		ft_len(char *str)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
		{
			i++;
			len++;
		}
	}
	return (len);
}
