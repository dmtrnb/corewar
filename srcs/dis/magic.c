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

void	ft_putstr_to_fd(t_all *all, char *temp)
{
	if (all->flag.p == 1)
		ft_putstr_fd(temp, 0);
	else
		ft_putstr_fd(temp, all->fd);
	free(temp);
}

int		ft_int(char *array)
{
	int	i;

	i = (unsigned char)array[3];
	i += (unsigned char)array[2] * 256;
	i += (unsigned char)array[1] * 256 * 256;
	i += (unsigned char)array[0] * 256 * 256 * 256;
	return (i);
}

int		ft_short(char *array)
{
	short	i;

	i = (unsigned char)array[1];
	i += (unsigned char)array[0] * 256;
	return (i);
}

int		i_have_no_idea_how_it_works(int x)
{
	int	y;

	y = (x >> 24) & 0xFF;
	y += (x >> 8) & 0xFF00;
	y += (x << 8) & 0xFF0000;
	y += x << 24;
	return (y);
}
