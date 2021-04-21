/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/14 16:48:03 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	xor(t_line *temp)
{
	char	*new;

	if (temp->line[3] == ' ' || temp->line[3] == '\t')
		new = ft_afterspace(temp->line + 3);
	else
		ft_error(ERR, ERR_XOR);
	temp->arg = ft_strsplit_wide(new, SEPARATOR_CHAR);
	if (ft_size_mass(temp->arg) != 3 || ft_h_m(new, SEPARATOR_CHAR) != 2)
		ft_error(ERR_ARG, ERR_XOR);
	ft_trim_mass_arg(temp->arg);
	temp->cod += ft_check_trio(temp->arg[0], 1, temp, DIR_SIZE);
	temp->cod += ft_check_trio(temp->arg[1], 2, temp, DIR_SIZE);
	ft_check_reg(temp->arg[2]);
	temp->cod += 4;
	temp->size += 1 + 1 + 1;
	temp->op = 8;
	temp->flag = 1;
}
