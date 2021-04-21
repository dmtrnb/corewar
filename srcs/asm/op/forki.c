/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forki.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/14 16:46:24 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	forki(t_line *temp)
{
	char	*new;

	if (temp->line[4] == ' ' || temp->line[4] == '\t')
		new = ft_afterspace(temp->line + 4);
	else
		new = temp->line + 4;
	if (new[0] == DIRECT_CHAR)
	{
		temp->arg = ft_strsplit_wide(new, SEPARATOR_CHAR);
		if (ft_size_mass(temp->arg) != 1 || ft_h_m(new, SEPARATOR_CHAR) != 0)
			ft_error(ERR_ARG, ERR_FORK);
		ft_trim_mass_arg(temp->arg);
		if (temp->arg[0][1] == LABEL_CHAR)
			ft_check_ls_label(temp->arg[0] + 2);
		else
			ft_check_ld_number(temp->arg[0] + 1);
	}
	else
		ft_error(ERR, ERR_FORK);
	temp->op = 12;
	temp->dir = IND_SIZE;
	temp->size = 1 + IND_SIZE;
	temp->flag = 1;
}
