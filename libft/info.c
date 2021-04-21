/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:38:26 by dholiday          #+#    #+#             */
/*   Updated: 2019/07/31 17:47:13 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bef(t_print *info, int i)
{
	(*info).beforepoint = ft_atoi((*info).str + i + 1);
	while (i >= 0 && (info->str[i] != '.'))
		i--;
	if (i >= 0 && info->str[i] == '.')
	{
		(*info).afterpoint = ft_atoi((*info).str + i + 1);
		if ((*info).afterpoint == 0 && info->star != 1)
			info->nullpoint = 0;
	}
}

void	ft_bef_and_af(t_print *info, int i)
{
	(*info).afterpoint = ft_atoi((*info).str + i + 1);
	if ((*info).afterpoint == 0 && info->star != 1)
		info->nullpoint = 0;
	while (i >= 0)
	{
		while (i >= 0 && (info->str[i] > 57 || info->str[i] < 48))
			i--;
		while (i >= 0 && info->str[i] <= 57 && info->str[i] >= 48)
			i--;
		if (i >= 0 && info->str[i] == '.')
			continue ;
		else
		{
			(*info).beforepoint = ft_atoi((*info).str + i + 1);
			break ;
		}
	}
}

void	ft_find_a_and_b(t_print *info)
{
	int i;

	i = ft_strlen(info->str) - 1;
	while (i >= 0 && (info->str[i] > 57 ||
		info->str[i] < 49) && info->str[i] != '.')
		i--;
	while (i >= 0 && info->str[i] <= 57 && info->str[i] >= 48)
		i--;
	if (i >= 0)
		if (info->str[i] == '.')
			ft_bef_and_af(info, i);
		else
			ft_bef(info, i);
	else
		(*info).beforepoint = ft_atoi((*info).str + i + 1);
}

void	ft_read(t_print *info, va_list hello)
{
	char c;

	c = info->str[info->len];
	if (c == 'd' || c == 'i')
		info->str1 = ft_type_d(hello, info);
	else if (c == 'D')
		info->str1 = ft_type_dd(hello);
	else if (c == 'c')
		info->str1 = ft_type_c(hello, info);
	else if (c == 'o' || c == 'u' ||
			c == 'x' || c == 'X')
		info->str1 = ft_type_u(hello, info);
	else if (c == 'O' || c == 'U')
		info->str1 = ft_type_uu(hello, info->str, info->len);
	else if (c == 's' || c == 'S')
		info->str1 = ft_type_s(hello);
	else if (c == 'p')
	{
		info->str1 = ft_type_p(hello, info);
		ft_find_sharp2(info);
	}
	else if (c == 'f')
		info->str1 = ft_type_f(hello, info);
}

void	ft_swap_minus(char *str)
{
	char	*temp;

	if ((temp = ft_strchr(str, '.')) != NULL)
	{
		if (temp[1] == '-')
		{
			temp[0] = '-';
			temp[1] = '.';
		}
	}
}
