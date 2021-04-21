/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:41:23 by dholiday          #+#    #+#             */
/*   Updated: 2019/07/31 17:47:53 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_type_s(va_list hello)
{
	char *a;
	char *str;

	str = va_arg(hello, char*);
	if (str == NULL)
	{
		a = ft_memalloc(7);
		a = ft_strcpy(a, "(null)");
	}
	else
		a = ft_strdup(str);
	return (a);
}

char	*ft_wide_s(t_print *info)
{
	char	*join;

	if (info->nullpoint == 0 && info->str[info->len] == 's')
		join = ft_memalloc(1);
	else
		join = ft_join_s_a((*info).afterpoint, (*info).str1);
	join = ft_join_s_b((*info).beforepoint, join);
	ft_strdel(&(*info).str1);
	return (join);
}

char	*ft_join_s_a(int afterpoint, char *str1)
{
	char	*temp;

	if (afterpoint != 0 && afterpoint < (int)ft_strlen(str1))
	{
		temp = (char *)malloc((sizeof(char) * (afterpoint + 1)));
		temp = ft_memset(temp, '\0', afterpoint + 1);
		temp = ft_strncpy(temp, str1, afterpoint);
	}
	else
	{
		temp = ft_strdup(str1);
		return (temp);
	}
	return (temp);
}

char	*ft_join_s_b(int beforepoint, char *join)
{
	char	*temp;
	char	*pemp;
	int		k;

	k = ft_strlen(join);
	if (beforepoint > k)
	{
		temp = ft_memalloc(beforepoint - k + 1);
		temp = ft_memset(temp, ' ', beforepoint - k);
		pemp = ft_strjoin(temp, join);
		ft_strdel(&temp);
		ft_strdel(&join);
		return (pemp);
	}
	return (join);
}
