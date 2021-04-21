/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_and_comment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/10 19:51:20 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_trim(char *line, char *f_qoute)
{
	char *new;
	char *temp;

	if ((new = ft_proc_comment(line, f_qoute)) == NULL)
		temp = ft_strtrim(line);
	else
	{
		temp = ft_strtrim(new);
		ft_strdel(&new);
	}
	return (temp);
}

char	*ft_proc_comment(char *line, char *f_qoute)
{
	char	*temp;
	char	*temp2;
	int		i;
	int		len;

	temp = NULL;
	temp2 = NULL;
	if ((temp = ft_strchr(f_qoute, COMMENT_CHAR)) != NULL ||
			(temp2 = ft_strchr(f_qoute, ALT_COMMENT_CHAR)) != NULL)
	{
		if (temp != NULL && temp2 == NULL)
			i = ft_strlen(temp);
		else if (temp2 != NULL && temp == NULL)
			i = ft_strlen(temp2);
		else
			i = temp > temp2 ? ft_strlen(temp2) : ft_strlen(temp);
		len = ft_strlen(line);
		temp = ft_strnew(len - i + 1);
		temp = ft_strncpy(temp, line, len - i);
		return (temp);
	}
	return (NULL);
}
