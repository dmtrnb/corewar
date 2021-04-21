/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/07 15:53:18 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

int		file_len(char *filename)
{
	int		fd;
	int		len;
	int		r;
	char	buff;

	if ((fd = open(filename, O_RDONLY)))
	{
		len = 0;
		while ((r = read(fd, &buff, 1)) == 1)
			len++;
		close(fd);
		if (r == 0)
			return (len);
	}
	ft_exit(ERR_FILE_EXIST);
	return (0);
}

void	*read_file(char *filename, int *size)
{
	int		r;
	int		fd;
	char	*buf;

	*size = file_len(filename);
	buf = ft_memalloc(*size + 1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_exit(ERR_RD_FILE);
	r = read(fd, buf, *size);
	close(fd);
	if (r > MEM_SIZE)
		ft_exit(ERR_SIZE);
	else if (r == *size)
		return (buf);
	else
		ft_exit(ERR_PROG_SIZE);
	return (0);
}

void	ft_read_name_comment(t_all *all)
{
	int		r;
	char	*buf;

	all->fd = open(all->file_s, O_WRONLY | O_CREAT, 0777);
	buf = (char*)malloc(sizeof(char) * (COMMENT_LENGTH + 1));
	r = read(all->fd, buf, 4);
	buf[r] = '\0';
	ft_bzero((void*)buf, COMMENT_LENGTH + 1);
	if ((r = read(all->fd, buf, PROG_NAME_LENGTH)) < 0)
		ft_exit(ERR_RD_FILE);
	all->name = ft_strdup(buf);
	ft_printf("r=%i\nname=%s\n", r, all->name);
	all->comment = ft_strnew((COMMENT_LENGTH + 1));
	r = read(all->fd, all->comment, 8);
	r = read(all->fd, all->comment, COMMENT_LENGTH);
	if (r < COMMENT_LENGTH)
		ft_exit(ERR_CMT_SIZE);
	ft_printf("r=%i\ncomment=%s\n", r, all->comment);
	close(all->fd);
}

void	ft_write_name_comment(t_all *all)
{
	int	output;

	output = all->flag.p == 1 ? 0 : all->fd;
	ft_putstr_fd(".name	\"", output);
	ft_putstr_fd(all->magic->prog_name, output);
	ft_putstr_fd("\"\n", output);
	ft_putstr_fd(".comment \"", output);
	ft_putstr_fd(all->magic->comment, output);
	ft_putstr_fd("\"\n\n", output);
}

void	ft_cmp_inc(t_all *all, char *str, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while ((unsigned long)j < sizeof(g_optab) / sizeof(t_op))
		{
			if (str[i] == g_optab[j].num)
			{
				i += ft_write_inc(&str[i], g_optab[j], all);
				break ;
			}
			j++;
		}
		if ((unsigned long)j >= (sizeof(g_optab) / sizeof(t_op)) - 1)
			ft_exit(ERR_INC);
	}
}
