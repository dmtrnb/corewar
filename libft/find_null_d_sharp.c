/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_null_d_sharp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:30:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/07/31 17:46:41 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_space_only(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ft_sharp_o(t_print *info, char c)
{
	int i;

	i = 0;
	if (info->str1[0] == ' ')
	{
		while (info->str1[i + 1] == ' ')
			i++;
		if (info->str1[i + 1] != '0')
			info->str1[i] = '0';
	}
	else if (info->str1[0] != '0')
		info->str1 = ft_twice_symb(info, c, 0);
}

void	ft_find_plus(t_print *info)
{
	if (info->plus != 0)
		(*info).str1 = ft_print_plus((*info).str1, (*info).plus, (*info).null);
}

char	*ft_only_null(char *str1, int plus, int flag)
{
	char	*spec;

	if (flag == 1)
	{
		str1[0] = plus;
		spec = (str1);
	}
	else if (plus == '-')
		spec = ft_strjoin("-", str1);
	else
		spec = ft_strjoin("+", str1);
	return (spec);
}

char	*ft_print_plus(char *str1, int plus, int flag)
{
	int		i;

	plus = (plus > 0) ? '+' : '-';
	i = 0;
	if (str1[0] == '0' && str1[1] != '\0')
		return (ft_only_null(str1, plus, flag));
	else if (str1[0] == ' ')
	{
		while (str1[i + 1] == ' ')
			i++;
		if (str1[i] == ' ')
			str1[i] = plus;
		else if (str1[i] == '0')
			str1[i - 1] = plus;
		return ((str1));
	}
	else if (str1[0] != '-')
		return (ft_not_only_null(str1, plus));
	return ((str1));
}
