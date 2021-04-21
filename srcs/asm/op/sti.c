/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/14 16:48:05 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sti(t_line *temp)
{
	char	*new;

	if (temp->line[3] == ' ' || temp->line[3] == '\t')
		new = ft_afterspace(temp->line + 3);
	else
		ft_error(ERR, ERR_ST_);
	temp->arg = ft_strsplit_wide(new, SEPARATOR_CHAR);
	if (ft_size_mass(temp->arg) != 3 || ft_h_m(new, SEPARATOR_CHAR) != 2)
		ft_error(ERR_ARG, ERR_ST_);
	ft_trim_mass_arg(temp->arg);
	ft_check_reg(temp->arg[0]);
	temp->cod += 64;
	temp->size += 1 + 1 + 1;
	temp->cod += ft_check_trio(temp->arg[1], 2, temp, IND_SIZE);
	ft_check_double(temp->arg[2], 3, temp);
	temp->op = 11;
	temp->dir = IND_SIZE;
	temp->flag = 1;
}

void	ft_check_double(char *arg, int i, t_line *temp)
{
	if (arg[0] == DIRECT_CHAR)
	{
		if (arg[1] == LABEL_CHAR)
			ft_check_ls_label(arg + 2);
		else
			ft_check_ld_number(arg + 1);
		temp->size += IND_SIZE;
		temp->cod += i == 2 ? 32 : 8;
	}
	else
	{
		ft_check_reg(arg);
		temp->size += 1;
		temp->cod += i == 2 ? 16 : 4;
	}
}
