/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:13:19 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/07 17:21:31 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	check_code(int fd, t_players *players, unsigned char *buf)
{
	if (!(players->code = (char *)malloc(sizeof(char) * (players->code_size))))
		ft_error(ERR_MALLOC_CODE, -3);
	if (read(fd, players->code, players->code_size) < (int)players->code_size)
		ft_error(ERR_BIG_CODE, -3);
	if (read(fd, buf, 1))
		ft_error(ERR_END_FILE, -3);
}

static void	check_code_size(int fd, unsigned char *buf, t_players *players)
{
	unsigned	size;

	size = 0;
	ft_bzero(buf, 4);
	if (read(fd, buf, SIZE_MAGIC_NULL) < SIZE_MAGIC_NULL)
		ft_error(ERR_READ_EOF, -3);
	size += *(buf + 3);
	size += *(buf + 2) << 8;
	size += *(buf + 1) << 16;
	size += *(buf + 0) << 24;
	if (size > CHAMP_MAX_SIZE)
	{
		ft_printf("Very big code for champion %s from %s (%u bytes "\
	"vs. %u bytes)\n", players->name, players->filename, size, CHAMP_MAX_SIZE);
		exit(-3);
	}
	players->code_size = size;
}

static void	check_name_or_comment(int fd, t_players *players, char isname)
{
	size_t			len;
	char			*buf;

	len = (isname ? PROG_NAME_LENGTH : COMMENT_LENGTH);
	if (!((buf = (char *)malloc(sizeof(char) * (len + 1)))))
		ft_error(ERR_MALLOC_BUFFER, -3);
	ft_bzero(buf, len + 1);
	if (read(fd, buf, len) < (int)len)
		ft_error(ERR_NM_EOF, -3);
	if (isname)
		players->name = ft_strdup(buf);
	else
		players->comment = ft_strdup(buf);
	if (!players->name && !players->comment)
		ft_error(ERR_MALLOC_NAME, -3);
	free(buf);
}

static void	check_magic_or_null(int fd, unsigned char *buf, char ismagic)
{
	unsigned	magic_num;

	ft_bzero(buf, 4);
	magic_num = 0;
	if (read(fd, buf, SIZE_MAGIC_NULL) < SIZE_MAGIC_NULL)
		ft_error(ERR_NUL_EOF, -3);
	magic_num += *(buf + 3);
	magic_num += *(buf + 2) << 8;
	magic_num += *(buf + 1) << 16;
	magic_num += *(buf + 0) << 24;
	if (ismagic && magic_num != COREWAR_EXEC_MAGIC)
		ft_error(ERR_MAGIC, -3);
	if (!ismagic && magic_num != 0x0)
		ft_error(ERR_NULL, -3);
}

void		valid_files(t_players *players)
{
	int				fd;
	t_players		*temp;
	unsigned char	*buf;

	if (!(buf = (unsigned char *)malloc(sizeof(unsigned char) * 4)))
		ft_error(ERR_MALLOC_BUFFER, -3);
	temp = players;
	while (temp)
	{
		if ((fd = open(temp->filename, O_RDONLY)) < 0)
			ft_error(ERR_OPEN, -3);
		check_magic_or_null(fd, buf, 1);
		check_name_or_comment(fd, temp, 1);
		check_magic_or_null(fd, buf, 0);
		check_code_size(fd, buf, temp);
		check_name_or_comment(fd, temp, 0);
		check_magic_or_null(fd, buf, 0);
		check_code(fd, temp, buf);
		if (close(fd) < 0)
			ft_error(ERR_CLOSE, -3);
		temp = temp->next;
	}
	free(buf);
}
