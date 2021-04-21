/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:23:45 by mkami             #+#    #+#             */
/*   Updated: 2019/07/31 17:47:28 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_find_sharp2(t_print *info)
{
	char	c;

	c = info->str[info->len];
	if (((!(info->str1[0] == '0' &&
			info->str1[1] == '\0')) && info->sharp == 1) || c == 'p')
	{
		if (c == 'x' || c == 'X' || c == 'p')
		{
			if (!(ft_space_only(info->str1) == 1 && c != 'p'))
				ft_print_sharp(info, c);
		}
		else if (c == 'o' || c == 'O')
			ft_sharp_o(info, c);
	}
}

int		ft_find_sharp(t_print *info, char c)
{
	if (info->sharp == 1 && (c == 'x' || c == 'X'))
		return (2);
	return (0);
}

char	*ft_twice_symb(t_print *info, char c, int i)
{
	char	*temp;
	char	*spec;

	spec = ft_strnew(2);
	spec[0] = '0';
	if (c != 'o' && c != 'O')
		spec[1] = c;
	temp = info->str1;
	info->str1 = ft_strjoin(spec, info->str1 + i);
	ft_strdel(&temp);
	ft_strdel(&spec);
	return (info->str1);
}

void	ft_sharp_nulls(t_print *info, char c)
{
	int i;

	i = 0;
	if (info->str1[1] == '0')
	{
		if (info->str[info->len] == 'p')
		{
			if (info->number != 0)
				while (info->str1[i] == '0')
					i++;
			info->str1 = ft_twice_symb(info, c, i);
		}
		else
			info->str1[1] = c;
	}
	else
	{
		(i = (info->str1[1] != '\0' && info->null == 1) ? 1 : 0);
		info->str1 = ft_twice_symb(info, c, i);
	}
}

void	ft_print_sharp(t_print *info, char c)
{
	int		i;

	i = 0;
	c = c == 'p' ? 'x' : c;
	if (info->str1[0] == ' ')
		if (info->str1[1] == ' ')
		{
			while (info->str1[i + 1] == ' ')
				i++;
			info->str1[i] = c;
			info->str1[i - 1] = '0';
		}
		else
			info->str1 = ft_twice_symb(info, c, 1);
	else if (info->str1[0] == '0')
		ft_sharp_nulls(info, c);
	else
		info->str1 = ft_twice_symb(info, c, 0);
}
