/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/07 15:52:21 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

void			ft_details(t_all *all)
{
	if (all->flag.f == 1)
	{
		ft_printf(".cor file: " ANSI_COLOR_GREEN "%s"
			ANSI_COLOR_RESET "\n", all->file_cor);
		ft_printf(".s file: " ANSI_COLOR_GREEN "%s"
			ANSI_COLOR_RESET "\n", all->file_s);
		ft_printf(".name    \"%s\"\n", all->magic->prog_name);
		ft_printf(".comment \"%s\"\n\n", all->magic->comment);
	}
}

void			ft_null_test(t_all *all)
{
	int i;

	i = 0;
	while ((int)(all->magic->prog_name[i]) != 0)
		i++;
	while (i < PROG_NAME_LENGTH)
	{
		if ((int)(all->magic->prog_name[i]) != 0)
			ft_exit(ERR_NBR_NLL);
		i++;
	}
	i = 0;
	while ((int)(all->magic->comment[i]) != 0)
		i++;
	while (i < COMMENT_LENGTH)
	{
		if ((int)(all->magic->comment[i]) != 0)
			ft_exit(ERR_NBR_CMT);
		i++;
	}
}

void			ft_process(t_all *all)
{
	int			size;
	char		*buf;

	buf = read_file(all->file_cor, &size);
	all->magic = (t_magic*)buf;
	ft_null_test(all);
	if (i_have_no_idea_how_it_works(all->magic->magic) != COREWAR_EXEC_MAGIC)
		ft_exit(ERR_MGC_NBR);
	if (all->flag.p != 1 && (all->fd = open(all->file_s,
		O_WRONLY | O_CREAT | O_TRUNC, 0777)) == -1)
		ft_exit(ERR_CRT_S);
	ft_details(all);
	ft_write_name_comment(all);
	ft_cmp_inc(all, buf + sizeof(t_magic),
		i_have_no_idea_how_it_works(all->magic->prog_size));
	if (all->flag.p == 0)
	{
		ft_printf("Writing output program to " ANSI_COLOR_GREEN "%s"
			ANSI_COLOR_RESET "\n", all->file_s);
		if (all->flag.f == 1)
			ft_print_s(all);
	}
	free(buf);
}

int				main(int ac, char **av)
{
	t_all all;

	ft_init(&all, ac, av);
	if (ac < 2)
		ft_usage();
	else if (ac == 3)
	{
		if (ft_strcmp(av[1], "-p") == 0)
			all.flag.p = 1;
		else if (ft_strcmp(av[1], "-f") == 0)
			all.flag.f = 1;
		else if (ft_strcmp(av[1], "-P") == 0)
			all.flag.p = 1;
		else
			ft_exit(ERR_NBR_AGRS);
	}
	else if (ac > 3)
		ft_exit(ERR_NBR_AGRS);
	all.file_s = ft_s(&all);
	ft_process(&all);
	ft_free_all(&all);
	return (1);
}
