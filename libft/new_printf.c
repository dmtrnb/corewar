/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:19:26 by dholiday          #+#    #+#             */
/*   Updated: 2019/07/31 17:47:18 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *restrict format, ...)
{
	va_list		hello;
	int			return_value;
	int			i;

	va_start(hello, format);
	i = 0;
	return_value = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			i++;
			return_value++;
		}
		else
			ft_k(format, &i, &return_value, hello);
	}
	va_end(hello);
	return (return_value);
}

int		ft_understand(char *str)
{
	char	*a;
	int		i;
	int		j;
	int		flag;

	i = -1;
	flag = 0;
	a = ft_memalloc(14);
	a = ft_memcpy(a, "cpsdiouxXfUDOS", 13);
	while (str[++i] != '\0' && str[i] != '%')
	{
		j = -1;
		while (a[++j] != '\0')
			if (a[j] == str[i])
			{
				ft_strdel(&a);
				return (i);
			}
		flag = (flag == 0 && ft_char_comp(str[i]) == 0) ? 1 : flag;
	}
	ft_strdel(&a);
	if (str[i] == '%' && flag == 0)
		return (-5);
	return (-4);
}

int		ft_char_comp(char c)
{
	int		i;
	char	*b;

	i = 0;
	b = ft_memalloc(27);
	b = ft_memcpy(b, "0123456789qetaghjlzvn+-.# ", 26);
	while (b[i] != 0)
	{
		if (b[i] == c)
		{
			ft_strdel(&b);
			return (1);
		}
		i++;
	}
	ft_strdel(&b);
	return (0);
}
