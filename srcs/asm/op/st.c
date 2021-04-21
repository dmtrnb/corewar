/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/14 16:48:06 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	st(t_line *temp)
{
	char	*new;

	if (temp->line[2] == ' ' || temp->line[2] == '\t')
		new = ft_afterspace(temp->line + 2);
	else
		ft_error(ERR, ERR_ST);
	temp->arg = ft_strsplit_wide(new, SEPARATOR_CHAR);
	if (ft_size_mass(temp->arg) != 2 || ft_h_m(new, SEPARATOR_CHAR) != 1)
		ft_error(ERR_ARG, ERR_ST);
	ft_trim_mass_arg(temp->arg);
	ft_check_reg(temp->arg[0]);
	ft_st_arg2(temp, temp->arg[1]);
	temp->op = 3;
	temp->flag = 1;
}

void	ft_st_arg2(t_line *temp, char *arg)
{
	if (arg[0] == LABEL_CHAR)
		ft_check_ls_label(arg + 1);
	else if (arg[0] == 'r')
	{
		ft_check_reg(arg);
		temp->size = 1 + 1 + 1 + 1;
		temp->cod = 80;
		return ;
	}
	else
		ft_check_ld_number(arg);
	temp->size = 1 + 1 + 1 + IND_SIZE;
	temp->cod = 112;
}
