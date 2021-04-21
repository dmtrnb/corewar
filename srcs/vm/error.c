/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:28:27 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/14 15:43:42 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_error(char *line, int i)
{
	ft_putstr(ANSI_COLOR_RED);
	ft_putstr(line);
	ft_putstr(ANSI_COLOR_RESET);
	ft_putstr("\n");
	exit(i == -1 ? i : -1);
}

int		ft_usage(void)
{
	ft_putstr(USG0);
	ft_putstr(USG1);
	ft_putendl(USG2);
	ft_putendl(USG3);
	ft_putendl(USG4);
	ft_putendl(USG5);
	ft_putendl(USG6);
	ft_putendl(USG7);
	ft_putendl(USG8);
	ft_putendl(USG9);
	exit(-1);
}
