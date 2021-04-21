/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/07 15:37:50 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_general_write(t_all *all)
{
	int		fd;
	char	*fname;
	int		len;

	len = ft_strlen(all->file);
	fname = ft_strnew(len + 2);
	fname = ft_strncpy(fname, all->file, len - 2);
	fname = ft_strcat(fname, ".cor");
	fd = open(fname, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	ft_write_magic(fd);
	ft_write_name(fd, all->name->line, PROG_NAME_LENGTH);
	ft_write_null(fd);
	ft_write_size(fd, all->size);
	ft_write_name(fd, all->comment->line, COMMENT_LENGTH);
	ft_write_null(fd);
	ft_write_code(all, fd);
	ft_printf("Writing output program to %s\n", fname);
	ft_strdel(&fname);
}

void	ft_str_to_byte(char *str, int fd)
{
	int				i;
	int				k;
	unsigned char	c;

	i = 0;
	while (str[i] != '\0')
	{
		k = 0;
		if (str[i] >= '0' && str[i] <= '9')
			k = str[i] - '0';
		else
		{
			k = str[i] - 'A' + 10;
		}
		k *= 16;
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			k += str[i + 1] - '0';
		else
		{
			k += str[i + 1] - 'A' + 10;
		}
		i += 2;
		c = k;
		write(fd, &c, 1);
	}
}
