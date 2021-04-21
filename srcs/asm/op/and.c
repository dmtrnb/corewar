/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/14 16:46:25 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	and(t_line *temp)
{
	char	*new;

	if (temp->line[3] == ' ' || temp->line[3] == '\t')
		new = ft_afterspace(temp->line + 3);
	else
		ft_error(ERR, ERR_AND);
	temp->arg = ft_strsplit_wide(new, SEPARATOR_CHAR);
	if (ft_size_mass(temp->arg) != 3 || ft_h_m(new, SEPARATOR_CHAR) != 2)
		ft_error(ERR_ARG, ERR_AND);
	ft_trim_mass_arg(temp->arg);
	temp->cod += ft_check_trio(temp->arg[0], 1, temp, DIR_SIZE);
	temp->cod += ft_check_trio(temp->arg[1], 2, temp, DIR_SIZE);
	ft_check_reg(temp->arg[2]);
	temp->cod += 4;
	temp->size += 1 + 1 + 1;
	temp->op = 6;
	temp->flag = 1;
}

int		ft_check_trio(char *arg, int i, t_line *temp, int size)
{
	if (arg[0] == 'r')
	{
		ft_check_reg(arg);
		temp->size += 1;
		return (i == 1 ? 64 : 16);
	}
	else if (arg[0] == DIRECT_CHAR)
	{
		if (arg[1] == LABEL_CHAR)
			ft_check_ls_label(arg + 2);
		else
			ft_check_ld_number(arg + 1);
		temp->size += size;
		return (i == 1 ? 128 : 32);
	}
	else if (arg[0] == LABEL_CHAR)
		ft_check_ls_label(arg + 1);
	else
		ft_check_ld_number(arg);
	temp->size += IND_SIZE;
	return (i == 1 ? 192 : 48);
}
