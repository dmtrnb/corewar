/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:17:46 by mkami             #+#    #+#             */
/*   Updated: 2019/07/31 17:47:38 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_type_f(va_list hello, t_print *info)
{
	char	*str1;

	if (ft_strchr(info->str, 'L') == NULL)
		str1 = ft_type_f_double(hello, info);
	else
		str1 = ft_type_f_long_double(hello, info);
	return (str1);
}

int		ft_detect_a_plz(t_print *info)
{
	int a;

	if (info->nullpoint == 0)
		a = 0;
	else
		a = (info->afterpoint != 0) ? info->afterpoint : 6;
	return (a);
}

char	*ft_type_f_double(va_list hello, t_print *info)
{
	double			d;
	char			*str1;
	char			*str;
	char			*temp;
	int				a;

	a = ft_detect_a_plz(info);
	d = va_arg(hello, double);
	if ((str = ft_infinity(d, info)) != NULL)
		return (str);
	info->plus = (long long int)d < 0 ? -1 : info->plus;
	temp = ft_itoa2(ABS((long long int)d), 1);
	str = ft_strjoin(temp, ".");
	ft_strdel(&temp);
	temp = ft_itoa_float(ABS(d), a + 1);
	str1 = ft_strjoin(str, temp);
	ft_strdel(&temp);
	ft_strdel(&str);
	str1 = ft_approx(str1, a);
	a = ft_strlen(str1);
	str1[a - 1] = '\0';
	if (info->nullpoint == 0)
		str1[a - 2] = '\0';
	return (str1);
}

char	*ft_infinity(double d, t_print *info)
{
	double	inf;
	double	inf_m;
	char	*str;

	str = ft_memalloc(4);
	inf = 5.0 / 0.0;
	inf_m = -5.0 / 0.0;
	if (d == inf || d == inf_m)
		str = ft_memcpy(str, "inf", 3);
	else if (d != d)
	{
		info->plus = 0;
		str = ft_memcpy(str, "nan", 3);
	}
	else
	{
		ft_strdel(&str);
		return (NULL);
	}
	if (d == inf_m)
		info->plus = -1;
	return (str);
}

char	*ft_type_f_long_double(va_list hello, t_print *info)
{
	long double		d;
	char			*str1;
	char			*str;
	int				a;
	char			*temp;

	a = ft_detect_a_plz(info);
	d = va_arg(hello, long double);
	info->plus = (long long int)d < 0 ? -1 : info->plus;
	temp = ft_itoa2(ABS((long long int)d), 1);
	str = ft_strjoin(temp, ".");
	ft_strdel(&temp);
	temp = ft_itoa_float_long(ABS(d), a + 1);
	str1 = ft_strjoin(str, temp);
	ft_strdel(&temp);
	ft_strdel(&str);
	ft_approx(str1, a);
	a = ft_strlen(str1);
	str1[a - 1] = '\0';
	if (info->nullpoint == 0)
		str1[a - 2] = '\0';
	return (str1);
}
