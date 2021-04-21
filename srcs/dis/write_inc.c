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

void	ft_write_r(t_all *all, int index, char *data, int *j)
{
	char *temp;

	if (index == 1)
	{
		temp = ft_itoa(ft_short(&data[*j]));
		if (all->flag.p == 1)
			ft_putstr_fd_wide(DIRECT_CHAR, temp, 0);
		else
			ft_putstr_fd_wide(DIRECT_CHAR, temp, all->fd);
		*j = *j + 2;
	}
	else
	{
		temp = ft_itoa(ft_int(&data[*j]));
		if (all->flag.p == 1)
			ft_putstr_fd_wide(DIRECT_CHAR, temp, 0);
		else
			ft_putstr_fd_wide(DIRECT_CHAR, temp, all->fd);
		*j = *j + 4;
	}
	free(temp);
}

void	ft_write_code_to_fd(t_all *all, char *temp)
{
	if (ft_atoi(temp) > REG_NUMBER)
		ft_exit(ERR_REG_NUM);
	if (all->flag.p == 1)
		ft_putstr_fd_wide('r', temp, 0);
	else
		ft_putstr_fd_wide('r', temp, all->fd);
	free(temp);
}

int		ft_write_code(char *str, t_op op, t_all *all)
{
	int		i;
	int		j;

	i = 0;
	j = 2;
	while (i < op.params)
	{
		if (((str[1] >> (6 - (i * 2))) & 3) == REG_CODE)
			ft_write_code_to_fd(all, ft_itoa(str[j++]));
		else if (((str[1] >> (6 - (i * 2))) & 3) == IND_CODE)
		{
			ft_putstr_to_fd(all, ft_itoa(ft_short(&str[j])));
			j += 2;
		}
		else if (((str[1] >> (6 - (i * 2))) & 3) == DIR_CODE)
			ft_write_r(all, op.index, str, &j);
		if (++i < op.params)
			ft_putstr_to_fd(all, ft_strdup(", "));
		else
			ft_putstr_to_fd(all, ft_strdup("\n"));
	}
	return (j);
}

void	ft_write_to_fd(t_all *all, char *temp)
{
	if (all->flag.p == 1)
	{
		ft_putstr_fd_wide(DIRECT_CHAR, temp, 0);
		ft_putchar_fd('\n', 0);
	}
	else
	{
		ft_putstr_fd_wide(DIRECT_CHAR, temp, all->fd);
		ft_putchar_fd('\n', all->fd);
	}
	free(temp);
}

int		ft_write_inc(char *data, t_op op, t_all *all)
{
	if (all->flag.p == 1)
	{
		ft_putstr_fd(op.opstr, 0);
		ft_putchar_fd('\t', 0);
	}
	else
	{
		ft_putstr_fd(op.opstr, all->fd);
		ft_putchar_fd('\t', all->fd);
	}
	if (op.acb)
		return (ft_write_code(data, op, all));
	if (op.index)
	{
		ft_write_to_fd(all, ft_itoa(ft_short(&data[1])));
		return (3);
	}
	else
	{
		ft_write_to_fd(all, ft_itoa(ft_int(&data[1])));
		return (5);
	}
}
