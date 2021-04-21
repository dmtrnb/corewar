/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:08:33 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/09 13:01:11 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_find_all(t_print *info)
{
	int		i;
	char	c;

	c = info->str[info->len];
	i = 0;
	while (info->str[i] != '\0')
	{
		if (info->str[i] == '#' || info->str[i] == 'p')
			info->sharp = 1;
		else if (info->str[i] == '-')
			info->minus = 1;
		else if (info->str[i] == ' ')
			info->space = 1;
		else if (info->str[i] == '+')
			if (c == 'd' || c == 'i' || c == 'f' || c == 'D')
				info->plus = 1;
		i++;
	}
}

void	ft_make_info(t_print *info, char *str)
{
	(*info).str = str;
	(*info).str1 = 0;
	(*info).len = ft_understand(str);
	info->minus = 0;
	info->sharp = 0;
	info->plus = 0;
	info->space = 0;
	ft_find_all(info);
	info->beforepoint = 0;
	info->afterpoint = 0;
	info->nullpoint = 1;
	ft_find_a_and_b(info);
	if (info->minus == 0 && info->afterpoint == 0 && info->nullpoint == 1)
		(*info).null = ft_find_null(info->str);
	else
		info->null = 0;
}

void	ft_lets_spec(t_print *info, char *surprise)
{
	if (info->beforepoint > 0 && info->plus == 0 && surprise == NULL)
		info->beforepoint = info->beforepoint - info->space;
	if (info->str[info->len] == 'f')
		info->str1 = ft_wide_f(info);
	else if (info->str[info->len] == 's' || info->str[info->len] == 'c')
		info->str1 = ft_wide_s(info);
	else
		info->str1 = ft_wide_diouxx(info, info->str[info->len]);
	ft_print_null(info);
	if (info->str[info->len] != 'p')
		ft_find_sharp2(info);
}

int		ft_lets_check(char *str, va_list hello, char *surprise)
{
	int		flag;
	t_print info;

	str = ft_make_star2(&info, str, hello);
	ft_make_info(&info, str);
	if (surprise != NULL)
	{
		info.afterpoint = 0;
		info.str1 = ft_strdup(surprise);
	}
	else
		ft_read(&info, hello);
	ft_lets_spec(&info, surprise);
	ft_find_plus(&info);
	ft_swap_str(&info);
	ft_glue_space(&info);
	ft_putsrt(info.str1);
	flag = ft_strlen(info.str1);
	ft_strdel(&info.str1);
	ft_strdel(&info.str);
	return (flag);
}
