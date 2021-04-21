/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_useful_mass.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/02/25 18:43:36 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_size_mass(char **mass)
{
	int i;

	i = 0;
	if (mass == NULL)
		return (0);
	while (mass[i] != NULL)
		i++;
	return (i);
}

void	ft_trim_mass_arg(char **mass)
{
	int		i;
	char	*temp;

	i = 0;
	if (mass == NULL)
		return ;
	while (mass[i] != NULL)
	{
		temp = ft_strtrim(mass[i]);
		ft_strdel(&mass[i]);
		mass[i] = temp;
		i++;
	}
}

void	ft_print_mass(char **mass)
{
	int i;

	i = 0;
	while (mass[i] != NULL)
	{
		ft_printf("\033[34;1;1mmass[%i]:\033[0m%s\n", i, mass[i]);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_free_mas(char **arr)
{
	int i;

	i = 0;
	if (arr != NULL)
	{
		while (arr[i] != 0)
		{
			ft_strdel(&arr[i]);
			i++;
		}
		free(arr);
	}
}

int		ft_h_m(char *str, int c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}
