/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:55:59 by dholiday          #+#    #+#             */
/*   Updated: 2019/07/31 17:46:25 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_type_d(va_list hello, t_print *info)
{
	long long int	a;
	char			*str1;

	a = va_arg(hello, long long int);
	if (info->len != 0)
	{
		if ((str1 = ft_strchr(info->str, 'z')) != NULL)
			a = (size_t)a;
		else if ((str1 = ft_strchr(info->str, 'j')) != NULL)
			a = (intmax_t)a;
		else if ((str1 = ft_strchr(info->str, 'l')) != NULL)
			a = str1[1] == 'l' ? a : (long int)a;
		else if ((str1 = ft_strchr(info->str, 'h')) != NULL)
			a = str1[1] == 'h' ? (signed char)a : (short int)a;
		else
			a = (int)a;
	}
	else
		a = (int)a;
	info->plus = a < 0 ? -1 : info->plus;
	str1 = ft_itoa2(ABS(a), 1);
	return (str1);
}

char	*ft_type_dd(va_list hello)
{
	long long int	a;
	char			*str1;

	a = va_arg(hello, long int);
	str1 = ft_itoa2(ABS(a), 1);
	return (str1);
}

char	*ft_type_u(va_list hello, t_print *info)
{
	unsigned long long int	a;
	char					*str1;

	a = va_arg(hello, unsigned long long int);
	if (info->len == 0)
		a = (unsigned int)a;
	else if ((str1 = ft_strchr(info->str, 'z')) != NULL)
		a = (size_t)a;
	else if ((str1 = ft_strchr(info->str, 'j')) != NULL)
		a = (uintmax_t)a;
	else if ((str1 = ft_strchr(info->str, 'l')) != NULL)
		a = str1[1] == 'l' ? (unsigned long long int)a :
			(unsigned long int)a;
	else if ((str1 = ft_strchr(info->str, 'h')) != NULL)
		a = str1[1] == 'h' ? (unsigned char)a : (unsigned short int)a;
	else
		a = (unsigned int)a;
	if (a == 0 && info->nullpoint != 0)
		info->sharp = 0;
	if ((info->str[info->len] == 'x') || (info->str[info->len] == 'X'))
		str1 = ft_conv_six(a, info->str[info->len]);
	else
		str1 = info->str[info->len] == 'o' ? ft_conv_octal(a) :
		ft_itoa2(ABS(a), 1);
	return (str1);
}

char	*ft_type_uu(va_list hello, char *str, int len)
{
	unsigned long long int	a;
	char					*str1;

	a = va_arg(hello, unsigned long int);
	if (str[len] == 'O')
		str1 = ft_conv_octal(a);
	else
		str1 = ft_itoa2(ABS(a), 1);
	return (str1);
}

char	*ft_type_c(va_list hello, t_print *info)
{
	char *a;

	a = ft_memalloc(3);
	a[0] = va_arg(hello, int);
	info->number = a[0];
	if (a[0] == 0)
	{
		a[0] = '^';
		a[1] = '@';
		if (info->beforepoint != 0)
			info->beforepoint++;
		if (info->afterpoint != 0)
			info->afterpoint++;
	}
	return (a);
}
