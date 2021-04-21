/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/14 16:46:23 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ld(t_line *temp)
{
	char	*new;

	if (temp->line[2] == ' ' || temp->line[2] == '\t')
		new = ft_afterspace(temp->line + 2);
	else
		new = temp->line + 2;
	if (new[0] == DIRECT_CHAR || new[0] == LABEL_CHAR ||
			(new[0] >= '0' && new[0] <= '9') || new[0] == '-' || new[0] == '+')
	{
		temp->arg = ft_strsplit_wide(new, SEPARATOR_CHAR);
		if (ft_size_mass(temp->arg) != 2 ||
			ft_h_m(new, SEPARATOR_CHAR) != 1)
			ft_error(ERR_ARG, ERR_LD);
		ft_trim_mass_arg(temp->arg);
		ft_ld_arg1(temp, temp->arg[0]);
		ft_check_reg(temp->arg[1]);
	}
	else
		ft_error(ERR, ERR_LD);
	temp->op = 2;
	temp->flag = 1;
}

void	ft_ld_arg1(t_line *temp, char *arg)
{
	if (arg[0] == DIRECT_CHAR)
	{
		temp->size = 1 + 1 + 1 + DIR_SIZE;
		temp->cod = 144;
		if (arg[1] == LABEL_CHAR)
			ft_check_ls_label(arg + 2);
		else
			ft_check_ld_number(arg + 1);
		return ;
	}
	else if (arg[0] == LABEL_CHAR)
		ft_check_ls_label(arg + 1);
	else
		ft_check_ld_number(arg);
	temp->size = 1 + 1 + 1 + IND_SIZE;
	temp->cod = 208;
}

void	ft_check_ld_number(char *arg)
{
	int i;

	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i = 1;
	if (ft_str_is_digit(arg + i) == 0)
		ft_error(ERR_LD_DIG, NULL);
}

void	ft_check_ls_label(char *arg)
{
	int i;
	int len;

	len = ft_strlen(arg);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(LABEL_CHARS, arg[i]) == NULL)
			ft_error(ERR_LD_LBL, NULL);
		i++;
	}
}

void	ft_check_reg(char *arg)
{
	long long int i;

	if (arg[0] != 'r')
		ft_error(ERR_LD_NO_REG, NULL);
	else
	{
		if (ft_str_is_digit(arg + 1) == 0)
			ft_error(ERR_LD_REG, NULL);
		i = ft_atoi(arg + 1);
		if (i < 0 || i > 99)
			ft_error(ERR_LD_BAD_REG, NULL);
	}
}
