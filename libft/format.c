/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:13:33 by mkami             #+#    #+#             */
/*   Updated: 2019/07/31 17:46:47 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sputni_check(int n, char *format_i)
{
	char *str;

	str = (char*)malloc(sizeof(char) * (n));
	str = ft_memset(str, '\0', n);
	str = ft_strncpy(str, format_i, n - 1);
	return (str);
}

void	ft_k(const char *format, int *i, int *return_value, va_list hello)
{
	int		k;
	int		j;
	char	*str;

	*i = *i + 1;
	k = ft_understand((char *)(format + *i));
	if (k == -5)
	{
		j = *i;
		while (format[j] != '%')
			j++;
		j++;
		str = ft_sputni_check(j - *i, (char *)format + *i);
		*i = j;
		*return_value += ft_lets_check(str, hello, "%");
	}
	else if (k == -4)
		*return_value += ft_k_4_u(hello, format, i);
	else
	{
		str = ft_sputni_check(k + 2, (char *)format + *i);
		*return_value += ft_lets_check(str, hello, NULL);
		*i = *i + k + 1;
	}
}

void	ft_k_4_me(const char *format, int *j, int *return_value)
{
	while (format[*j] != '\0' && format[*j] != '%')
	{
		ft_putchar(format[*j]);
		*j = *j + 1;
		*return_value = *return_value + 1;
	}
}

int		ft_k_4_u(va_list hello, const char *format, int *i)
{
	int		j;
	char	*str;
	char	*temp;
	int		return_value;

	j = *i;
	return_value = 0;
	while (ft_char_comp(format[j]) == 1)
		j++;
	str = ft_sputni_check(j - *i + 1, (char *)format + *i);
	temp = ft_memalloc(2);
	temp[0] = format[j];
	if (format[j] != '\0')
	{
		return_value += ft_lets_check(str, hello, temp);
		j++;
	}
	else
		ft_strdel(&str);
	ft_k_4_me(format, &j, &return_value);
	ft_strdel(&temp);
	*i = j;
	return (return_value);
}
