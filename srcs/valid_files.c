/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:13:19 by nhamill           #+#    #+#             */
/*   Updated: 2020/02/28 14:05:30 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	check_code(int fd, t_players *players, unsigned char *buf)
{
	if (!(players->code = (char *)malloc(sizeof(char) * (players->code_size))))
		ft_error("Problem with malloc for player code", -3);
	if (read(fd, players->code, players->code_size) < (int)players->code_size)
		ft_error("Too long code", -3);
	if (read(fd, buf, 1))
		ft_error("Something wrong with end of file", -3);
}

static void	check_code_size(int fd, unsigned char *buf, t_players *players)
{
	unsigned	size;

	size = 0;
	bzero(buf, 4);	// FT
	if (read(fd, buf, SIZE_MAGIC_NULL) < SIZE_MAGIC_NULL)
		ft_error("File unexpectedly ended while reading size of a champion ", -3);
	size += *(buf + 3);
	size += *(buf + 2) << 8;
	size += *(buf + 1) << 16;
	size += *(buf + 0) << 24;
	if (size > CHAMP_MAX_SIZE)
	{
		printf("Слишком большой код для чемпиона %s from %s", players->name, players->filename); //FT
		exit(-3);	// FT
	}
	players->code_size = size;
}

static void	check_name_or_comment(int fd, t_players *players, char isname)
{
	size_t			len;
	char			*buf;

	len = (isname ? PROG_NAME_LENGTH : COMMENT_LENGTH);
	if (!((buf = (char *)malloc(sizeof(char) * (len + 1)))))
		ft_error("Problem with malloc for buffer for name/comment of champ", -3);
	bzero(buf, len + 1); // FT
	if (read(fd, buf, len) < (int)len)
		ft_error("Unexpected end of file while reading name/comment of champ", -3);
	if (isname)
		players->name = strdup(buf);	// FT
	else
		players->comment = strdup(buf);	// FT
	if (!players->name && !players->comment)
		ft_error("Problem with malloc for name/comment of champ", -3);
	free(buf);
}

static void	check_magic_or_null(int fd, unsigned char *buf, char ismagic)
{
	unsigned	magic_num;

	bzero(buf, 4);	// FT
	magic_num = 0;
	if (read(fd, buf, SIZE_MAGIC_NULL) < SIZE_MAGIC_NULL)
		ft_error("Unexpected end of file while reading MAGIC HEADER or NULL", -3);
	magic_num += *(buf + 3);
	magic_num += *(buf + 2) << 8;
	magic_num += *(buf + 1) << 16;
	magic_num += *(buf + 0) << 24;
	if (ismagic && magic_num != COREWAR_EXEC_MAGIC)
		ft_error("Wrong MAGIC HEADER", -3);
	if (!ismagic && magic_num != 0x0)
		ft_error("Wrong NULL", -3);
}

void		valid_files(t_players *players)
{
	int				fd;
	t_players		*temp;
	unsigned char	*buf;

	if (!(buf = (unsigned char *)malloc(sizeof(unsigned char) * 4)))
		ft_error("Problem with malloc for buffer or magic number", -3);
	temp = players;
	while (temp)
	{
		if ((fd = open(temp->filename, O_RDONLY)) < 0)
			ft_error("File noopen", -3);
		check_magic_or_null(fd, buf, 1);
		check_name_or_comment(fd, temp, 1);
		check_magic_or_null(fd, buf, 0);
		check_code_size(fd, buf, temp);
		check_name_or_comment(fd, temp, 0);
		check_magic_or_null(fd, buf, 0);
		check_code(fd, temp, buf);
		if (close(fd) < 0)
			ft_error("File noclose", -3);
		temp = temp->next;
	}
	free(buf);
}
