/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/14 16:48:27 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	lld(t_line *temp)
{
	char	*new;

	if (temp->line[3] == ' ' || temp->line[3] == '\t')
		new = ft_afterspace(temp->line + 3);
	else
		new = temp->line + 3;
	if (new[0] == DIRECT_CHAR || new[0] == LABEL_CHAR ||
			(new[0] >= '0' && new[0] <= '9') || new[0] == '-' || new[0] == '+')
	{
		temp->arg = ft_strsplit_wide(new, SEPARATOR_CHAR);
		if (ft_size_mass(temp->arg) != 2 ||
				ft_h_m(new, SEPARATOR_CHAR) != 1)
			ft_error(ERR_ARG, ERR_LLD);
		ft_trim_mass_arg(temp->arg);
		ft_ld_arg1(temp, temp->arg[0]);
		ft_check_reg(temp->arg[1]);
	}
	else
		ft_error(ERR, ERR_LLD);
	temp->op = 13;
	temp->flag = 1;
}
