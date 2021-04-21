/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_mass.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:31:43 by dholiday          #+#    #+#             */
/*   Updated: 2019/10/04 17:32:58 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_clean_mass(char **mass)
{
	int i;

	i = 0;
	if (mass == NULL)
		return ;
	while (mass[i] != NULL)
	{
		ft_strdel(&mass[i]);
		i++;
	}
	free(mass);
}
