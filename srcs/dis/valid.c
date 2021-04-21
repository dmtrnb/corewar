/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dis_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/02/18 15:14:02 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disassembler.h"

char	*ft_s(t_all *all)
{
	char	*out;
	char	*temp;

	temp = ft_strrchr(all->file_cor, '.');
	if (temp == NULL)
		ft_exit(ERR_FILE_NAME);
	if (ft_strcmp(temp, ".cor"))
		ft_exit(ERR_FILE_FORMAT);
	out = ft_memalloc(ft_strlen(all->file_s) - 4 + 2 + 1);
	ft_strncpy(out, all->file_s, ft_strlen(all->file_s) - 4);
	ft_strncpy(out + ft_strlen(out), ".s", 2);
	return (out);
}

void	ft_free_all(t_all *all)
{
	ft_strdel(&(all->file_cor));
	ft_strdel(&(all->file_s));
}

void	ft_init(t_all *all, int ac, char **av)
{
	if (ac > 1)
	{
		all->file_s = ac == 3 ? av[2] : av[1];
		all->file_cor = ft_strdup(ac == 3 ? av[2] : av[1]);
		all->fd = 0;
		all->flag.f = 0;
		all->flag.p = 0;
	}
}
