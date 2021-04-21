/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/15 14:51:41 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			main(int argc, char **argv)
{
	t_all all;

	ft_init(&all);
	if (argc > 1)
	{
		ft_read_file(argv[argc - 1], &all);
		ft_labels(&all);
		ft_look_at_list(&all);
		ft_codirovka(&all);
		ft_general_write(&all);
		ft_clean_all(&all);
	}
	else
	{
		ft_putstr(ANSI_COLOR_YELLOW"usage : ./asm player.s\n"ANSI_COLOR_RESET);
		ft_putstr("(if you send few players, only last will be proceeded)\n");
		ft_clean_all(&all);
	}
	return (0);
}

void		ft_read_file(char *file, t_all *all)
{
	char	*line;
	char	*check;
	int		i;

	all->fd = open(file, O_RDONLY);
	all->file = file;
	check = NULL;
	if (all->fd == -1 || read(all->fd, check, 0) < 0)
		ft_error(ERR_FILE, NULL);
	while ((i = get_next_line(all->fd, &line)) > 0)
	{
		ft_process(line, all);
		ft_strdel(&line);
	}
	if (i < 0)
	{
		ft_putstr("goodbye");
		exit(1);
	}
	ft_strdel(&line);
}

char		*ft_afterspace(char *line)
{
	int i;

	i = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	else
		return (line + i);
}

t_line		*ft_create(char *line)
{
	t_line *new;

	new = (t_line*)malloc(sizeof(t_line));
	new->line = line;
	new->ans = ft_strnew(80);
	new->metka = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->arg = NULL;
	new->size = 0;
	new->flag = 0;
	new->op = 0;
	new->cod = 0;
	new->dir = DIR_SIZE;
	return (new);
}

void		ft_error(char *line, char *add)
{
	ft_printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET, line);
	if (add != NULL)
		ft_printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET "\n", add);
	else
		ft_putchar('\n');
	exit(-1);
}
