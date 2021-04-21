/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_file_spec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/02/26 16:58:18 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_write_magic(int fd)
{
	char *new;
	char *temp;

	new = ft_convert(COREWAR_EXEC_MAGIC, 16, 2);
	temp = ft_add_null(new, 8);
	ft_str_to_byte(temp, fd);
	ft_strdel(&temp);
}

void	ft_write_name(int fd, char *str, int big_len)
{
	int		i;
	char	c;
	int		len;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		write(fd, &c, 1);
		i++;
	}
	len = ft_strlen(str);
	len = big_len - len;
	i = 0;
	while (i < len)
	{
		c = '\0';
		write(fd, &c, 1);
		i++;
	}
}

void	ft_write_size(int fd, int size)
{
	char *new;
	char *temp;

	new = ft_convert(size, 16, 2);
	temp = ft_add_null(new, 8);
	ft_str_to_byte(temp, fd);
	ft_strdel(&temp);
}

void	ft_write_code(t_all *all, int fd)
{
	t_line *temp;

	temp = all->inc_list;
	while (temp != NULL)
	{
		ft_str_to_byte(temp->ans, fd);
		temp = temp->next;
	}
}

void	ft_write_null(int fd)
{
	int		i;
	char	c;

	i = 0;
	while (i < 4)
	{
		c = '\0';
		write(fd, &c, 1);
		i++;
	}
}
