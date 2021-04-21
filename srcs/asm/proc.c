/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/14 16:48:36 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_keep_read(t_all *all, char *temp, int flag, int s)
{
	char *buf;
	char *new;
	char *temp2;
	char *check;

	new = ft_strdup(temp);
	while ((check = ft_strchr(new, '"')) == NULL)
	{
		if (get_next_line(all->fd, &buf) <= 0)
			ft_error(ERR_FD, NULL);
		temp2 = new;
		new = ft_strjoin3(new, "\n", buf);
		ft_strdel(&temp2);
		ft_strdel(&buf);
	}
	temp2 = ft_trim(check + 1, check + 1);
	if (temp2[0] != '\0')
		ft_error(ERR_BAD_NAME, NULL);
	check[0] = '\0';
	if (ft_strlen(new) > (size_t)s)
		ft_error(ERR_BIG_NAME, NULL);
	ft_keep_read2(all, new, flag);
	check[0] = '"';
	ft_strdel(&temp2);
}

void	ft_keep_read2(t_all *all, char *new, int flag)
{
	if (flag == 1)
		all->name = ft_create(ft_strdup(new));
	else
		all->comment = ft_create(ft_strdup(new));
	ft_strdel(&new);
}

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = 0;
	if (!(s1 && s2 && s3))
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	k = ft_strlen(s3);
	str = (char*)malloc(sizeof(char) * (i + j + k + 1));
	if (!(str))
		return (NULL);
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	str = ft_strcat(str, s3);
	return (str);
}

void	ft_check_len(t_line *new, int flag)
{
	int s;

	s = flag != 1 ? COMMENT_LENGTH : PROG_NAME_LENGTH;
	if (ft_strlen(new->line) > (size_t)s)
		ft_error(ERR_LENGHT, NULL);
}

char	*ft_copy_name_com(char *f, char *s)
{
	int		len;
	char	*new;

	len = ft_strlen(f) - ft_strlen(s) - 1;
	new = ft_strnew(len + 1);
	new = ft_strncpy(new, f + 1, len);
	return (new);
}
